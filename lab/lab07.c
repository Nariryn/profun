#include <stdio.h>
#include <windows.h>
#include <conio.h>

void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(4, 0);
    printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf("       ");
}

void setcursor(int visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void draw_Bullet(int a, int b)
{
    gotoxy(a, b);
    setcolor(3, 0);
    printf("|");
}

void erase_Bullet(int a, int b)
{
    gotoxy(a, b);
    setcolor(0, 0);
    printf(" ");
}

void draw_star(int k, int y)
{
    gotoxy(k, y);
    setcolor(6, 0);
    printf("*");
}

void erase_star(int k, int y)
{
    gotoxy(k, y);
    setcolor(0, 0);
    printf(" ");
}

char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2]; COORD c = { x,y }; DWORD num_read;
    if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}

void score(int sc)
{
    gotoxy(60, 1);
    setcolor(7, 0);
    printf("SCORE : %d", sc);
}

int main()
{
    char ch = ' ';
    int x = 35, y = 20;
    int i = 0;
    int bullet = 0;
    int cx, cy;
    int countscore = 0;

    setcursor(0);
    draw_ship(x, y);
    score(countscore);

    for (int d = 0; d < 20; d++) {
        draw_star(rand() % 60 + 10, rand() % 4 + 2);
    }

    do
    {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a' && x > 1)
            {
                erase_ship(x, y);
                draw_ship(--x, y);
            }
            if (ch == 'd' && x < 70)
            {
                erase_ship(x, y);
                draw_ship(++x, y);
            }
            if (ch == ' ' && bullet != 1)
            {
                bullet = 1; cx = x + 3; cy = y - 1;
            }
            fflush(stdin);
        }
        if (bullet == 1)
        {
            erase_Bullet(cx, cy);
            if (cy == 2)
            {
                bullet = 0;
            }
            else
            {
                if (cursor(cx, cy - 1) == '*')
                {
                    bullet = 0;
                    erase_Bullet(cx, cy);
                    erase_star(cx, cy - 1);
                    Beep(900, 200);
                    countscore++;
                    score(countscore);
                    draw_star(rand() % 60 + 10, rand() % 4 + 2);
                }
                else
                {
                    draw_Bullet(cx, --cy);
                    Beep(700, 200);
                }
            }
        }
        Sleep(100);
    } while (ch != 'x');
    return 0;
}
