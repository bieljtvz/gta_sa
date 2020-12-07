extern int outros[99];
int GetPlayerForOPK()
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

				//if (!pCheckVisibility((DWORD)pLocal, (DWORD)pPlayer, 1))//  Checa visibilidade
				//	continue;

				D3DXVECTOR3 Screen, Screen1, HeadPos, FootPos;

				HeadPos = pPlayer->pObject->Pos;
				FootPos = pPlayer->pObject->Pos;

				HeadPos.z = pPlayer->pObject->Pos.z + 0.7;//ajuste
				FootPos.z = pPlayer->pObject->Pos.z - 0.9;//ajuste

				CalcScreenCoors(&HeadPos, &Screen);
				CalcScreenCoors(&FootPos, &Screen1);

				if (VerificarPontos(HeadPos) && VerificarPontos( FootPos) )
				{
					if (Screen.z > 0)
					{

						//if (aim[4])
						{
							D3DXVECTOR3 EnemyScreen, CenterScreen;
							int x, y;
							ViewPortMira(&x, &y);
							CenterScreen.x = x;
							CenterScreen.y = y;
							CalcScreenCoors(&pPlayer->pObject->Pos, &EnemyScreen);
							if ((30 * 2.8) < Get2dDistance(CenterScreen, EnemyScreen))
								continue;
						}

						//if (ModoAimbot == 0)
						{
							D3DXVECTOR3 NodeTela(0, 0, 0);
							CalcScreenCoors(&pPlayer->pObject->Pos, &NodeTela);

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
#define PI 3.14159265
void CalcAngle(float* EnemyCoords, float* LocalCoords, float* CameraCoords, float angles)
{
	float ResultAngles[3];
	float delta[3] = {(CameraCoords[0] - EnemyCoords[0]), (CameraCoords[1] - EnemyCoords[1]), (CameraCoords[2] - EnemyCoords[2]) };
	float hyp = sqrt(delta[0] * delta[0] + delta[1] * delta[1]);
	ResultAngles[0] = (float)(atanf(delta[1] / delta[0]));
	ResultAngles[1] = (float)(asinf(delta[2] / hyp));
	
	float alpha = asin(delta[0] / hyp);
	float beta = acos(delta[0] / hyp);

	if ((LocalCoords[0] > EnemyCoords[0]) && (LocalCoords[1] < EnemyCoords[1]))
		beta = -beta; //1 part

	if ((LocalCoords[0] > EnemyCoords[0]) && (LocalCoords[1] > EnemyCoords[1]))
		beta = beta; //2 part

	if ((LocalCoords[0] < EnemyCoords[0]) && (LocalCoords[1] > EnemyCoords[1]))
		beta = (alpha + (1.5707)); //3 part

	if ((LocalCoords[0] < EnemyCoords[0]) && (LocalCoords[1] < EnemyCoords[1]))
		beta = (-alpha - (1.5707)); //4 part
	 
	angles = beta;
	//angles[1] = ResultAngles[1];
}

void DoOPK()
{

	DWORD PlayerAddr = *(DWORD*)(STARTPLAYER);

	if (GetAsyncKeyState('E') < 0)
	{

		INT Index = GetPlayerForOPK();

		if (Index < 0)
			return;

		float PlayerPitch = *(float*)(CAMERAX);
		float PlayerYaw = *(float*)(CAMERAY);
		D3DXVECTOR3 CameraPos = *(D3DXVECTOR3*)(CPOS_X);


		DWORD LOOP = Index * SIZEPlAYER;
		DWORD Player = (PlayerAddr + LOOP);
		DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;

		PlayerInfo1* pPlayer = (PlayerInfo1*)(Player);
		PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);

		if (pPlayer && pPlayer->pObject && pPlayer->vida <= 100 && pPlayer->vida > 0 && pPlayer->isplayer == 100.0f && (DWORD)pPlayer != LocalPlayer)
		{			
			
			float beta=0;
			CalcAngle(pPlayer->pObject->Pos, pLocal->pObject->Pos, CameraPos, beta);
			
			*(float*)(CAMERAX) = beta + 0.0389;//for deagle.
			//*(float*)(CAMERAY) = -beta[1] - 0.0389;//for deagle.
		}

	}

}

void DoTelekill()
{

	DWORD PlayerAddr = *(DWORD*)(STARTPLAYER);
	if (outros[3])
	{
		if (GetAsyncKeyState('F') < 0)
		{

			INT Index = GetPlayerForOPK();

			if (Index < 0)
				return;

			float PlayerPitch = *(float*)(CAMERAX);
			float PlayerYaw = *(float*)(CAMERAY);
			D3DXVECTOR3 CameraPos = *(D3DXVECTOR3*)(CPOS_X);

			DWORD LOOP = Index * SIZEPlAYER;
			DWORD Player = (PlayerAddr + LOOP);
			DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;

			PlayerInfo1* pPlayer = (PlayerInfo1*)(Player);
			PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);

			if (pPlayer && pPlayer->pObject && /*pPlayer->Vida <= 100 &&*/ pPlayer->vida > 0 && pPlayer->isplayer == 100.0f && (DWORD)pPlayer != LocalPlayer)
			{

				pLocal->pObject->Pos.x = pPlayer->pObject->Pos.x + 1;
				pLocal->pObject->Pos.y = pPlayer->pObject->Pos.y + 1;
				pLocal->pObject->Pos.z = pPlayer->pObject->Pos.z + 1;


			}

		}
	}

}





#define M_PI 3.14159265358979323846f
void Ghostmode(void)
{
	DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;
	PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);
	D3DXVECTOR3 CameraPos = *(D3DXVECTOR3*)(CPOS_X);

	float PlayerYaw = *(float*)(CAMERAX);
	float PlayerPitch = *(float*)(CAMERAY);

	bool Forward, Backward, Left, Right;
	
	Forward = (GetAsyncKeyState('I') & 0x8000) != 0;
	Backward = (GetAsyncKeyState('K') & 0x8000) != 0;
	Left = (GetAsyncKeyState('J') & 0x8000) != 0;
	Right = (GetAsyncKeyState('L') & 0x8000) != 0;	

	if (Forward || Backward || Left || Right)
	{
		if (Forward || Backward)
		{
			float Sign = (Forward ? 1.0f : -1.0f);
			CameraPos.x += Sign * 5.0f * sinf(PlayerYaw);
			CameraPos.y += Sign * 5.0f * sinf(-PlayerPitch);
			CameraPos.z += Sign * 5.0f * cosf(PlayerYaw);

			pLocal->pObject->Pos.x = CameraPos.x;
			pLocal->pObject->Pos.y = CameraPos.y;
			pLocal->pObject->Pos.z= CameraPos.z;

		}
		if (Left)
		{
			CameraPos.x += 20.0f * sinf(PlayerYaw - (M_PI / 2.0f));
			CameraPos.y += 0;
			CameraPos.z += 20.0f * cosf(PlayerYaw - (M_PI / 2.0f));
			pLocal->pObject->Pos.x = CameraPos.x;
			pLocal->pObject->Pos.y = CameraPos.y;
			pLocal->pObject->Pos.z = CameraPos.z;
		}
		if (Right)
		{
			CameraPos.x += 20.0f * sinf(PlayerYaw + (M_PI / 2.0f));
			CameraPos.y += 0;
			CameraPos.z += 20.0f * cosf(PlayerYaw + (M_PI / 2.0f));
			pLocal->pObject->Pos.x = CameraPos.x;
			pLocal->pObject->Pos.y = CameraPos.y;
			pLocal->pObject->Pos.z = CameraPos.z;
		}
	}
}

