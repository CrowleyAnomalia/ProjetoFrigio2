#include "Album.h"

Album::Album(std::string titulo, Autor autor, int anoLancamento)
{
	this->titulo = titulo;
	this->autor = autor.GetNome();
	this->anoLancamento = anoLancamento;
}
Album::Album(std::string titulo, Autor autor, int anoLancamento, double nota)
{
	this->titulo = titulo;
	this->autor = autor.GetNome();
	this->anoLancamento = anoLancamento;
	this->nota = nota;

}
	  //getters
std::string Album::GetTitulo() const
{
	return titulo;

}
std::string Album::GetAutor() const
{
	return autor.GetNome();
}
int Album::GetAno() const
{
	return anoLancamento;
}
double Album::GetNota() const
{
	return nota;
}
