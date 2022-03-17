#pragma once

// ���� ����
enum Initial_Game_State{ INTIAL_GAME_STATE, INIT_GAME, NEW_GAME_START, CONTINUE_GAME_START, GAME_INFO, GAME_EXIT};
enum Middle_Game_State{ MIDDLE_GAME_STATE=10, PLAYING_GAME};

#define MAX_STAGE1_MONSTER_NUM 100
#define MAX_STAGE2_MONSTER_NUM 100
#define MAX_STAGE3_MONSTER_NUM 100
#define MAX_STAGE4_MONSTER_NUM 100
#define MAX_STAGE5_MONSTER_NUM 100
#define MAX_STAGE6_MONSTER_NUM 100
#define MAX_STAGE7_MONSTER_NUM 100
#define MAX_STAGE8_MONSTER_NUM 100
#define MAX_STAGE9_MONSTER_NUM 100
#define MAX_STAGE10_MONSTER_NUM 100


//=======================================================
// Game Class - ������ ȭ��, ����� ���õ� ����Լ� ����
//=======================================================
class Game
{
public:
	Game();

	string Class_ItoS(char chractor_class);
	
	// ��
	int Initial_Game_State();
	int Init_Screen();
	int Game_Info_Screen();
	int Charactor_Create_Screen();
	void Init_Game_Frame();

	// ��
	int Middle_Game_State();
	int Playing_Game_Screen();
	void Middle_Game_Frame();


	// �� ���� �Լ�
	void Map_Window(int dungeonStage);
	void Make_Map_Dungeon1(int dungeonStage);
	void Make_Map_Dungeon2(int dungeonStage);
	void Make_Map_Dungeon3(int dungeonStage);
	 

	// ĳ���� ����â ���� �Լ�
	void Character_Info_Window(int state, int dungeonStage);
	void Character_Status(int dungeonStage);
	void Character_Inventory();
	void Remove_Character_Info_Window();

	// ��������â ��� ����
	void Remove_GameProcess_Window();
	void Remove_Inventory_In_Store();
	void Remove_Inventory_In_Battle();
	void Remove_Battle_Log();
	void Remove_At_Battle_End();

	// ���� ����
	void Store_Process(int dungeonStage, int* infoWindowType);
	void Store_Screen(int dungeonStage);
	void Store_Buy_Mode(int dungeonStage,int input);
	void Store_Sell_Mode(int input);

	// ���� ��������
	void Battle_Process(int dungeonStage, int *infoWindowType);
	void Battle_Screen(Monster* monster);

	void Battle_RunAway();
	void Monster_Decision(int dungeonStage, Monster* monster);
	int Battle_Use_Item();
	void Battle_Log_window();


};