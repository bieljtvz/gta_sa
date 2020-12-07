extern int esp[99];
void DrawESPBox(D3DXVECTOR3 Head, D3DXVECTOR3 Foot, D3DXVECTOR3 EnemyPos, D3DXVECTOR3 MinhaPos, char* text, int Vida, DWORD dwColor, LPDIRECT3DDEVICE9 pDevice)
{

	D3DXVECTOR3 Box = Head - Foot;
	DWORD dwColor1;
	if (Box.y < 0)
		Box.y *= -1;

	int BoxWidth = (int)Box.y / 2;
	int DrawX = (int)Head.x - (BoxWidth / 2);
	int DrawY = (int)Head.y;
	/////////////////////////////////////////////////////////////


	/////////////////////////////////////////////
	DWORD dwDrawWidth = Vida * (Foot.y - Head.y) / 100;
	if (Vida > 100)
		Vida = 100;

	if (Vida > 75)
		dwColor1 = Green;
	else if (Vida > 40)
		dwColor1 = Orange;
	else
		dwColor1 = Red;
	/////////////////////////////////////////////////

	if (esp[0])//Name
	{
		BordedText(Head.x , Head.y - 13, dwColor, Black, text);
	}

	//if (esp[1])//box
	{
		DrawBorder(DrawX + 1, DrawY + 1, BoxWidth, (int)Box.y, 1, 0xFF000000, pDevice);
		DrawBorder(DrawX, DrawY, BoxWidth, (int)Box.y, 1, dwColor, pDevice);
		
	}

	//if (esp[4])//vida
	{
		FillRGB(DrawX - 6, DrawY - 1, 5, (int)Box.y + 2, Black, pDevice);
		FillRGB(DrawX - 5, DrawY, 3, dwDrawWidth, dwColor1, pDevice);
	}

	if (esp[2])//linha
	{
		DrawLine(*(int*)VIEWPORTX / 2 + 0.5, *(int*)VIEWPORTY / 2 + 0.5, DrawX + 0.5, DrawY + 0.5, 1, 0xFF000000);
		DrawLine(*(int*)VIEWPORTX / 2, *(int*)VIEWPORTY / 2, DrawX, DrawY, 1, dwColor);
	}

	if (esp[3])//Distancia
	{
		char Distancia[99];
		sprintf(Distancia, "%0.f", (PegarDistancia(MinhaPos, EnemyPos) ));
		BordedText(Head.x, Foot.y + 3,  dwColor, D3DCOLOR_XRGB(0, 0, 0), Distancia);
	}
}

typedef bool(__thiscall* oIsPedShootable)(DWORD ecx);
oIsPedShootable pIsPedShootable;

typedef int(__thiscall* oPedState)(DWORD ecx, int state);
oPedState pPedState;

typedef int(__thiscall* oCheckVisibility)(DWORD ecx, DWORD Ped, bool IsSpoted);
oCheckVisibility pCheckVisibility;

void desenhar_esp()
{
	DWORD PlayerAddr = *(DWORD*)(STARTPLAYER);
	
	for (int i = 0; i < 200; i++)	{		
		
		DWORD Color = Yellow;
		DWORD LOOP = i * SIZEPlAYER;
		DWORD Player = (PlayerAddr + LOOP);
		DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;

		PlayerInfo1* pPlayer = (PlayerInfo1*)(Player);
		PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);

		if (pPlayer && pPlayer->pObject && /*pPlayer->Vida <= 100 &&*/ pPlayer->vida > 0 && pPlayer->isplayer == 100.0f && (DWORD)pPlayer != LocalPlayer)
		{		
			//if (!pIsPedShootable((DWORD)pPlayer)) // Verifica os jogadores em veiculos
			//	continue;

		/*	if (pLocal->vida > 0)
			{
				if (!pCheckVisibility((DWORD)pLocal, (DWORD)pPlayer, 1))
					Color = Red;
			}*/

			D3DXVECTOR3 Screen, Screen1,HeadPos,FootPos;

			HeadPos = pPlayer->pObject->Pos;
			FootPos = pPlayer->pObject->Pos;

			HeadPos.z = pPlayer->pObject->Pos.z + 0.7;//ajuste
			FootPos.z = pPlayer->pObject->Pos.z - 0.9;//ajuste

			D3DXVECTOR3 HeadPosBone,HeadPosBoneScreen;		

			//CalcScreenCoors(&HeadPosBone, &HeadPosBoneScreen);
			CalcScreenCoors(&HeadPos, &Screen);
			CalcScreenCoors(&FootPos, &Screen1);

			if (Screen.z < 1.f || Screen1.z < 1.f /*|| HeadPosBoneScreen.z < 1.0f*/)
				continue;		

			if (VerificarPontos(HeadPos) == 1 && VerificarPontos( FootPos) == 1 )
			{
				if (Screen.z > 0)
				{
					
					/*float Distancia = PegarDistancia(pLocal->pObject->Pos, pPlayer->pObject->Pos);
					if (Distancia < 71.0f)
					{
						float PlayerPitch = *(float*)(CAMERAX);
						float PlayerYaw = *(float*)(CAMERAY);
						D3DXVECTOR3 CameraPos = *(D3DXVECTOR3*)(CPOS_X);

						float angles=0;
						CalcAngle(pPlayer->pObject->Pos,pLocal->pObject->Pos,CameraPos, angles);

						float ang = ((angles) - PlayerYaw + 3);

						float dx = (*(int*)(VIEWPORTX) / 2) - 1 - cos(ang) * Distancia;
						float dy = (*(int*)(VIEWPORTY) / 2) - 1 - sin(ang) * Distancia;

						DrawBox((int)dx, (int)dy, 2, 2, Red, 1, g_pDevice);
					}*/


					DrawESPBox(Screen, Screen1, HeadPos, pLocal->pObject->Pos ,(char*)"NPC", (int)pPlayer->vida, Color, g_pDevice);
				}
			}
		}
	}
}
