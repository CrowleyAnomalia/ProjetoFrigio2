﻿#include "Animacao.h"
#include "Plataforma.h"      // getTerminalSize()
#include "Centralizador.h" //visualLen()
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>


static void printDigitando(const std::string& text, int delayMs = 30)
{
    for(char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << '\n';
}


void mostrarAnimacao()
{
    /* arte ASCII */
    const std::string arte = R"(
  ▄████  ▒█████   ██▀███   ▄▄▄       ██▓    
 ██▒ ▀█▒▒██▒  ██▒▓██ ▒ ██▒▒████▄    ▓██▒    
▒██░▄▄▄░▒██░  ██▒▓██ ░▄█ ▒▒██  ▀█▄  ▒██░    
░▓█  ██▓▒██   ██░▒██▀▀█▄  ░██▄▄▄▄██ ▒██░    
░▒▓███▀▒░ ████▓▒░░██▓ ▒██▒ ▓█   ▓██▒░██████▒
 ░▒   ▒ ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ▒░▓  ░
  ░   ░   ░ ▒ ▒░   ░▒ ░ ▒░  ▒   ▒▒ ░░ ░ ▒  ░
░ ░   ░ ░ ░ ░ ▒    ░░   ░   ░   ▒     ░ ░   
      ░     ░ ░     ░           ░  ░    ░  ░
)";

    const std::string frase = "[x] Sistema encerrado com sucesso.";

    limparTela();
    const int larguraTerm = getTerminalSize().width;

    /* -------- imprime a arte centralizada ----*/
    std::istringstream in(arte);
    std::string linha;
    while(std::getline(in, linha))
    {
       
        std::size_t first = linha.find_first_not_of(' ');
        std::string ltrim = (first == std::string::npos) ? "" : linha.substr(first);

        int vis = static_cast<int>(visualLen(ltrim));
        int esp = (larguraTerm - vis) / 2;
        if(esp < 0) esp = 0;

        std::cout << std::string(esp, ' ');
        printDigitando(ltrim, 5);          
    }

    int espMsg = (larguraTerm - static_cast<int>(frase.size())) / 2;
    if(espMsg < 0) espMsg = 0;

    std::cout << '\n' << std::string(espMsg, ' ');
    printDigitando(frase, 50);             

    std::this_thread::sleep_for(std::chrono::seconds(2));
    limparTela();                         
}
