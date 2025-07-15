// Resenha.h
#pragma once
#include <string>
#include "Album.h"
#include "Estrelas.h"

class Resenha
{
    private:
    Album album_;
    std::string texto_;
    int nota_{ 0 };
    bool ouvido_{ false };
    bool favorito_{ false };

    public:
        
    Resenha() = default;
    Resenha(const Album& alb, const std::string& txt, int nota);

    
    const Album& GetAlbum() const noexcept { return album_; }
    const std::string& GetTexto() const noexcept { return texto_; }
    int GetNota() const noexcept { return nota_; }
    bool IsOuvido() const noexcept { return ouvido_; }
    bool IsFavorito()  const noexcept { return favorito_; }

   
    void SetTexto(const std::string& txt) { texto_ = txt; }
    void SetNota(int nota) { nota_ = nota; }
    void MarkOuvido(bool v = true) { ouvido_ = v; }
    void MarkFavorito(bool v = true) { favorito_ = v; }

    
    void Mostrar() const;
};
