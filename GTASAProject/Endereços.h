#define PRESENTCALL		0x007F9B0F

#define VIEWPORTX	0xC17044
#define VIEWPORTY	0xC17048
#define W2S	0x71DAB0 

#define GETBONEPOS 0x5E4280 
// 5 cabeça

#define LOCALPLAYER 0xB6F5F0
#define STARTPLAYER		0xB7CD98
#define SIZEPlAYER		0x7C4

#define CAMERAX		0xB6F258
#define CAMERAY		0xB6F248

#define CPOS_X 0xB6F9CC
#define CPOS_Y 0xB6F9D0

#define distaciatoline 0x417610
#define JETPACK 0x439600
#define CHECKPEDS 0x4154A0
#define IS_ENTITY_VALID	0x533310
#define IS_PLAYER_SHOOTABLE 0x5DEFD0
#define CHECK_VISIBILITY 0x5E1660

#define FIRSTPERSON 0x50AC10



//00736010 onde registra a posição do tiro da sniper
//0074242C comparaçao da sniper com otras

//0xBA6748 + 0x5c // player in menu


CHAR* Opt_KeyFovAimbot[] = { (char*)"5º", (char*)"20º", (char*)"45º",(char*)"180º" };
int FovAimbot;
CHAR* Opt_KeyAimbot[] = { (char*)"Mouse1", (char*)"Mouse2",(char*)"E" };
int KeyAimbot;
CHAR* Opt_Menu[] = { (CHAR*)"+", (CHAR*)"-" };
CHAR* Opt_Opções[] = { (CHAR*)"Off",(CHAR*)"On" };