#include "main.h"


Character My_Character;
char tempMap[27][68];

int main()
{
	Init_Console();

	srand((int)time(NULL));	// 난수생성을 위한 시드값 제공

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

		case GAME_EXIT:		// 게임종료
			return 0;
		}
	}
}

int Percent(int percent)		// 확률 계산용 함수
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

int Void_Garbage_getch()			// 한글 및 엔터값 getch 처리
{
	int temp = _getch();

	if (temp == CARRIAGE_RETURN)	// 엔터 입력시 물음표표시 
	{
		return QUESTION_MARK;
	}
	//else if (temp > MAX_ASCII_NUM)	// 최대 아스키값 넘는 한글들을 물음표표시
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