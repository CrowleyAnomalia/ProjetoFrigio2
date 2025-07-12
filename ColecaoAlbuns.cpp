#include "ColecaoAlbuns.h"
bool ColecaoAlbuns::Remover(const std::string& titulo)
{
    auto it = std::find_if(albuns_.begin(), albuns_.end(),
                           [&](const Album& alb) { return alb.GetTitulo() == titulo; });
    if(it == albuns_.end()) return false;
    albuns_.erase(it);
    return true;
}
