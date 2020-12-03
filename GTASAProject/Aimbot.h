//typedef float(WINAPIV* oDistToLine)(D3DXVECTOR3 linestart, D3DXVECTOR3 lineend, D3DXVECTOR3 point);
//oDistToLine pDistToLine;

typedef bool(WINAPIV* oDistToLine)(D3DXVECTOR3 linestart, D3DXVECTOR3 lineend);
oDistToLine pDistToLine;
extern int aim[99];

#pragma region PegarFov
float EscolherFov()
{
	if (FovAimbot == 0)
	{
		return 5.0f;
	}
	else if (FovAimbot == 1)
	{
		return 20.0f;
	}
	else if (FovAimbot == 2)
	{
		return 45.0f;
	}
	else if (FovAimbot == 3)
	{
		return 180.0f;
	}
}
#pragma endregion 

#pragma region PegarTecla
DWORD EscolherTeclaAimbot()
{
	if (aim[1])
	{
		if (KeyAimbot == 0)
		{
			return  VK_LBUTTON;
		}
		else if (KeyAimbot == 1)
		{
			return  VK_RBUTTON;
		}
		else if (KeyAimbot == 2)
		{
			return 'E';
		}
	}
	else
	{
		return VK_LBUTTON;
	}
}
#pragma endregion


void AimAtPos(float x, float y)
{	
	int ScreenCenterY;
	int ScreenCenterX;
	ViewPortMira(&ScreenCenterX, &ScreenCenterY);	
	

	float TargetX = 0;
	float TargetY = 0;


	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x) / 4;

			if (TargetX + ScreenCenterX > ScreenCenterX * 2 )
				TargetX = 0;
			
			
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;			
			
			/*if (TargetX + ScreenCenterX < 0) 
				TargetX = 0;*/
			
			
		}
	}
	//Y Axis
	if (Trava_Y == 1)
	{
		if (y != 0)//PosY
		{
			if (y > ScreenCenterY)
			{
				TargetY = -(ScreenCenterY - y) / 4;
				if (TargetY + ScreenCenterY > ScreenCenterY * 2)
					TargetY = 0;
			}

			if (y < ScreenCenterY)
			{
				TargetY = y - ScreenCenterY;

				if (TargetY + ScreenCenterY < 0)
					TargetY = 0;
			}
		}
	}



	mouse_event(MOUSEEVENTF_MOVE, TargetX, TargetY, 0, 0);
	return;

}


int GetPlayers()
{
	DWORD PlayerAddr = *(DWORD*)(STARTPLAYER);

	FLOAT Distance = 0.0f, minDistance = (FLOAT)INT_MAX;
	DOUBLE fNearestDistance = (FLOAT)INT_MAX;
	INT index = -1;
	FLOAT fNearest = (FLOAT)INT_MAX;

	for (int i = 0; i < 200; i++)
	{
		DWORD LOOP = i * SIZEPlAYER;
		DWORD Player = (PlayerAddr + LOOP);
		DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;

		PlayerInfo1* pPlayer = (PlayerInfo1*)(Player);
		PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);

		if (pPlayer && pPlayer->pObject && /*pPlayer->Vida <= 100 &&*/ pPlayer->vida > 0 && pPlayer->isplayer == 100.0f && (DWORD)pPlayer != LocalPlayer)
		{		

			if (!pCheckVisibility((DWORD)pLocal, (DWORD)pPlayer, 1))//  Checa visibilidade
				continue;

			D3DXVECTOR3 HeadScreen, HeadPos;	

			HeadPos = pPlayer->pObject->Pos;
			if (pPlayer->player_crouch != 132)
				HeadPos.z = pPlayer->pObject->Pos.z + 0.7;//ajuste				

			CalcScreenCoors(&HeadPos, &HeadScreen);						

			if (VerificarPontos(HeadPos) == 1)
			{
				if (HeadScreen.z > 0)
				{
					
					if (dist_max <= PegarDistancia(pLocal->pObject->Pos, HeadPos))
						continue;

					//if (aim[4])
					{
						D3DXVECTOR3 EnemyScreen, CenterScreen;								
						int x, y;
						ViewPortMira(&x, &y);
						//FillRGB(x, y, 3, 3, White, g_pDevice);
						CenterScreen.x = x;
						CenterScreen.y = y;						
						CalcScreenCoors(&HeadPos, &EnemyScreen);
						if ((45.0f * 2.8) < Get2dDistance(CenterScreen, EnemyScreen))
							continue;
					}

					//if (ModoAimbot == 0)
					{
						D3DXVECTOR3 NodeTela(0, 0, 0);
						CalcScreenCoors(&HeadPos, &NodeTela);

						int x, y;
						ViewPortMira(&x, &y);

						D3DXVECTOR3 Pos;
						Pos.x = NodeTela.x - (x);
						Pos.y = NodeTela.y - (y);
						if (Pos.x < 0)
							Pos.x *= -1;
						if (Pos.y < 0)
							Pos.y *= -1;
						double Dist = (Pos.x + Pos.y);
						if (Dist < fNearest)
						{
							fNearest = Dist;
							index = i;							
						}
					}		
				}
			}
		}
	}
	return index;
}

void do_aimbot()
{
	//if (aim[1])
	{
		DWORD PlayerAddr = *(DWORD*)(STARTPLAYER);

		int ScreenCenterY;
		int ScreenCenterX;
		ViewPortMira(&ScreenCenterX, &ScreenCenterY);

		//if (aim[4])//DesenharFov
		//	DrawCircle(ScreenCenterX, ScreenCenterY, EscolherFov() * 3.0f, 50, Green);
		
		if (GetAsyncKeyState(tecla_aimbot) < 0)
		{			

			INT Index = GetPlayers();

			if (Index < 0)
				return;

			DWORD LOOP = Index * SIZEPlAYER;
			DWORD Player = (PlayerAddr + LOOP);
			DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;

			PlayerInfo1* pPlayer = (PlayerInfo1*)(Player);
			PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);

			if (pPlayer && pPlayer->pObject && /*pPlayer->Vida <= 100 &&*/ pPlayer->vida > 0 && pPlayer->isplayer == 100.0f && (DWORD)pPlayer != LocalPlayer)
			{
				
				D3DXVECTOR3 EnemyScreen,HeadPosBone,HeadScrenn;
				pGetBonePosition((DWORD)pPlayer, HeadPosBone, 5, 0);
				//CalcScreenCoors(&pPlayer->pObject->Pos, &EnemyScreen);
				CalcScreenCoors(&HeadPosBone, &HeadScrenn);		
				

				AimAtPos(HeadScrenn.x, HeadScrenn.y);

				
			}

		}
	}

}

void do_aimbot1()
{
	DWORD* pTarget = (DWORD*)0xB6F3B8;//pointer of target object.
	DWORD* pActor = (DWORD*)0xB6F5F0;//pointer of player actor 
	DWORD* pCamera = (DWORD*)0xB6F99C;//camera pointer
	float* camXpos = (float*)0xB6F258;//writeable camera Z angle 
		if (*pActor > 0)
		{
			char* pVehicle = (char*)((*pActor) + 0x46C);

			if (*pVehicle != 1)
			{
				DWORD* pMtrx1 = (DWORD*)((*pActor) + 0x14);//matrix of player actor 
				float* xPos1 = (float*)((*pMtrx1) + 0x30);//player actor X position 
				float* yPos1 = (float*)((*pMtrx1) + 0x34);//player actor Y position 

				float* CxPos1 = (float*)(0xB6F9CC);//camera X position  
				float* CyPos1 = (float*)(0xB6F9D0);//camera Y position 

				float xPoint = *CxPos1;
				float yPoint = *CyPos1;

				int* keyt = (int*)0xB7347A;//Left mouse key
				DWORD* pPed = (DWORD*)((*pTarget) + 0x79C);//pointer to target player  

				if (*pPed > 0) {

					float* playerSpeedVectorX = (float*)((*pPed) + 0x44);// Player speed angle vector.
					float* playerSpeedVectorY = (float*)((*pPed) + 0x48);

					DWORD* pMtrx2 = (DWORD*)((*pPed) + 0x14);//matrix of target player 
					float* xPos2 = (float*)((*pMtrx2) + 0x30);//X position 
					float* yPos2 = (float*)((*pMtrx2) + 0x34);//Y position

					float xPos2a;
					float yPos2a;

					float* playerHP = (float*)((*pPed) + 0x540);//health of target player
					if (*playerHP > 0) 
					{

						xPos2a = *xPos2 + *playerSpeedVectorX * 6;//position not far from target player sceen
						yPos2a = *yPos2 + *playerSpeedVectorY * 6;

						float Aa = fabs(xPoint - xPos2a);
						float Ab = fabs(yPoint - yPos2a);
						float Ac = sqrt(Aa * Aa + Ab * Ab);
						float alpha = asin(Aa / Ac);
						float beta = acos(Aa / Ac);

						if ((*xPos1 > * xPos2) && (*yPos1 < *yPos2)) 						 
							beta = -beta; //1 part

						if ((*xPos1 > * xPos2) && (*yPos1 > * yPos2))  
							beta = beta; //2 part

						if ((*xPos1 < *xPos2) && (*yPos1 > * yPos2))  
							beta = (alpha + (1.5707)); //3 part

						if ((*xPos1 < *xPos2) && (*yPos1 < *yPos2)) 
							beta = (-alpha - (1.5707)); //4 part

						if (*keyt > 0) {
							*camXpos = beta + 0.0389;//for deagle.
						}
					}
				}
			}
		}		
	
}

void do_aimbot2()
{
	DWORD PlayerAddr = *(DWORD*)(STARTPLAYER);
	if (PlayerAddr)
	{
		if (GetAsyncKeyState(tecla_aimbot) < 0)
		{
			INT Index = GetPlayers();

			if (Index < 0)
				return;

			DWORD LOOP = Index * SIZEPlAYER;
			DWORD Player = (PlayerAddr + LOOP);
			DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;

			PlayerInfo1* pPlayer = (PlayerInfo1*)(Player);
			PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);

			if (pPlayer && pPlayer->pObject && /*pPlayer->Vida <= 100 &&*/ pPlayer->vida > 0 && pPlayer->isplayer == 100.0f && (DWORD)pPlayer != LocalPlayer)
			{

			}
		}
	}

}
