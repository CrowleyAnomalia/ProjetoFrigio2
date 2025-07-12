#include "Cores.h"
#include <iostream>

std::string corQuadrados = "\033[1;31m";
std::string corMenu = "\033[1;34m";
std::string reset = "\033[0m";

std::string corParaCodigo(const std::string& cor)
{
    if(cor == "vermelho") return "\033[1;31m";
    if(cor == "roxo")     return "\033[1;35m";
    if(cor == "azul")     return "\033[1;34m";
    if(cor == "verde")    return "\033[1;32m";
    if(cor == "amarelo")  return "\033[1;33m";
    if(cor == "ciano")    return "\033[1;36m";
    return "\033[0m";
}

void alterarCores()
{
    std::cout << "Cor dos quadrados (vermelho, azul, verde, amarelo, roxo, ciano): ";
    std::string corQ;
    std::getline(std::cin, corQ);
    corQuadrados = corParaCodigo(corQ);

    std::cout << "Cor do menu (vermelho, azul, verde, amarelo, roxo, ciano): ";
    std::string corM;
    std::getline(std::cin, corM);
    corMenu = corParaCodigo(corM);
}
