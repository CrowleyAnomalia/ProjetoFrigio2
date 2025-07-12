#pragma once
#include <vector>
#include <string>
#include "Album.h"

class ColecaoAlbuns
{
    protected:
    std::vector<Album> albuns_;

    public:
    void Adicionar(const Album& a) { albuns_.push_back(a); }

    bool Remover(const std::string& titulo);

    std::size_t size() const noexcept { return albuns_.size(); }
    bool Empty()   const noexcept { return albuns_.empty(); }

    virtual void ListarQuadro(int porLinha, int largura) const = 0;
    virtual ~ColecaoAlbuns() = default;
};
