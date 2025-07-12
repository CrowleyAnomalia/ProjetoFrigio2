#pragma once
#include "Perfil.h"
#include <string>

void salvarPerfil(const Perfil& p, const std::string& arquivo = "perfil.txt");
bool carregarPerfil(Perfil& p, const std::string& arquivo = "perfil.txt");
