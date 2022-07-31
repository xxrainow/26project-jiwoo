#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// #include "Console.h"
using namespace std;

void SetConsoleSize(int _col, int _lines);
void GotoXY(int _x, int _y);
void Clear(void);

int main() {
	int x = 14, y = 28;
	SetConsoleSize(30, 30);

	while (1) {
		Clear();
		if (GetAsyncKeyState(VK_LEFT) && 0x8000) {
			x++;
			if (x < 0) x = 0;
		}
		if (GetAsyncKeyState(VK_RIGHT) && 0x8000) {
			x--;
			if (x > 28) x = 28;
		}

		GotoXY(x, y);
		printf("бу");
		Sleep(100);
	}

	system("pause");
	return 0;
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}

void GotoXY(int _x, int _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Clear(void)
{
	system("cls");
}
