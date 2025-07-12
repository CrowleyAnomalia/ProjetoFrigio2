#include "Animacao.h"
#include "Plataforma.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

// Efeito digitando com delay
void printDigitando(const std::string& text, int delayMs = 30)
{
    for(char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << std::endl;
}

// Exibir a arte e mensagem com efeito digitado
void mostrarAnimacao()
{
    std::string arte = R"(
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

    std::string frase = "[x] Sistema encerrado com sucesso.";

    limparTela();

    // Digitando a arte linha por linha
    std::istringstream stream(arte);
    std::string linha;
    while(std::getline(stream, linha))
    {
        printDigitando(linha, 5); // mais rápido pra arte
    }

    std::cout << std::endl;
    printDigitando(frase, 50); // mais lento pra mensagem final

    std::this_thread::sleep_for(std::chrono::seconds(2));
    limparTela();
}
