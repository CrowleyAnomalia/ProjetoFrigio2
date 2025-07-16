#pragma once
#include <string>
#include <vector>

#include "AlbunsOuvidos.h"      //herda de ColecaoAlbuns
#include "FilaDeInteresses.h"   // herda de ColecaoAlbuns
#include "Favoritos.h"
#include "Resenha.h"

class Perfil
{
    private:
    std::string nome_;
    std::string cabeca_;// avatar 
    Favoritos  favs_;//implementar dps
    std::vector<Resenha> resenhas_;

    AlbunsOuvidos albunsOuvidos_; 
    FilaDeInteresses filaDeInteresses_; 

    public:
       
    Perfil() = default;
    explicit Perfil(std::string nome) : nome_(std::move(nome)) {}

   //get/settt
    void SetNome(std::string n) { nome_ = std::move(n); }
    const std::string& GetNome() const noexcept { return nome_; }

    void SetCabeca(std::string c) { cabeca_ = std::move(c); }
    const std::string& GetCabeca() const noexcept { return cabeca_; }

    AlbunsOuvidos& Albuns() noexcept { return albunsOuvidos_; }
    const AlbunsOuvidos& Albuns() const noexcept { return albunsOuvidos_; }

    FilaDeInteresses& Watchlist() noexcept { return filaDeInteresses_; }
    const FilaDeInteresses& Watchlist() const noexcept { return filaDeInteresses_; }

    Favoritos& FavoritosColecao() noexcept { return favs_; }
    const Favoritos& FavoritosColecao() const noexcept { return favs_; }

    
    void MostrarPerfil() const;
};
