#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_star(int x, int y)
{
    gotoxy(x, y); printf("*");
}
void setcursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
void draw_ship(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int fg = 2, bg = 4;
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
    COORD c = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("<-0->");
}
void erase_ship(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int fg = 2, bg = 0;
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
    COORD c = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("     ");
}
void draw_bullet(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int fg = 7, bg = 0;
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
    COORD c = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("|");
}
void erase_bullet(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int fg = 7, bg = 0;
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
    COORD c = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" ");
}
char cursor(int x, int y) {
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2]; COORD c = { x,y }; DWORD num_read;
    if (
        !ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}
int main() {
    setcursor(0);
    char ch = ' ';
    int posX = 38, posY = 20;
    draw_ship(posX, posY);
    int toTheleft = 0, toTheright = 0, BulletShot[5] = { 0,0,0,0,0 };
    int BullposX[5] = { 0,0,0,0,0 }, BullposY[5] = { 0,0,0,0,0 };
    srand((unsigned int)time(NULL));
    int starx, stary;
    for (int i = 0; i < 20; i++) {
        starx = (rand() % 60) + 10;
        stary = (rand() % 4) + 1;
        while (cursor(starx, stary) == '*'); {
            starx = (rand() % 61) + 10;
            stary = (rand() % 4) + 1;
        }
        draw_star(starx, stary);
    }
    do {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'a') {
                toTheleft = 1;
                toTheright = 0;
            }
            if (ch == 'd') {
                toTheleft = 0;
                toTheright = 1;
            }
            if (ch == 's') {
                toTheleft = 0;
                toTheright = 0;
                draw_ship(posX, 20);
            }
            if (ch == ' ') {
                for (int i = 0; i < 5; i++) {
                    if (BulletShot[i] == 0) {
                        BulletShot[i] = 1;
                        BullposX[i] = posX + 2;
                        BullposY[i] = posY - 1;
                        break;
                    }
                }
            }
            fflush(stdin);
        }
        if (toTheleft == 1 && posX > 0) {
            erase_ship(posX, 20);
            draw_ship(--posX, 20);
        }
        if (toTheright == 1 && posX <= 80) {
            erase_ship(posX, 20);
            draw_ship(++posX, 20);
        }
        for (int j = 0; j < 5; j++) {
            if (BulletShot[j] == 1 || BulletShot[j] == 2) {
                if (BulletShot[j] == 2) {
                    if (BullposY[j] - 1 == 0) {
                        BulletShot[j] = 0;
                        erase_bullet(BullposX[j], BullposY[j]);
                    }
                    else {
                        erase_bullet(BullposX[j], BullposY[j]);
                        draw_bullet(BullposX[j], --BullposY[j]);
                    }
                }
                if (BulletShot[j] == 1) {
                    draw_bullet(BullposX[j], BullposY[j]);
                    BulletShot[j] = 2;
                }
            }
        }
        Sleep(100);
    } while (ch != 'x');
    return 0;
}
