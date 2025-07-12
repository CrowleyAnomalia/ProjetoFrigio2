#include "Banner.h"
#include "Centralizador.h"   // getTerminalSize() e visualLen()
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void Banner::printBannerAnimado()
{
    std::vector<std::string> arte = {
        "╔═══════════════════════════════════════════════════════════════════════════════════════╗",
        "║                                                                                       ║",
        "║ █████▒██▀███   ██▓  ▄████  ██▓ ▒█████      ███▄ ▄███▓ █    ██   ██████  ██▓ ▄████▄    ║",
        "║▓██   ▒▓██ ▒ ██▒▓██▒ ██▒ ▀█▒▓██▒▒██▒  ██▒   ▓██▒▀█▀ ██▒ ██  ▓██▒▒██    ▒ ▓██▒▒██▀ ▀█   ║",
        "║▒████ ░▓██ ░▄█ ▒▒██▒▒██░▄▄▄░▒██▒▒██░  ██▒   ▓██    ▓██░▓██  ▒██░░ ▓██▄   ▒██▒▒▓█    ▄  ║",
        "║░▓█▒  ░▒██▀▀█▄  ░██░░▓█  ██▓░██░▒██   ██░   ▒██    ▒██ ▓▓█  ░██░  ▒   ██▒░██░▒▓▓▄ ▄██  ║",
        "║░▒█░   ░██▓ ▒██▒░██░░▒▓███▀▒░██░░ ████▓▒░   ▒██▒   ░██▒▒▒█████▓ ▒██████▒▒░██░▒ ▓███▀░  ║",
        "║ ▒ ░   ░ ▒▓ ░▒▓░░▓   ░▒   ▒ ░▓  ░ ▒░▒░▒░    ░ ▒░   ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░░▓  ░ ░▒ ▒  ░ ║",
        "║ ░       ░▒ ░ ▒░ ▒ ░  ░   ░  ▒ ░  ░ ▒ ▒░    ░  ░      ░░░▒░ ░ ░ ░ ░▒  ░ ░ ▒ ░  ░  ▒    ║",
        "║ ░ ░     ░░   ░  ▒ ░░ ░   ░  ▒ ░░ ░ ░ ▒     ░      ░    ░░░ ░ ░ ░  ░  ░   ▒ ░░         ║",
        "║           ░      ░        ░  ░      ░ ░            ░      ░           ░   ░  ░ ░      ║",
        "║                                                                             ░         ║",
        "║                      Bem-vindo ao seu Letterboxd de Músicas!                          ║",
        "╚═══════════════════════════════════════════════════════════════════════════════════════╝"
    };

    std::cout << "\033[1;35m";      // cor roxa

    int largura = getTerminalSize().width;

    for(const std::string& linha : arte)
    {
        int espacos = (largura - static_cast<int>(visualLen(linha))) / 2;
        if(espacos < 0) espacos = 0;

        std::cout << std::string(espacos, ' ');

        for(char c : linha)
        {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        std::cout << '\n';
    }

    std::cout << "\033[0m";         // reset cor
}
