#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define screen_x 80
#define screen_y 25
#define scount 25

HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
COORD star[scount];
DWORD numEvents = 0;
DWORD numEventsRead = 0;

int ship_color = rand();
int hit = 48;

int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
    ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}

void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}

void clear_buffer()
{
    for (int y = 0; y < screen_y; ++y) {
        for (int x = 0; x < screen_x; ++x) {
            consoleBuffer[x + screen_x * y].Char.AsciiChar = 32;
            consoleBuffer[x + screen_x * y].Attributes = 7;
        }
    }
}

void init_star()
{
    for ( int i = 0; i < scount; i++)
    {
        star[i].X = rand() % 80;
        star[i].Y = 1 + rand() % 24;
    }
}

void star_fall()
{
    for (int i = 0; i < scount; i++)
    {
        if (star[i].Y >= screen_y - 1)
        {
            star[i].X = rand() % screen_x;
            star[i].Y = 1;
        }
        else
        {
            star[i].Y = star[i].Y + 1;
        }
    }
}

void star_hit()
{
    int i;
    for (int i = 0; i < scount; i++)
    {
       if (consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar != 42 &&
        consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar != 32)
        {
            star[i].X = rand() % screen_x;
            star[i].Y = 1;
            hit = hit + 1;
        }
            
       else if (consoleBuffer[star[i].X + screen_x * star[i].Y+1].Char.AsciiChar != 42 && 
       consoleBuffer[star[i].X + screen_x * star[i].Y+1].Char.AsciiChar != 32)
        {
            if (star[i].Y+1 <20)
            {
            star[i].X = rand() % screen_x;
            star[i].Y = 1;
            hit = hit + 1; 
            }
        } 
    }
    
}

void printBuff( char str[], int posx, int posy)
{
    for (int i = 0 ; i < strlen(str) ; i++)
    {
        consoleBuffer[posx + i + screen_x * posy].Char.AsciiChar = str[i];
        consoleBuffer[posx + i + screen_x * posy].Attributes = 7;
    } 
    
}

void fill_star_to_buffer()
{
    for (int i = 0; i < scount; i++)
    {
        int x = star[i].X;
        int y = star[i].Y;

        consoleBuffer[x + screen_x * y].Char.AsciiChar = 42; 
        consoleBuffer[x + screen_x * y].Attributes = 1 + rand() % 8;
    }
    printBuff("LIFE : ", 72, 0);
    consoleBuffer[78].Char.AsciiChar = hit; 
    consoleBuffer[78].Attributes = 7;

}

void ship_in_Buff(int x, int y)
{
    char str[10] = " <-0-> ";
    for (int i = 0; i < strlen(str) ; i++)
    {
        consoleBuffer[x + i + screen_x * y].Char.AsciiChar = str[i]; 
        consoleBuffer[x + i + screen_x * y].Attributes = 1 + ship_color% 8;
    }
}

int capPosx(int x)
{
     if (x > 75){
        return 75;
    }
    if (x < 4){
        return 4;
    }
}
int capPosy (int x)
{
    if (x > 25){
        return 25;
    }
    if (x < 1){
        return 1;
    }
}

int main()
{

    bool play = true;
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    srand (time(NULL));
    setConsole(screen_x, screen_y);
    setMode();
    init_star();
    int sec = 0;
    int tempx = 0, tempy = 0;

    while (play)
    {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (hit>57) {
            hit = 48;
            play = false;
        }
        star_fall();
        if (sec >10){
            star_hit();
        }
        clear_buffer();
        fill_star_to_buffer();

        if (numEvents != 0) {
            INPUT_RECORD *eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i) {
                int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                
                if (eventBuffer[i].EventType == KEY_EVENT &&
                    eventBuffer[i].Event.KeyEvent.bKeyDown == true ) {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
                        play = false;
                    }
                    if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c'){
                        ship_color = rand();
                        }
                    }
                else if (eventBuffer[i].EventType == MOUSE_EVENT) {
                    if (eventBuffer[i].Event.MouseEvent.dwButtonState &
                        FROM_LEFT_1ST_BUTTON_PRESSED) {
                            ship_color = rand();
                        }
                    else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
                        posx = capPosx(posx);
                        posy = capPosy(posy);
                        tempx = posx - 4;
                        tempy = posy;
                        
                    }
                }
                ship_in_Buff(tempx, tempy);
        }
        fill_buffer_to_console();
        delete[] eventBuffer;
    }
    else{
        ship_in_Buff(tempx, tempy);
        fill_buffer_to_console();
    }
    sec++;
    Sleep(100);

} 
    clear_buffer();
    printBuff("GAME OVER", 36, 12);
    fill_buffer_to_console();
    Sleep(5000);

    return 0;
}
