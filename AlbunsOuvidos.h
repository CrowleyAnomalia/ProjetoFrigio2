﻿#pragma once
#include "ColecaoAlbuns.h"
#include "Album.h"
#include "Cores.h"
#include <vector>
#include <string>
#include <iostream>

class AlbunsOuvidos : public ColecaoAlbuns
{
    public:
    void ListarQuadro(int porLinha, int largura) const override;

    
    bool Empty() const noexcept { return albuns_.empty(); }

    const std::vector<Album>& GetAlbuns() const noexcept { return albuns_; }
    std::vector<Album>& GetAlbuns()       noexcept { return albuns_; }
};  
