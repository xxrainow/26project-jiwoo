#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

void movexy(int x, int y);

int main() {
	int x = 0, y = 0;

	for (int i = 0; i < 2; i++) {
		srand(time(NULL));

		x = (rand() % 15) * 2;

	}
	while (1) {
		y = 0;
		while (1) {

			system("cls");
			y++;
			movexy(x, y);
			cout << "¡Ú";
			Sleep(50);
			if (y == 20)
				break;
		}
	}

	system("pause");
	return 0;
}



void movexy(int x, int y) {

	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}