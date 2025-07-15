// Resenha.cpp
#include "Resenha.h"
#include "Plataforma.h" // para limparTela()
#include <iostream>

Resenha::Resenha(const Album& alb, const std::string& txt, int nota)
    : album_(alb), texto_(txt), nota_(nota), ouvido_(true), favorito_(false)
{
}

void Resenha::Mostrar() const
{
    limparTela();
    std::cout << "══════ Resenha de \"" << album_.GetTitulo() << "\" ══════\n\n";
    std::cout << "Nota: ";
    Estrelas::GerarEstrelas(nota_);    // adapte para o método que você já usa
    std::cout << "\n\n" << texto_ << "\n";
}
