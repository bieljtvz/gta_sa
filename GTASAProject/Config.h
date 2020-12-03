//ViewPort
int VP_X;
int VP_Y;
//Aimbot
int Trava_Y = 1;
DWORD tecla_aimbot = 'E';
float dist_max = 500;

void carrega_config()
{
	//ViewPort
	//TCHAR BufferGetVPX[32];
	//TCHAR BufferGetVPY[32];	
	//GetPrivateProfileStringA("ViewPort", "VPX", NULL, (LPSTR)BufferGetVPX, 32, "C://config_gta.ini");
	//GetPrivateProfileStringA("ViewPort", "VPY", NULL, (LPSTR)BufferGetVPY, 32, "C://config_gta.ini");	
	//VP_X = atoi((char*)BufferGetVPX);
	//VP_Y = atoi((char*)BufferGetVPY);

	//Aimbot
	TCHAR BufferGet_TravarY[32];
	TCHAR BufferGet_TeclaAimbot[32];
	TCHAR BufferGet_Distancia[32];
	GetPrivateProfileStringA("Aimbot", "trava_y", NULL, (LPSTR)BufferGet_TravarY, 32, "C://config_gta.ini");
	GetPrivateProfileStringA("Aimbot", "tecla_aimbot", NULL, (LPSTR)BufferGet_TeclaAimbot, 32, "C://config_gta.ini");
	GetPrivateProfileStringA("Aimbot", "distancia_maxima", NULL, (LPSTR)BufferGet_Distancia, 32, "C://config_gta.ini");
	Trava_Y = atoi((char*)BufferGet_TravarY);
	tecla_aimbot = strtoul((char*)BufferGet_TeclaAimbot, NULL, 16);
	dist_max = atof((char*)BufferGet_Distancia);

	//printf("Tecla : %X",tecla_aimbot);
}

void salvar_viewport()
{
	char VPX[99];
	char VPY[99];
	sprintf(VPX,"%i", VP_X);
	sprintf(VPY, "%i", VP_Y);

	printf("VP_X: %s", VP_X);
	printf("VP_Y: %s", VP_Y);
	WritePrivateProfileStringA("ViewPort", "VPX", VPX, "C://config_gta.ini");
	WritePrivateProfileStringA("ViewPort", "VPY", VPY, "C://config_gta.ini");
}

int Vy = VP_X, Vx = VP_Y;
void config_viewport()
{
	
	if (GetAsyncKeyState(VK_UP) & 1)
	{
		Vy = Vy + 1;
	}
	if (GetAsyncKeyState(VK_DOWN) & 1)
	{
		Vy = Vy - 1;
	}
	if (GetAsyncKeyState(VK_LEFT) & 1)
	{
		Vx = Vx - 1;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 1)
	{
		Vx = Vx + 1;
	}

	int X = *(int*)(VIEWPORTX) / 2 + Vx;
	int Y = *(int*)(VIEWPORTY) / 2 - Vy;

	VP_X = X;
	VP_Y = Y;

	FillRGB(X, Y, 3, 3, White, g_pDevice);

	if (GetAsyncKeyState(VK_F7) & 1)
		salvar_viewport();

}


