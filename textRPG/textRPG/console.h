#pragma once

enum {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	PURPLE,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTPURPLE,
	YELLOW,
	WHITE
};

#define MAX_CONSOLE_COLOR_NUM 16

#define ONE	49
#define TWO 50
#define THREE 51
#define FOUR 52
#define SPACE_BAR 32


void gotoxy(short x, short y);
void setcolor(int colFront, int colBack); //글자색,배경색
void removeCursor(void); //커서지우기
