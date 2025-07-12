#include "Resenha.h"
	std::string Resenha::CriarResenha(std::string c)
	{
		resenha = c;
		MarcarComoOuvido();
		return c;

	}
	void Resenha::MarcarComoOuvido()
	{
		ouvido = true;
	}
	void Resenha::Remover()
	{

	}
    
