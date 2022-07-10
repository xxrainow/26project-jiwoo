#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void movexy(int x, int y);

int main() {
	printf("HELLO"); // HELLO 출력
	movexy(3,2); // 커서를 오른쪽으로 3칸, 아래로 2칸 이동
	printf("WORLD"); // 이동한 커서에서 WORLD 출력
}
void movexy(int x, int y) {

	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

