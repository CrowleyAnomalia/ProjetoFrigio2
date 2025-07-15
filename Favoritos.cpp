// Favoritos.cpp
#include "Favoritos.h"
#include <iostream>
#include <algorithm>

bool Favoritos::Adicionar(const Album& album)
{
    if(items_.size() >= kMaxFavoritos)
    {
        std::cout << "⚠️ Limite de favoritos (" << kMaxFavoritos << ") atingido.\n";
        return false;
    }
    items_.push_back(album);
    std::cout << "✅ Álbum \"" << album.GetTitulo() << "\" adicionado aos favoritos.\n";
    return true;
}

bool Favoritos::Remover(const std::string& titulo)
{
    auto it = std::find_if(items_.begin(), items_.end(),
                           [&](const Album& a) { return a.GetTitulo() == titulo; });
    if(it == items_.end())
    {
        std::cout << "⚠️ Álbum \"" << titulo << "\" não encontrado nos favoritos.\n";
        return false;
    }
    items_.erase(it);
    std::cout << "✅ Álbum \"" << titulo << "\" removido dos favoritos.\n";
    return true;
}

bool Favoritos::Editar(const std::string& tituloAntigo, const Album& albumNovo)
{
    auto it = std::find_if(items_.begin(), items_.end(),
                           [&](const Album& a) { return a.GetTitulo() == tituloAntigo; });
    if(it == items_.end())
    {
        std::cout << "⚠️ Álbum \"" << tituloAntigo << "\" não encontrado nos favoritos.\n";
        return false;
    }
    *it = albumNovo;
    std::cout << "✅ Álbum \"" << tituloAntigo << "\" atualizado para \""
        << albumNovo.GetTitulo() << "\" nos favoritos.\n";
    return true;
}

void Favoritos::Listar() const noexcept
{
    if(items_.empty())
    {
        std::cout << "📂 Nenhum favorito cadastrado.\n";
        return;
    }
    std::cout << "⭐ Lista de Favoritos ⭐\n";
    for(size_t i = 0; i < items_.size(); ++i)
    {
        const auto& a = items_[i];
        std::cout << i + 1 << ". "
            << a.GetTitulo()
            << " - " << a.GetAutor()
            << " (" << a.GetAno() << ")"
            << " Nota: " << a.GetNota()
            << "\n";
    }
}
