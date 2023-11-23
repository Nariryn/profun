#include <windows.h>
#include <time.h>
#include <stdlib.h> 
#include <stdio.h> 

#define screen_x 80
#define screen_y 25
HANDLE wHnd;

CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };


int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

char randomChar()
{
    return 'A' + (rand() % 26);
}

WORD randomColor()
{
    return rand() % 255;
}

void fill_data_to_buffer()
{
    for (int y = 0; y < screen_y; ++y) {
        for (int x = 0; x < screen_x; ++x)
        {
            consoleBuffer[x + screen_x * y].Char.AsciiChar = randomChar();
            consoleBuffer[x + screen_x * y].Attributes = randomColor();
        }
    }
}

void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
    &windowSize);
}

int main()
{
    setConsole(screen_x, screen_y);
    srand((unsigned)time(NULL));
    for (int cycle = 0; cycle < 10000; ++cycle)
    {
        fill_data_to_buffer();
        fill_buffer_to_console();
        Sleep(100);
    }
   
    return 0;
}