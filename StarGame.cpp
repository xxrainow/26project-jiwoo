#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAX 30


void SetConsoleSize(int _col, int _lines);
void GotoXY(int _x, int _y);
void Clear(void);
void StartMenu(void);
bool ScoreMenu(void);

struct st_state {
    int x = 0;
    int y = 0;
    bool bAct = false;
};

st_state stStar[MAX];
st_state stPlayer;

int score = 0;


int main() {

    SetConsoleSize(30, 30);
    srand(time(NULL));

    stPlayer.x = 14;
    stPlayer.y = 28;
    stPlayer.bAct = true;

    while (1)
    {
        StartMenu();
        while (1) {
            Clear();
            if (stPlayer.bAct) { //stPlayer.bAct가 false면 별 생성 안함
                // x축에 별 랜덤 생성
                for (int i = 0; i < MAX; i++) {
                    if (!stStar[i].bAct) {
                        stStar[i].x = (rand() % 15) * 2;
                        stStar[i].y = 0;
                        stStar[i].bAct = true; //별이 내려오게 함.
                        break; 
                    }
                }
                //input처리
                if (GetAsyncKeyState(VK_LEFT) & 0x8000) { 
                    stPlayer.x -= 2;
                    if (stPlayer.x < 0) stPlayer.x = 0;
                }
                if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                    stPlayer.x += 2;
                    if (stPlayer.x > 28) stPlayer.x = 28;
                }
            }


            // 별이 내려오는 과정 + 조건
            int cnt = 0;
            for (int j = 0; j < MAX; j++) {
                if (stStar[j].bAct)                 {
                    if (stStar[j].y == stPlayer.y) { //충돌
                        if (stStar[j].x == stPlayer.x) { 
                            stPlayer.bAct = false;
                            break;
                        }
                    }

                    cnt += 1;
                    GotoXY(stStar[j].x, stStar[j].y);
                    printf("★");
                    stStar[j].y++;

                    if (stStar[j].y > stPlayer.y) {
                        stStar[j].bAct = false;
                    }
                }
            }

            //Player 조건
            if (stPlayer.bAct) {
                GotoXY(stPlayer.x, stPlayer.y);
                printf("▲");
            }
            else {
                GotoXY(stPlayer.x, stPlayer.y);
                printf("▒");
            }


            if (stPlayer.bAct) {
                score += 1;
                GotoXY(28, 0);
                printf("%d", score);
            }

            Sleep(100);
            if (cnt == 0) {
                break;
            }

        }
        Sleep(50);
        if (ScoreMenu()) exit(0);
        Sleep(50);
    }

    system("pause");
    return 0;
}





void SetConsoleSize(int _col, int _lines) {
    char setText[100];
    sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
    system(setText);
}

void GotoXY(int _x, int _y) {
    COORD pos = { (short)_x, (short)_y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Clear(void) {
    system("cls");
}

void StartMenu(void) {
    while (1) {
        Clear();
        GotoXY(14, 10);
        printf("별 피하기 게임");
        GotoXY(12, 20);
        printf("시작하려면 아무키를 눌러주세요.");
        if (_kbhit()) break;
        Sleep(50);
    }

}


bool ScoreMenu(void) {
    bool end =false;
    while (1) {
        Clear();
        GotoXY(10, 10);
        printf("GAME OVER \n \n \n Score : %d", score);
        GotoXY(15, 20);
        printf("아무 키를 누르면 종료됩니다\n");
        if (_kbhit()) {
            end = true;
            break;
        }
        Sleep(50);
    }
    return end;
}
