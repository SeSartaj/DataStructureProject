#include <iostream>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

bool gameover;
const unsigned char BLACK = 219;
int COLUMNS;
int ROWS;
int OPTION;
char fruit[5];
int fruitx[5];
int fruity[5];
int slowness = 10000;
int highScore;

bool progressBar();
bool gotoxy(const WORD x, const WORD y);
void consuleSize();
//void MoveCenter();
void menu();
BOOL play();
inline void exitgame();
inline void highscore();
void drawStage();
void draw();
void logic();
void input();

using namespace std;

int main() {

    //MoveCenter();
    consuleSize();
    progressBar();
    menu();
    return 0;
}

bool gotoxy(const WORD x, const WORD y) {
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

bool progressBar()
{
    gotoxy(COLUMNS/2-8, ROWS/2-3);
    cout << "Welcome to TypingTutor!";
    for(int i = 1; i <= 100; i++)
    {
        gotoxy(COLUMNS/2-(50-i), ROWS/2-1);
        cout << "|";
        gotoxy(COLUMNS/2-3, ROWS/2+1);
        cout << "Loading " <<i <<"%" ;
        // Decoration
        if(i == 29 || i==42 || i == 57 || i == 81 || i == 99)
        {
            Sleep(20);
        }
        else
        {
            Sleep(2);
        }


    }
    Sleep(10);
}

void menu()
{
    gotoxy(COLUMNS/2-10, ROWS/2+3);
    cout << "(1) New Game";
    gotoxy(COLUMNS/2-10, ROWS/2+4);
    cout << "(2) High Scores";
    gotoxy(COLUMNS/2-10, ROWS/2+5);
    cout << "(3) Exit";
    int input;
    gotoxy(COLUMNS/2-10, ROWS/2+6);
    cin >> OPTION;


    switch(OPTION)
    {
    case 1:
        play();
        break;
    case 2:
        highscore();
        break;
    case 3:
        exitgame();
        break;
    }
}

void consuleSize()
{
    Sleep(4000);
    CONSOLE_SCREEN_BUFFER_INFO csbi;


    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COLUMNS = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    ROWS = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
/*
void MoveCenter()
{
    RECT rectClient, rectWindow;
    HWND hWnd = GetConsoleWindow();
    GetClientRect(hWnd, &rectClient);
    GetWindowRect(hWnd, &rectWindow);
    int posx, posy;
    posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
    posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,

    MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
    //MoveWindow(hWnd, posx, posy, 800, 600, TRUE);
}
*/
BOOL play()
{
    drawStage();
    while(!gameover)
    {
        draw();
        input();
        logic();
    }


}

void drawStage(){
    gotoxy(0,0);
    for(int i =0; i< ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            if(i == 0 || i==1 || i == ROWS-1 || i==ROWS-3 || j==0 || j== COLUMNS-1)
            {
                printf("#");
            }
            else{
                printf(" ");
            }
        }
    }

}

void draw(){
    // TODOs
}

void input(){
    // TODOs
}

void logic(){
    // TODOs
}

inline void highscore()
{
    cout << "highscore";
}

inline void exitgame()
{
    cout << "Exiting!!!";
}
