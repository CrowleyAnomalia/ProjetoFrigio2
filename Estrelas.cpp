#include "Estrelas.h"

std::string Estrelas::GerarEstrelas(int nota)
{

	int estrelas = static_cast<int>(nota / 2);
	return std::string(estrelas, '*');
}


