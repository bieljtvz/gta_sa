class Object
{
public:
	char _0x0000[48];
	D3DXVECTOR3 Pos; //0x0030 
	char _0x003C[1028];

};//Size=0x0440


//132 crounted
class PlayerInfo0
{
public:
	char _0x0000[20];
	union
	{
		__int32* iObject; //0x0014 
		Object* pObject;
	};
	char _0x0018[32];
	float IsPlayer; //0x0038 
	char _0x003C[132];
	__int32 ProximoCarro; //0x00C0 
	char _0x00C4[936];
	BYTE CheckPlayerStats; //0x046C 
	char _0x046D[211];
	float Vida; //0x0540 
	char _0x0544[4];
	float Colete; //0x0548 
	char _0x054C[500];
	__int32 current_wearpon; //0x0740 
	char _0x0744[1276];
};//Size=0x1440

class PlayerInfo1
{
public:
	char _0x0000[20];
	union
	{
		__int32* iObject;//0x0014 
		Object* pObject;
	};
	char _0x0018[32];
	float isplayer; //0x0038 
	char _0x003C[6];
	BYTE especial_flags; //0x0042 
	char _0x0043[125];
	__int32 proximo_carro; //0x00C0 
	char _0x00C4[936];
	BYTE player_stats; //0x046C 
	BYTE player_jumping; //0x046D 
	char _0x046E[1];
	BYTE player_crouch; //0x046F 
	char _0x0470[208];
	float vida; //0x0540 
	char _0x0544[4];
	float colete; //0x0548 
	char _0x054C[500];
	__int32 current_wearpon; //0x0740 //358 = snipermira
	char _0x0744[1276];

};//Size=0x0C40
