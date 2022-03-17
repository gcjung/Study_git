#include "main.h"

//=======================================================
// Console 화면에 관련된 함수
//=======================================================
void gotoxy(short x, short y)	// 커서 위치 변경
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setcolor(int colFront, int colBack)	//글자색,배경색 설정
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((colBack << 4) | colFront));
}
void removeCursor(void)			// 커서 깜박이는거 지우기
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

