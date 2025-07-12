#include "Banner.h"
#include "Menu.h"
#include "Plataforma.h"
#include <windows.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "Centralizador.h"
#include <ctime>
#include <string>

int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    limparTela();
    Banner::printBannerAnimado();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    limparTela(); // limpa antes do menu
    Menu m;
    m.menuUsuario();

    return 0;
}
