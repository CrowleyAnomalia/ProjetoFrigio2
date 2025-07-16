// Favoritos.h
#pragma once

#include <vector>
#include <string>
#include "Album.h"

class Favoritos
{
    private:
    std::vector<Album> items_;
    static constexpr size_t kMaxFavoritos = 4;

    public:
        
    bool Adicionar(const Album& album);

  
    bool Remover(const std::string& titulo);

   
    bool Editar(const std::string& tituloAntigo, const Album& albumNovo);

    
    void Listar() const noexcept;

    
    const std::vector<Album>& GetFavoritos() const noexcept { return items_; }
};
