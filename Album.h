#pragma once
#include "Autor.h"
#include <string>
class Album
{
	std::string titulo;
	Autor autor;
	int anoLancamento;
	double nota{ 0.0 };

	public: Album(std::string titulo, Autor autor, int anoLancamento);
	public: Album(std::string titulo, Autor autor, int anoLancamento, double nota);
		  //getters
	public: std::string GetTitulo() const;
	public: std::string GetAutor() const;
	public: int GetAno() const;
	public: double GetNota() const;

};


