#include <stdio.h>
#include <conio.h>d
#include <windows.h>

void gotoxy(short x, short y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(short x, short y)
{
    gotoxy(x, y);
    printf(" <-0-> ");
}

void erase_ship(short x, short y)
{
    gotoxy(x, y);
    printf("       ");
}

int main()
{
    char ch = ' ';
    int x = 38, y = 20;

    draw_ship(x, y);

    do
    {
        if (_kbhit())
        {
            ch = _getch();

            erase_ship(x, y);

            switch (ch)
            {
                case 'a':
                    if (x > 0)
                    {
                        x--;
                    }
                    break;
                case 'd':
                    if (x < 80 - 6) // Adjusted boundary to prevent going off-screen
                    {
                        x++;
                    }
                    break;
                case 's':
                    if (y < 24) // Adjusted boundary to prevent going off-screen
                    {
                        y++;
                    }
                    break;
                case 'w':
                    if (y > 0)
                    {
                        y--;
                    }
                    break;
            }

            draw_ship(x, y);

            fflush(stdin);
        }
        Sleep(100);
    } while (ch != 'x');

    return 0;
}
