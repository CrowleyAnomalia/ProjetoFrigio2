#pragma once
#include "ColecaoAlbuns.h"
#include "Album.h"
#include <vector>
#include <string>
#include <iostream>

class FilaDeInteresses : public ColecaoAlbuns
{
    public:
        /* métodos “redundantes” mantidos por compatibilidade */
    void Adicionar(const Album& a);
    void Remover(const std::string& titulo);
    bool Empty() const noexcept { return albuns_.empty(); }
    const std::vector<Album>& GetWatchlist() const noexcept { return albuns_; }
    std::vector<Album>& GetWatchlist()       noexcept { return albuns_; }

    /* método polimórfico */
    void ListarQuadro(int porLinha, int largura) const override;
};
