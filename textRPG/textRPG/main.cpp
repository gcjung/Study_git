#include "main.h"


Character My_Character;
char tempMap[27][68];

int main()
{
	Init_Console();

	srand((int)time(NULL));	// ���������� ���� �õ尪 ����

	Game game;
	int game_state = INTIAL_GAME_STATE;

	while (1)
	{
		switch (game_state)
		{
		case INTIAL_GAME_STATE:
			game_state = game.Initial_Game_State();
			break;

		case MIDDLE_GAME_STATE:
			game_state = game.Middle_Game_State();
			break;

		case GAME_EXIT:		// ��������
			return 0;
		}
	}
}

int Percent(int percent)		// Ȯ�� ���� �Լ�
{
	if ((rand() % 100) < percent)
	{		
		return SUCCESS;
	}
	else
	{		
		return FAIL;
	}
}

int Void_Garbage_getch()			// �ѱ� �� ���Ͱ� getch ó��
{
	int temp = _getch();

	if (temp == CARRIAGE_RETURN)	// ���� �Է½� ����ǥǥ�� 
	{
		return QUESTION_MARK;
	}
	//else if (temp > MAX_ASCII_NUM)	// �ִ� �ƽ�Ű�� �Ѵ� �ѱ۵��� ����ǥǥ��
	//{
	//	return QUESTION_MARK;
	//}

	return temp;
}

void Init_Console()
{
	system("mode con cols=70 lines=30 | title TXT_RPG");
	removeCursor();
}

void print_slime()
{
	int row = 37; gotoxy(16, row++);
	gotoxy(16, row++); cout << "                         . = @@!.     ";
	gotoxy(16, row++); cout << "                       ~=#=**=$#-     ";
	gotoxy(16, row++); cout << "     ;;-              ~:#      :=-    ";
	gotoxy(16, row++); cout << "    ;~, .             ~@        ~=,   ";
	gotoxy(16, row++); cout << "   *:~,. :           $!.=        ;=   ";
	gotoxy(16, row++); cout << "   ;::-,,~          :~~-.;        =-  ";
	gotoxy(16, row++); cout << "    ;=:~!          ;,:~,.,,       =@  ";
	gotoxy(16, row++); cout << "    .!!$.         ;-::-,. *       =#  ";
	gotoxy(16, row++); cout << "    .!          .$,::~-,,. $.     ;$  ";
	gotoxy(16, row++); cout << "     ;        ,=!-::~--,,.  !-    !#  ";
	gotoxy(16, row++); cout << "     #~     ;*:,~::~--,,,.   ,!   $@  ";
	gotoxy(16, row++); cout << "     ~#   $~-,~:::~--,,,..     ~: $@  ";
	gotoxy(16, row++); cout << "      !#@~,--::::~---,,,.       ,@#   ";
	gotoxy(16, row++); cout << "      ,*.--~::::~----,,..        ~#   ";
	gotoxy(16, row++); cout << "     .*,-=!::::~~---,,,..         $   ";
	gotoxy(16, row++); cout << "     $.-#;#@:::~---,,,,..         .*  ";
	gotoxy(16, row++); cout << "     ;-~= $@::~~---,,@~@,.         #  ";
	gotoxy(16, row++); cout << "    $.-:@-~:::~~---,#* $@..        *  ";
	gotoxy(16, row++); cout << "    #,~:;@$;:::~--,,*-  !,.....       ";
	gotoxy(16, row++); cout << "    #,~:;;;:;!*~~-,,~@ @#,, ......  ; ";
	gotoxy(16, row++); cout << "    #,~:;;;::! =#-,,,~**,,,,,.  ..  * ";
	gotoxy(16, row++); cout << "    #,~:;;;::!*##--,,,,,,,,,,.  ..  * ";
	gotoxy(16, row++); cout << "    #.-:;;:::!*=#--,,,,,,,,,,.  ..  , ";
	gotoxy(16, row++); cout << "    , -~:::::!;~$---,,,,,,,,,,..,. #  ";
	gotoxy(16, row++); cout << "     =,-~~:::;..$----,,,,,,,,,,,,  #  ";
	gotoxy(16, row++); cout << "     *-,,-~:::, $~---,,,,,,,,,,,. $   ";
	gotoxy(16, row++); cout << "      $  ,-::::;~~-----,,,,,,-,. !;   ";
	gotoxy(16, row++); cout << "      .$ .-::::;~~~~----------. #;    ";
	gotoxy(16, row++); cout << "        $.,-~::::::~~~~~~~~~, .#      ";
	gotoxy(16, row++); cout << "         ,$:.-~~::::::::~-, ~#!       ";
	gotoxy(16, row++); cout << "           -***,.,,,,,,.*!#:-         ";
	gotoxy(16, row++); cout << "              ..,$@@@@;...            ";
}