#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

struct TerminalSize
{
    int width;
    int height;
};

inline TerminalSize getTerminalSize()
{
    TerminalSize size{ 80, 24 };

    #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        size.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        size.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    #else
    struct winsize w;
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
    {
        size.width = w.ws_col;
        size.height = w.ws_row;
    }
    #endif

    return size;
}

inline void imprimirCentralizado(const std::vector<std::string>& linhas)
{
    TerminalSize term = getTerminalSize();

    int linhasAntes = (term.height - static_cast<int>(linhas.size())) / 2;
    for(int i = 0; i < linhasAntes; ++i)
        std::cout << '\n';

    for(const auto& linha : linhas)
    {
        int espacos = (term.width - static_cast<int>(linha.length())) / 2;
        std::cout << std::string(espacos > 0 ? espacos : 0, ' ') << linha << '\n';
    }
}


/// Devolve quantas colunas a string realmente ocupa no terminal.
inline std::size_t visualLen(const std::string& s)
{
    // remove códigos ANSI (ex.: "\033[1;35m")
    static const std::regex ansi(R"(\x1B\[[0-9;]*m)");
    std::string clean = std::regex_replace(s, ansi, "");

    // conta apenas bytes que NÃO são de continuação UTF-8 (10xxxxxx)
    std::size_t cols = 0;
    for(unsigned char ch : clean)
        if((ch & 0xC0) != 0x80)  // 0x80-0xBF são bytes de continuação
            ++cols;
    return cols;
}


