#include "FilaDeInteresses.h"
#include "Cores.h"
#include <algorithm>
#include <iostream>

/*-------------------------------------------------------------
  Adiciona álbum à fila (encaminha para o vetor herdado)
-------------------------------------------------------------*/
void FilaDeInteresses::Adicionar(const Album& a)
{
    albuns_.push_back(a);
}

/*-------------------------------------------------------------
  Remove álbum pelo título
-------------------------------------------------------------*/
void FilaDeInteresses::Remover(const std::string& titulo)
{
    auto it = std::find_if(albuns_.begin(), albuns_.end(),
                           [&](const Album& alb) { return alb.GetTitulo() == titulo; });

    if(it != albuns_.end())
    {
        albuns_.erase(it);
        std::cout << titulo << " removido com sucesso\n";
    }
    else
    {
        std::cout << titulo << " não encontrado.\n";
    }
}

/*-------------------------------------------------------------
  Exibe a fila em forma de “cartões”
-------------------------------------------------------------*/
void FilaDeInteresses::ListarQuadro(int porLinha, int largura) const
{
    /* alias: preserva o nome usado no código antigo */
    const auto& filaDeAlbum = albuns_;

    const int linhasPorAlbum = 8;
    const int larguraAlbum = 20;

    int totalAlbuns = static_cast<int>(filaDeAlbum.size());
    if(totalAlbuns == 0) return;

    int totalLinhas = (totalAlbuns + porLinha - 1) / porLinha;
    int linhasParaImprimir = std::max(1, totalLinhas);

    for(int blocoLinha = 0; blocoLinha < linhasParaImprimir; ++blocoLinha)
    {
        for(int linhaInterna = 0; linhaInterna < linhasPorAlbum; ++linhaInterna)
        {
            int ocupado = 0;

            for(int coluna = 0; coluna < porLinha; ++coluna)
            {
                int idx = blocoLinha * porLinha + coluna;

                if(idx < totalAlbuns)
                {
                    const Album& alb = filaDeAlbum[idx];

                    std::string titulo = alb.GetTitulo();
                    std::string artista = alb.GetAutor();
                    int notaInt = std::max(0, std::min(5, static_cast<int>(alb.GetNota())));

                    std::string estrelas(notaInt, '★');
                    estrelas.append(5 - notaInt, ' ');

                    if(static_cast<int>(titulo.size()) > 15) titulo = titulo.substr(0, 15);
                    if(static_cast<int>(artista.size()) > 15) artista = artista.substr(0, 15);

                    int espacoTitulo = std::max(0, larguraAlbum - 9 - static_cast<int>(titulo.size()));
                    int espacoArtista = std::max(0, larguraAlbum - 10 - static_cast<int>(artista.size()));
                    int espacoNota = std::max(0, larguraAlbum - 7 - 5);

                    switch(linhaInterna)
                    {
                        case 0: std::cout << corQuadrados << "   ╔═════════════╗   " << reset; break;
                        case 1: std::cout << corQuadrados << "   ║  W A T C H  ║   " << reset; break;
                        case 2: std::cout << corQuadrados << "   ╚═════════════╝   " << reset; break;
                        case 3: std::cout << corQuadrados << "   ■■ ▬▬ ■■ ▬▬   " << reset; break;
                        case 4:
                            std::cout << corQuadrados << "  Título: " << "\033[1;32m"
                                << titulo << std::string(espacoTitulo, ' ') << reset;
                            break;
                        case 5:
                            std::cout << corQuadrados << "  Artista: " << "\033[1;34m"
                                << artista << std::string(espacoArtista, ' ') << reset;
                            break;
                        case 6:
                            std::cout << corQuadrados << "  Nota: " << "\033[1;33m"
                                << estrelas << std::string(espacoNota, ' ') << reset;
                            break;
                        case 7:
                            std::cout << std::string(larguraAlbum, ' ');
                            break;
                    }

                    ocupado += larguraAlbum + 2;
                    std::cout << "  ";
                }
                else
                {
                    std::cout << std::string(larguraAlbum, ' ') << "  ";
                    ocupado += larguraAlbum + 2;
                }
            }
            std::cout << std::string(std::max(0, largura - ocupado), ' ') << '\n';
        }
    }
}
