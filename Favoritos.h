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
        // Tenta adicionar; retorna true se sucesso, false se já estiver cheio
    bool Adicionar(const Album& album);

    // Tenta remover por título; retorna true se encontrou e removeu
    bool Remover(const std::string& titulo);

    // Tenta editar um álbum existente identificado pelo título antigo
    // Substitui pelos dados de albumNovo; retorna true se sucesso
    bool Editar(const std::string& tituloAntigo, const Album& albumNovo);

    // Lista todos os favoritos (simples, por linha)
    void Listar() const noexcept;

    // Acesso direto, se precisar
    const std::vector<Album>& GetFavoritos() const noexcept { return items_; }
};
