#pragma region Cores
#define Green				D3DCOLOR_ARGB(255, 000, 255, 000)
#define Red					D3DCOLOR_ARGB(255, 255, 000, 000)
#define Blue				D3DCOLOR_ARGB(255, 000, 000, 255)
#define Orange				D3DCOLOR_ARGB(255, 255, 165, 000)
#define Yellow				D3DCOLOR_ARGB(255, 255, 255, 000)
#define Pink				D3DCOLOR_ARGB(255, 255, 192, 203)
#define Cyan				D3DCOLOR_ARGB(255, 000, 255, 255)
#define Purple				D3DCOLOR_ARGB(255, 160, 032, 240)
#define Black				D3DCOLOR_ARGB(255, 000, 000, 000) 
#define White				D3DCOLOR_ARGB(255, 255, 255, 255)
#define Grey				D3DCOLOR_ARGB(255, 112, 112, 112)
#define SteelBlue			D3DCOLOR_ARGB(255, 033, 104, 140)
#define LightSteelBlue		D3DCOLOR_ARGB(255, 201, 255, 255)
#define LightBlue			D3DCOLOR_ARGB(255, 026, 140, 306)
#define Salmon				D3DCOLOR_ARGB(255, 196, 112, 112)
#define Brown				D3DCOLOR_ARGB(255, 168, 099, 020)
#define Teal				D3DCOLOR_ARGB(255, 038, 140, 140)
#define Lime				D3DCOLOR_ARGB(255, 050, 205, 050)
#define ElectricLime		D3DCOLOR_ARGB(255, 204, 255, 000)
#define Gold				D3DCOLOR_ARGB(255, 255, 215, 000)
#define OrangeRed			D3DCOLOR_ARGB(255, 255, 069, 000)
#define GreenYellow			D3DCOLOR_ARGB(255, 173, 255, 047)
#define AquaMarine			D3DCOLOR_ARGB(255, 127, 255, 212)
#define SkyBlue				D3DCOLOR_ARGB(255, 000, 191, 255)
#define SlateBlue			D3DCOLOR_ARGB(255, 132, 112, 255)
#define Crimson				D3DCOLOR_ARGB(255, 220, 020, 060)
#define DarkOliveGreen		D3DCOLOR_ARGB(255, 188, 238, 104)
#define PaleGreen			D3DCOLOR_ARGB(255, 154, 255, 154)
#define DarkGoldenRod		D3DCOLOR_ARGB(255, 255, 185, 015)
#define FireBrick			D3DCOLOR_ARGB(255, 255, 048, 048)
#define DarkBlue			D3DCOLOR_ARGB(255, 000, 000, 204)
#define DarkerBlue			D3DCOLOR_ARGB(255, 000, 000, 153)
#define DarkYellow			D3DCOLOR_ARGB(255, 255, 204, 000)
#define LightYellow			D3DCOLOR_ARGB(255, 255, 255, 153)
#define DarkOutline			D3DCOLOR_ARGB(255, 37,   48,  52)

#define TGreen				D3DCOLOR_ARGB(180, 000, 255, 000)
#define TRed				D3DCOLOR_ARGB(180, 255, 000, 000)
#define TBlue				D3DCOLOR_ARGB(180, 000, 000, 255)
#define TOrange				D3DCOLOR_ARGB(180, 255, 165, 000)
#define TYellow				D3DCOLOR_ARGB(180, 255, 255, 000)
#define TPink				D3DCOLOR_ARGB(180, 255, 192, 203)
#define TCyan				D3DCOLOR_ARGB(180, 000, 255, 255)
#define TPurple				D3DCOLOR_ARGB(180, 160, 032, 240)
#define TBlack				D3DCOLOR_ARGB(180, 000, 000, 000) 
#define TWhite				D3DCOLOR_ARGB(180, 255, 255, 255)
#define TGrey				D3DCOLOR_ARGB(180, 112, 112, 112)
#define TSteelBlue			D3DCOLOR_ARGB(180, 033, 104, 140)
#define TLightSteelBlue		D3DCOLOR_ARGB(180, 201, 255, 255)
#define TLightBlue			D3DCOLOR_ARGB(180, 026, 140, 306)
#define TSalmon				D3DCOLOR_ARGB(180, 196, 112, 112)
#define TBrown				D3DCOLOR_ARGB(180, 168, 099, 020)
#define TTeal				D3DCOLOR_ARGB(180, 038, 140, 140)
#define TLime				D3DCOLOR_ARGB(180, 050, 205, 050)
#define TElectricLime		D3DCOLOR_ARGB(180, 204, 255, 000)
#define TGold				D3DCOLOR_ARGB(180, 255, 215, 000)
#define TOrangeRed			D3DCOLOR_ARGB(180, 255, 069, 000)
#define TGreenYellow		D3DCOLOR_ARGB(180, 173, 255, 047)
#define TAquaMarine			D3DCOLOR_ARGB(180, 127, 255, 212)
#define TSkyBlue			D3DCOLOR_ARGB(180, 000, 191, 255)
#define TSlateBlue			D3DCOLOR_ARGB(180, 132, 112, 255)
#define TCrimson			D3DCOLOR_ARGB(180, 220, 020, 060)
#define TDarkOliveGreen		D3DCOLOR_ARGB(180, 188, 238, 104)
#define TPaleGreen			D3DCOLOR_ARGB(180, 154, 255, 154)
#define TDarkGoldenRod		D3DCOLOR_ARGB(180, 255, 185, 015)
#define TFireBrick			D3DCOLOR_ARGB(180, 255, 048, 048)
#define TDarkBlue			D3DCOLOR_ARGB(180, 000, 000, 204)
#define TDarkerBlue			D3DCOLOR_ARGB(180, 000, 000, 153)
#define TDarkYellow			D3DCOLOR_ARGB(180, 255, 204, 000)
#define TLightYellow		D3DCOLOR_ARGB(180, 255, 255, 153)
#define TDarkOutline		D3DCOLOR_ARGB(180, 37,   48,  52)
#pragma endregion 

typedef char(WINAPIV* oDrawTextEngine)(int x, int y, const char* text);
oDrawTextEngine pDrawTextEngine;

LPDIRECT3DDEVICE9 g_pDevice;
LPD3DXSPRITE Sprite;
LPDIRECT3DTEXTURE9 MenuTexture;
LPD3DXFONT Font;
LPD3DXLINE pLine;
#pragma warning(disable: 4244 4996 4715 4800 4482 4011)
#define D3DFVF_TEXTUREVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
INT PosX = 30;
INT PosY = 70;
INT Posy = 60;
struct TEXTUREVERTEX
{
	D3DXVECTOR3 vec;
	FLOAT rhw;
	DWORD color;
	FLOAT u, v;
};

void FillRGB(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice)
{
	D3DRECT rec = { x, y, x + w, y + h };
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
}

VOID DrawLine(LONG Xa, LONG Ya, LONG Xb, LONG Yb, DWORD dwWidth, D3DCOLOR Color)
{
	D3DXVECTOR2 vLine[2];
	pLine->SetAntialias(0);

	pLine->SetWidth(dwWidth);
	pLine->Begin();

	vLine[0][0] = Xa;
	vLine[0][1] = Ya;
	vLine[1][0] = Xb;
	vLine[1][1] = Yb;

	pLine->Draw(vLine, 2, Color);
	pLine->End();
}

void DrawBorder(int x, int y, int w, int h, int px, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
{
	FillRGB(x, (y + h - px), w, px, BorderColor, pDevice);
	FillRGB(x, y, px, h, BorderColor, pDevice);
	FillRGB(x, y, w, px, BorderColor, pDevice);
	FillRGB(x + w - px, y, px, h, BorderColor, pDevice);
}

void Text(int x, int y, D3DCOLOR fontColor, char* text, ...)
{
	RECT rct;
	rct.left = x - 1;
	rct.right = x + 1;
	rct.top = y - 1;
	rct.bottom = y + 1;

	if (!text) { return; }
	va_list va_alist;
	char logbuf[256] = { 0 };
	va_start(va_alist, text);
	_vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
	va_end(va_alist);
	RECT FontRect = { x, y, x, y };
	Font->DrawTextA(NULL, logbuf, -1, &rct, DT_NOCLIP, fontColor);
}

void BordedText(int x, int y, D3DCOLOR fontColor, D3DCOLOR borderc, char* text, ...)
{
	Text(x + 1, y, borderc, text);
	Text(x, y + 1, borderc, text);
	Text(x, y, fontColor, text);
}

VOID TextComFlag(INT x, INT y, DWORD Flags, DWORD Color, CHAR* text, ...)
{
	RECT rec;
	SetRect(&rec, x, y, x, y);
	CHAR logbuf[512] = { 0 };

	va_list va_alist;
	va_start(va_alist, text);
	vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);

	va_end(va_alist);
	Font->DrawTextA(NULL, logbuf, -1, &rec, Flags, Color);
}

void BordedTextComFlag(int x, int y, DWORD Flags, D3DCOLOR fontColor, D3DCOLOR borderc, char* text, ...)
{
	TextComFlag(x + 1, y, Flags, borderc, text);
	TextComFlag(x, y + 1, Flags, borderc, text);
	TextComFlag(x, y, Flags, fontColor, text);
}

VOID CriarVertex(TEXTUREVERTEX* pVertices, FLOAT x, FLOAT y, FLOAT u, FLOAT v, DWORD dwCor)
{
	pVertices->vec = D3DXVECTOR3(x - 0.5f, y - 0.5f, 0);
	pVertices->rhw = 1.0f;
	pVertices->u = u;
	pVertices->v = v;
	pVertices->color = dwCor;
}

VOID DrawBox(int x, int y, int w, int h, DWORD ColorStart, int UsarVertex1, LPDIRECT3DDEVICE9 pDevice)
{
	RECT rect = { x, y, x + w, y + h };;

	FLOAT Esquerda = (FLOAT)rect.left;
	FLOAT Cima = (FLOAT)rect.top;
	FLOAT Direita = (FLOAT)rect.right;
	FLOAT Baixo = (FLOAT)rect.bottom;

	TEXTUREVERTEX vertex[4];
	TEXTUREVERTEX* pVertices = vertex;

	CriarVertex(pVertices, Esquerda, Cima, rect.left, rect.left, ColorStart);
	pVertices++;
	CriarVertex(pVertices, Direita, Cima, rect.right, rect.right, ColorStart);
	pVertices++;
	CriarVertex(pVertices, Esquerda, Baixo, rect.bottom, rect.bottom, ColorStart);
	pVertices++;
	CriarVertex(pVertices, Direita, Baixo, rect.top + rect.right, rect.top + rect.right, ColorStart);
	pVertices++;

	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, 1);
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, 1);
	pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_ANISOTROPIC);//qualidade
	pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_ANISOTROPIC);//qualidade	

	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

	pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_TFACTOR);

	pDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	pDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	pDevice->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(1, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(1, D3DTSS_ALPHAARG2, D3DTA_CURRENT);


	pDevice->SetVertexShader(NULL);
	pDevice->SetTexture(0, NULL);
	pDevice->SetTexture(1, NULL);
	pDevice->SetFVF(D3DFVF_TEXTUREVERTEX);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(TEXTUREVERTEX));
	pDevice->SetTexture(0, NULL);
	pDevice->SetTexture(1, NULL);
}

struct Vertex
{
	FLOAT x, y, z, w;
	DWORD Color;
};

void GradientBox(int x, int y, int width, int height, D3DCOLOR colour, D3DCOLOR color2, bool vertical, IDirect3DDevice9* pDevice)
{
	Vertex pVertex[4] = { { x, y, 0.0f, 1.0f, colour }, { x + width, y, 0.0f, 1.0f, vertical ? colour : color2 }, { x, y + height, 0.0f, 1.0f, vertical ? color2 : colour }, { x + width, y + height, 0.0f, 1.0f, color2 } };
	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, pVertex, sizeof(Vertex));
}

void DrawCircle(int X, int Y, float radius, int numSides, DWORD Color)
{
	D3DXVECTOR2 Line[128];
	float Step = 3.14 * 2.0 / numSides;
	int Count = 0;
	for (float a = 0; a < 3.14 * 2.0; a += Step)
	{
		float X1 = radius * cos(a) + X;
		float Y1 = radius * sin(a) + Y;
		float X2 = radius * cos(a + Step) + X;
		float Y2 = radius * sin(a + Step) + Y;
		Line[Count].x = X1;
		Line[Count].y = Y1;
		Line[Count + 1].x = X2;
		Line[Count + 1].y = Y2;
		Count += 2;
	}
	pLine->Begin();
	pLine->Draw(Line, Count, Color);
	pLine->End();
}

int CalcTSize(char* text)
{
	RECT Rect = { NULL, NULL, NULL, NULL };
	Font->DrawTextA(NULL, text, -1, &Rect, DT_CALCRECT, NULL);
	return Rect.right;
}

bool IsInBox(int x, int y, int w, int h)
{
	POINT MousePosition;
	GetCursorPos(&MousePosition);
	ScreenToClient(GetForegroundWindow(), &MousePosition);
	return (MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}

int tabs[5];

void InitVar()
{
	tabs[0] = 1;
}

int Tab(int x, int y, int& vtab, char* text, IDirect3DDevice9* pDevice)
{
	if (IsInBox(x, y, 75, 20) && GetAsyncKeyState(VK_LBUTTON) & 1)
	{
		for (int i = 0; i < 5; i++)
			tabs[i] = 0;
		vtab = !vtab;
	}

	if (vtab)
	{
		GradientBox(x, y - 4, 75, 24, D3DCOLOR_XRGB(65, 68, 65), D3DCOLOR_XRGB(255, 255, 255), true,pDevice);
		BordedText(x + 78 / 2 - CalcTSize(text) / 2, y + 2, D3DCOLOR_XRGB(255, 255, 255), D3DCOLOR_XRGB(0, 0, 0), text);
		FillRGB(x + 1, y + 18, 73, 2, D3DCOLOR_XRGB(65, 68, 65), pDevice);
	}
	else
	{
		GradientBox(x, y, 75, 20, D3DCOLOR_XRGB(24, 24, 24), D3DCOLOR_XRGB(255, 255, 255),true, pDevice);
		BordedText(x + 78 / 2 - CalcTSize(text) / 2, y + 4, D3DCOLOR_XRGB(172, 170, 172), D3DCOLOR_XRGB(0, 0, 0), text);
	}

	return x + 77;
}

VOID DrawCheck(DWORD Color, INT X, INT Y, IDirect3DDevice9* pDevice)
{
	FillRGB(X, Y, 1, 3, Color, pDevice);
	FillRGB(X + 1, Y + 1, 1, 3, Color, pDevice);
	FillRGB(X + 2, Y + 2, 1, 3, Color, pDevice);
	FillRGB(X + 3, Y + 1, 1, 3, Color, pDevice);
	FillRGB(X + 4, Y, 1, 3, Color, pDevice);
	FillRGB(X + 5, Y - 1, 1, 3, Color, pDevice);
	FillRGB(X + 6, Y - 2, 1, 3, Color, pDevice);
	FillRGB(X + 7, Y - 3, 1, 3, Color, pDevice);
}

void CheckBox(int x, int y, int& var, char* text, IDirect3DDevice9* pDevice)
{
	D3DCOLOR Color;

	if (IsInBox(x, y, 10, 10) && GetAsyncKeyState(VK_LBUTTON) & 1)
	{
		var = !var;
	}

	GradientBox(x, y, 10, 10, D3DCOLOR_XRGB(32, 32, 32), D3DCOLOR_XRGB(32, 32, 32), true,pDevice);
	DrawBorder(x, y, 10, 10, 1, White, pDevice);

	if (var) {
		Color = D3DCOLOR_XRGB(255, 255, 255);
		DrawCheck(D3DCOLOR_XRGB(255, 255, 255), x + 1, y + 4, pDevice);
	}
	else {
		Color = D3DCOLOR_XRGB(213, 213, 213);
	}
	BordedText(x + 15, y - 1, Color, D3DCOLOR_XRGB(0, 0, 0), text);
}

//void CheckBone(int x, int y, int& var, IDirect3DDevice9* pDevice)
//{
//	D3DCOLOR Color;
//
//	if (IsInBox(x, y, 10, 10) && GetAsyncKeyState(VK_LBUTTON) & 1)
//	{
//		var = !var;
//
//		int numero = 0;
//
//		for (int i = 1; i < 14; i++)
//			if (bone[i])
//				numero++;
//
//		if (numero < 1)
//			var = true;
//	}
//
//
//
//	DrawBox(x, y, 10, 10, D3DCOLOR_XRGB(32, 32, 32), D3DCOLOR_XRGB(32, 32, 32), pDevice);
//	DrawBorder(x, y, 10, 10, 1, White, pDevice);
//
//	if (var)
//	{
//		Color = D3DCOLOR_XRGB(255, 255, 255);
//		DrawBox(x, y, 8, 8, Green, D3DCOLOR_XRGB(32, 32, 32), pDevice);
//	}
//	else
//	{
//		Color = D3DCOLOR_XRGB(213, 213, 213);
//	}
//
//}

VOID GroupBox(INT X, INT Y, INT W, INT H, DWORD Color, CHAR* Text, LPDIRECT3DDEVICE9 pDevice)
{
	INT Soma = 10;

	FillRGB(X, Y, Soma, 1, Color, pDevice);
	FillRGB(X + Soma + CalcTSize(Text) + 8, Y, W - CalcTSize(Text) - Soma, 1, Color, pDevice);
	FillRGB(X, Y, 1, H, Color, pDevice);

	FillRGB(X, Y + H, W + 9, 1, Color, pDevice);
	FillRGB(X + Soma + CalcTSize(Text) + 8 + W - CalcTSize(Text) - Soma, Y, 1, H, Color, pDevice);

	BordedText(X + Soma + 5, Y - 6, Color, D3DCOLOR_XRGB(0, 0, 0), Text);
}

//VOID DrawArrows(INT x, INT y, int d, int max, CHAR** text, int& var, LPDIRECT3DDEVICE9 pDevice)
//{
//	DrawBox(x, y + 3, 12, 12, TBlack, White, pDevice);//X
//	BordedTextComFlag(x + 6, y + 2, TCenter, White, D3DCOLOR_XRGB(0, 0, 0), (char*)"<");
//
//	DrawBox(x + d, y + 3, 12, 12, TBlack, White, pDevice);
//	BordedTextComFlag(x + d + 6, y + 2, TCenter, White, D3DCOLOR_XRGB(0, 0, 0), (char*)">");
//
//	BordedTextComFlag(x + (d / 2) + 6, y + 2, TCenter, White, D3DCOLOR_XRGB(0, 0, 0), text[var]);
//
//	if (IsInBox(x, y + 3, 12, 12))
//	{
//		DrawBox(x, y + 3, 12, 12, D3DCOLOR_XRGB(32, 32, 32), Green, pDevice);
//		BordedTextComFlag(x + 6, y + 2, TCenter, Green, D3DCOLOR_XRGB(0, 0, 0), (char*)"<");
//
//		if (GetAsyncKeyState(VK_LBUTTON) & 1)
//		{
//			DrawBox(x, y + 3, 12, 12, Green, Green, pDevice);
//			BordedTextComFlag(x + 6, y + 2, TCenter, Green, D3DCOLOR_XRGB(0, 0, 0), (char*)"<");
//			if (var != 0)
//				var = var--;
//		}
//	}
//
//	if (IsInBox(x + d, y + 3, 12, 12))
//	{
//		DrawBox(x + d, y + 3, 12, 12, D3DCOLOR_XRGB(32, 32, 32), Green, pDevice);
//		BordedTextComFlag(x + d + 6, y + 2, TCenter, Green, D3DCOLOR_XRGB(0, 0, 0), (char*)">");
//
//		if (GetAsyncKeyState(VK_LBUTTON) & 1)
//		{
//			DrawBox(x + d, y + 3, 12, 12, Green, Green, pDevice);
//			BordedTextComFlag(x + d + 6, y + 2, TCenter, Green, D3DCOLOR_XRGB(0, 0, 0), (char*)">");
//			if (var < max)
//				var = var++;
//		}
//	}
//}

VOID Additem(char* Text, int MaxValue, int& Value, int Kind, char** Opt, LPDIRECT3DDEVICE9 pDevice)
{
	extern int MenuSelection, PosX, PosY, Posy, Current;
	extern bool DesenharMenu;

	if (DesenharMenu) {
		if (MenuSelection == Current)
		{
			if (GetAsyncKeyState(VK_RIGHT) & 1) {
				if (Value < MaxValue)
					Value++;
			}
			else if (GetAsyncKeyState(VK_LEFT) & 1) {
				if (Value > 0)
					Value--;
			}
		}
		if (MenuSelection == Current) {
			BordedText( PosX - 5, Posy + (Current * 15), Cyan, Black, Text);//Cor Do Texto Quando Selection Em Cima.
			BordedText( PosX + 140, Posy + (Current * 15), Cyan, Black, Opt[Value]);//Cor Da Opção Quando Selection Em Cima.
		}
		else if (Value > 0) {
			if (Kind == 1) {
			}
			else {
				BordedText( PosX - 5, Posy + (Current * 15), White, Black, Text); // Cor Do Texto da Função Quando Ativada.
				BordedText( PosX + 140, Posy + (Current * 15), Green, Black, Opt[Value]); // Cor da Opção da Função Quando Ativada.
			}
		}
		else {
			if (Kind == 1) {
			}
			else {
				BordedText( PosX - 5, Posy + (Current * 15), White, Black, Text); // Cor Do Texto da Função Quando Desativada.
				BordedText( PosX + 140, Posy + (Current * 15), White, Black, Opt[Value]); // Cor da Opção da Função Quando Desativada.
			}
		}
		Current++;
	}
}