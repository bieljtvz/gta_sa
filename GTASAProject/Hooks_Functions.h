typedef BOOL(WINAPIV* pGenerateDamageEvent)(DWORD victim, DWORD creator, DWORD weaponType, int damageFactor, DWORD pedPiece, int direction);
pGenerateDamageEvent oGenerateDamageEvent;

typedef BOOL(WINAPI* pSetCursorPos)(int X, int Y);
pSetCursorPos oSetCursorPos;

bool WINAPIV hkGenerateDamageEvent(DWORD victim, DWORD creator, DWORD weaponType, int damageFactor, DWORD pedPiece, int direction)
{
	printf("victim = %X!\n", victim);
	printf("creator = %X!\n", creator);
	printf("weaponType = %X!\n", weaponType);
	printf("damageFactor = %X!\n", damageFactor);
	printf("pedPiece = %X!\n", pedPiece);
	printf("direction = %i!\n", direction);
	printf("_________________________________\n");
	pedPiece = 0x9;//0x9 = CABEÇA
	direction = 0;
	return oGenerateDamageEvent(victim, creator, weaponType, damageFactor, pedPiece, direction);
}

BOOL WINAPI hkSetCursorPos(int X, int Y)
{

	POINT MousePosition;
	GetCursorPos(&MousePosition);
	return oSetCursorPos(MousePosition.x, MousePosition.y);
	//return oSetCursorPos(X, Y);
}


void Hooks_Init()
{
	//Address
	//
	DWORD GenerateDamageEvent_Addr = 0x73A530;


	//Hooks
	//
	oGenerateDamageEvent = (pGenerateDamageEvent)DetourFunction((PBYTE)GenerateDamageEvent_Addr, (PBYTE)hkGenerateDamageEvent);


}