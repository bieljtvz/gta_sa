#define  _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h> 
#include <intrin.h>
#include <process.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <tchar.h>



#include "PEB.h"
#include "detours.h"
#include "Menu.h"
#include "Endereços.h"
#include "Config.h"
#include "Classes.h"
#include "Engine.h"
#include "Telekill.h"
#include "ESP.h"
#include "Aimbot.h"
#include "Hooks_Functions.h"

#include "Outros.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib") 

typedef int(WINAPIV* oCreateCar)(int x);
oCreateCar pCreateCar;

typedef int(*oShutdownPed)();
oShutdownPed pShutdownPed;

typedef signed int(__thiscall* oPrimeira)(DWORD ecx);
oPrimeira pPrimeira;

typedef HRESULT(WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;

typedef HRESULT(WINAPI* oPresent)(LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
oPresent pPresent;

int esp[99],aim[99],outros[99],aimopk[99],tabspos[99];

bool DesenharMenu = 0;
INT  MenuSelection = 1;
INT  Current = true;
bool v_viewport = 0;

HRESULT WINAPI hkPresent(LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
	__asm PUSHAD;
	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);

	if(g_pDevice != pDevice)
	{
		g_pDevice = pDevice;
		pGetBonePosition = (oGetBonePosition)(GETBONEPOS);
		pCheckVisibility = oCheckVisibility(CHECK_VISIBILITY); //Checa a visibilidade
		//pIsPedShootable = (oIsPedShootable)(IS_PLAYER_SHOOTABLE); // Verifica jogadores em veiculos
		//pPedState = (oPedState)(0x5E4500);
		//pGiveWearpon = oGiveWearpon(0x5E6080);
		//pChangeModel = oChangeModel(0x5E4880);
		


		//carrega_config();
		try
		{
			//if (Font != 0 || pLine != 0 /*|| MenuTexture != 0 || Sprite != 0*/)
			{
				/*Font->Release();
				pLine->Release();*/
				/*
				MenuTexture->Release();
				Sprite->Release();*/
			}
		}
		catch (...)
		{
		}

		//Font = 0;
		//pLine = 0;
		/*
		MenuTexture = 0;
		Sprite = 0;*/
		/*D3DXCreateFontA(pDevice, 13, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Lucida Console", &Font);
		D3DXCreateLine(pDevice, &pLine);*/

		/*D3DXCreateTextureFromFileInMemory(pDevice, &Menupic, sizeof(Menupic), &MenuTexture);
		D3DXCreateSprite(pDevice, &Sprite);*/
	}
	
#pragma region Menu
	//BordedText(5, 5, Red, Black, (char*)"Hooked by bieljtvz");	

	//if (GetAsyncKeyState(VK_INSERT) & 1)
	//{
	//	DesenharMenu = !DesenharMenu;	
	//	
	//	

	//}

	//if (DesenharMenu && Font )
	//{
	//

	//		

	//		GradientBox(PosX - 10, PosY - 22, 180, 20, TBlack, White,true, pDevice);//Draw box do Titulo.
	//		BordedText(PosX + 38, PosY - 20, Yellow, Black, (CHAR*)"GTA_SA(bieljtvz)");//Titulo
	//		GradientBox(PosX - 10, PosY, 180, (Current * 15), TBlack, White,true, pDevice);//DrawBox
	//		DrawBorder(PosX - 10, Posy + 2 + (MenuSelection * 15), 180, 13, 1, White, pDevice);//Seleção
	//		Current = 1;

	//		if (GetAsyncKeyState(VK_UP) & 1)
	//			MenuSelection--;

	//		if (GetAsyncKeyState(VK_DOWN) & 1)
	//			MenuSelection++;

	//		//Itens Do Menu
	//		Additem((CHAR*)"[+]ESP", 1, tabspos[0], 0, Opt_Menu, pDevice);
	//		if (tabspos[0]) {
	//			Additem((CHAR*)"   Caixa", 1, esp[1], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   Linha", 1, esp[2], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   Distancia", 1, esp[3], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   Saude", 1, esp[4], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   nmae", 1, esp[0], 0, Opt_Opções, pDevice);
	//		}
	//		Additem((CHAR*)"[+]Aimbot Normal", 1, tabspos[1], 0, Opt_Menu, pDevice);
	//		if (tabspos[1]) 
	//		{
	//			Additem((CHAR*)"   Ativar", 1, aim[1], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   Tecla", 2, KeyAimbot, 0, Opt_KeyAimbot, pDevice);
	//			Additem((CHAR*)"   Fov", 3, FovAimbot, 0, Opt_KeyFovAimbot, pDevice);
	//			Additem((CHAR*)"   Desenhar Fov", 1, aim[4], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   TravarY", 1, aim[5], 0, Opt_Opções, pDevice);
	//		}
	//		Additem((CHAR*)"[+]Aimbot OPK", 1, tabspos[2], 0, Opt_Menu, pDevice);
	//		if (tabspos[2]) 
	//		{
	//			Additem((CHAR*)"   Ativar", 1, aimopk[1], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   Tecla", 2, aimopk[2], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   Fov", 3, aimopk[3], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   Desenhar Fov", 1, aimopk[4], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   TravarY", 1, aimopk[5], 0, Opt_Opções, pDevice);
	//		}
	//		Additem((CHAR*)"[+]Outros", 1, tabspos[3], 0, Opt_Menu, pDevice);
	//		if (tabspos[3])
	//		{
	//			Additem((CHAR*)"   Sem Recuo", 1, outros[1], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   JetPack", 1, outros[2], 0, Opt_Opções, pDevice);
	//			Additem((CHAR*)"   Telekill(F)", 1, outros[3], 0, Opt_Opções, pDevice);
	//			
	//		}
	//	

	//}

	//if (MenuSelection >= Current)
	//	MenuSelection = 1;

	//if (MenuSelection < 1)
	//	MenuSelection = Current - 1;


#pragma endregion 


	/*if (GetAsyncKeyState(VK_UP) & 1) bone = bone++;
	if (GetAsyncKeyState(VK_DOWN) & 1) bone = bone--;

	char pp[99];
	sprintf(pp, "%i", bone);
	BordedText(40, 40, Red, Black, pp);*/

	/*if (GetAsyncKeyState(VK_F8) & 1)
		v_viewport = !v_viewport;*/

	if (GetAsyncKeyState(VK_F6) & 1)
		outros[3] = !outros[3];
		
	/*if (v_viewport)
		config_viewport();*/ 

	//desenhar_esp();
	//DoOPK();
	//do_aimbot();
	//OutrasFunc();
	//DoTelekill();
	//DoOPK();
	//Ghostmode();
	//0xB7CDC8 no recoil


	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);

	__asm POPAD;
	return pPresent(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}


unsigned __stdcall HookThread(LPVOID param)
{
	
	/*DWORD Device = (DWORD)LoadLibraryA("d3d9.dll");
	DWORD* vTable;
	DWORD Endereço = FindPattern(Device, 0x128000, (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", (char*)"xx????xx????xx");
	Sleep(9000);

	pW2S = (oW2S)(W2S);
	if (Endereço)*/
	{
		DWORD* Device1 = **(DWORD***)0xC97C28;
		pPresent = (oPresent)DetourFunction((PBYTE)Device1[17], (PBYTE)&hkPresent);		
	}
	Hooks_Init();
	/*DWORD AddressSetCursorPos = (DWORD)GetProcAddress(GetModuleHandleA("User32.dll"), "SetCursorPos");
	oSetCursorPos = (pSetCursorPos)DetourFunction((PBYTE)AddressSetCursorPos, (PBYTE)hkSetCursorPos);*/



	ExitThread(0);
	return FALSE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		AllocConsole(); 
		freopen("CONOUT$", "w", stdout); //console para teste
			
		DisableThreadLibraryCalls(hModule);		
		ErasePEHeader(hModule);
		EraseHeaders(hModule);
		UnlinkModuleFromPEB(hModule);
		HideModule(hModule);	
		_beginthreadex(0, 0, HookThread, 0, 0, 0);
		
	}
	return TRUE;
}