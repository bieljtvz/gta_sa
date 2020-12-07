extern int outros[99];

typedef int(*oJetPack)();
oJetPack pJetPack;

typedef int(__thiscall *oCreatDeadMoney)(DWORD ecx);
oCreatDeadMoney pCreatDeadMoney;

typedef int(__thiscall* oGiveWearpon)(DWORD ecx, DWORD WearponType, int ammo, bool likeunuses);
oGiveWearpon pGiveWearpon;

typedef int(__thiscall* oChangeModel)(DWORD ecx, int model);
oChangeModel pChangeModel;



void OutrasFunc()
{
	//if (outros[1])
		*(float*)(0xB7CDC8) = 0;

	if (outros[2])
	{
		/*pJetPack = (oJetPack)(JETPACK);
		pJetPack();
		outros[2] = 0;*/
	}

	if(outros[3])
	{
		DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;		
		PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);
		pLocal->especial_flags = 1;
		/*pCreatDeadMoney = (oCreatDeadMoney)(0x4590F0);
		pCreatDeadMoney((DWORD)pLocal);*/
		//pGiveWearpon((DWORD)pLocal, 0x26, 999, 0);
		//pChangeModel((DWORD)pLocal, 4);
	}

}


