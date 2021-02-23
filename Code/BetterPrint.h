	#pragma once
#include <Windows.h>

void SetFontColor(int color)
{
	/*
	0 - BLACK ��

	1 - BLUE �� 2 - GREEN ��

	3 - CYAN �� 4 - RED ��

	5 - MAGENTA ��� 6 - BROWN ��

	7 - LIGHTGRAY ���� 8 - DARKGRAY ���

	9 - LIGHTBLUE ���� 10 - LIGHTGREEN ����

	11 - LIGHTCYAN ���� 12 - LIGHTRED ����

	13 - LIGHTMAGENTA ����� 14 - YELLOW ��

	15 - WHITE ��
	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void MoveCursor(int startX, int startY)
{
	HANDLE hd;
	COORD pos;
	pos.X = startX;
	pos.Y = startY;
	hd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hd, pos);
}