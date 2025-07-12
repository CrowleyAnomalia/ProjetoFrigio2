#include "ServicosPerfil.h"
#include <fstream>
#include <utility>

void salvarPerfil(const Perfil& p, const std::string& arq)
{
    std::ofstream out(arq, std::ios::trunc);
    if(!out) { std::cerr << "Erro ao gravar " << arq << "\n"; return; }

    out << p.GetNome() << '\n';

    // -- álbuns avaliados --
    const auto& vistos = p.Albuns().GetAlbuns();
    out << vistos.size() << '\n';
    for(const auto& alb : vistos)
        out << alb.GetTitulo() << '\n' << alb.GetNota() << '\n';

    // -- watch-list --
    const auto& watch = p.Watchlist().GetWatchlist();
    out << watch.size() << '\n';
    for(const auto& alb : watch)
        out << alb.GetTitulo() << '\n';
}

bool carregarPerfil(Perfil& p, const std::string& arq)
{
    std::ifstream in(arq);
    if(!in) return false;

    std::string nome; std::getline(in, nome);
    p.SetNome(std::move(nome));

    size_t qtd{};
    // -- álbuns avaliados --
    in >> qtd; in.ignore();
    p.Albuns().GetAlbuns().clear();
    for(size_t i = 0; i < qtd; ++i)
    {
        std::string titulo; std::getline(in, titulo);
        double nota{}; in >> nota; in.ignore();
        Autor dummy{ "Desconhecido", {} };
        p.Albuns().GetAlbuns().emplace_back(titulo, dummy, 0, nota);
    }

    //watchlist
    in >> qtd; in.ignore();
    p.Watchlist().GetWatchlist().clear();
    for(size_t i = 0; i < qtd; ++i)
    {
        std::string titulo; std::getline(in, titulo);
        Autor dummy{ "Desconhecido", {} };
        p.Watchlist().GetWatchlist().emplace_back(titulo, dummy, 0);
    }
    return true;
}

