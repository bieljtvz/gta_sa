bool Mask(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	return (*szMask) == NULL;
}

DWORD FindPattern(DWORD dwAddress, DWORD dwLen, BYTE* bMask, char* szMask)
{
	for (DWORD i = 0; i < dwLen; i++)
		if (Mask((BYTE*)(dwAddress + i), bMask, szMask))
			return (DWORD)(dwAddress + i);
	return 0;
}

typedef int(__cdecl* oW2S)(D3DXVECTOR3 *a1, D3DXVECTOR3 *a2);
oW2S pW2S;

typedef int(__thiscall* oGetBonePosition)(DWORD ECX, D3DXVECTOR3& outPosition, unsigned int boneId, bool updateSkinBones);
oGetBonePosition pGetBonePosition;

void CalcScreenCoors(D3DXVECTOR3* vecWorld, D3DXVECTOR3* vecScreen)
{
	/** C++-ifyed function 0x71DA00, formerly called by CHudSA::CalcScreenCoors **/

	// Get the static view matrix as D3DXMATRIX
	D3DXMATRIX m((float*)(0xB6FA2C));

	// Get the static virtual screen (x,y)-sizes
	DWORD* dwLenX = (DWORD*)(0xC17044);
	DWORD* dwLenY = (DWORD*)(0xC17048);

	// Do a transformation
	vecScreen->x = vecWorld->z * m._31 + vecWorld->y * m._21 + vecWorld->x * m._11 + m._41;
	vecScreen->y = vecWorld->z * m._32 + vecWorld->y * m._22 + vecWorld->x * m._12 + m._42;
	vecScreen->z = vecWorld->z * m._33 + vecWorld->y * m._23 + vecWorld->x * m._13 + m._43;

	// Get the correct screen coordinates
	float fRecip = 1.0f / vecScreen->z;
	vecScreen->x *= fRecip * (*dwLenX);
	vecScreen->y *= fRecip * (*dwLenY);
}

int VerificarPontos(D3DXVECTOR3 world)
{
	if (world.x > -3000.0f && world.x < 3000.0f && (world.x + 0x1) > -3000.0f && (world.x + 0x1) < 3000.0f && (world.x + 0x2) > -3000.0f && (world.x + 0x2) < 3000.0f && (int)world.x != 0 && (int)(world.x + 0x1) != 0 && (int)(world.x + 0x2) != 0)
		return 1;
	else
		return 0;;
}

float Get2dDistance(D3DXVECTOR3 Viewangle, D3DXVECTOR3 AimbotAngle)
{
	float X = Viewangle.x - AimbotAngle.x;
	float Y = Viewangle.y - AimbotAngle.y;
	return sqrt(X * X + Y * Y);
}

//1280=37
//1024=100
int calculo_resolucao_x()
{
	int x = *(int*)VIEWPORTX;
	return (x*37)/1280;
}

int calculo_resolucao_y()
{
	int y = *(int*)VIEWPORTY;
	return (y * 100) / 1024;
	
}

void ViewPortMira(int* X,int* Y)
{
	DWORD LocalPlayer = *(DWORD*)LOCALPLAYER;	
	PlayerInfo1* pLocal = (PlayerInfo1*)(LocalPlayer);
	if (pLocal->current_wearpon == 358)
	{
		*X = *(int*)(VIEWPORTX) / 2 ;
		*Y = *(int*)(VIEWPORTY) / 2 ;
	}
	else
	{
		*X = *(int*)(VIEWPORTX) / 2 + calculo_resolucao_x();
		*Y = *(int*)(VIEWPORTY) / 2 - calculo_resolucao_y();
	}
	
}

float PegarDistancia(D3DXVECTOR3 Camera, D3DXVECTOR3 Jogador)
{
	return sqrt(
		(Camera.x - Jogador.x) * (Camera.x - Jogador.x) +
		(Camera.y - Jogador.y) * (Camera.y - Jogador.y) +
		(Camera.z - Jogador.z) * (Camera.z - Jogador.z)
	);
}



