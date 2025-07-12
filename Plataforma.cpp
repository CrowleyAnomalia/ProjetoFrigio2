#include "Plataforma.h"
#include <iostream>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void limparTela()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int getKey()
{
    #ifdef _WIN32
    int c = _getch();
    if(c == 224) return _getch();
    return c;
    #else
    char buf = 0;
    struct termios old = {};
    tcgetattr(0, &old);
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &old);
    read(0, &buf, 1);
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    tcsetattr(0, TCSADRAIN, &old);

    if(buf == 27)
    {
        char seq[2];
        read(0, &seq[0], 1);
        read(0, &seq[1], 1);
        if(seq[0] == '[')
        {
            if(seq[1] == 'A') return 'U';
            if(seq[1] == 'B') return 'D';
        }
    }
    return buf;
    #endif
}
