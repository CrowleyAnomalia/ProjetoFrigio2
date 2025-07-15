#include "Menu.h"
#include "Cores.h"
#include "Plataforma.h"
#include "ServicosPerfil.h"
#include "Animacao.h"
#include <iostream>
#include <string>

using namespace std;

void Menu::showMenu(size_t selected)
{
    const int largura = 44; // Largura entre as bordas
    string options[] = {
        "Criar Perfil",
        "Adicionar Album",
        "Remover Album",
        "Ver Perfil e Albuns",
        "Adicionar a Watchlist",
        "Gerenciar Favoritos",   // <<-- novo
        "Alterar Cores",
        "Sair"
    };
    size_t n = sizeof(options) / sizeof(options[0]);

    limparTela();
    cout << corMenu;
    cout << "\n✧･ﾟ: *✧･ﾟ:* MENU *:･ﾟ✧*:･ﾟ✧\n\n";

    for(size_t i = 0; i < n; ++i)
    {
        if(i == selected)
        {
            cout << "\033[1;30m▸ " << options[i] << "\033[0m\n";
        }
        else
        {
            cout << "  " << options[i] << "\n";
        }
    }

    cout << "\n⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆\n";
    cout << "\033[0m"; // Resetar cores
}

void Menu::menuUsuario()
{
    Perfil u;
    carregarPerfil(u);

    size_t selected = 0;
    const size_t max_options = 8; // agora são 8 opções
    bool sair = false;

    while(!sair)
    {
        Menu::showMenu(selected);
        int key = getKey();

        #ifdef _WIN32
        if(key == 72)           // seta pra cima
            selected = (selected + max_options - 1) % max_options;
        else if(key == 80)      // seta pra baixo
            selected = (selected + 1) % max_options;
        else if(key == 13)      // Enter
            #else
        if(key == 'U')          // seta pra cima
            selected = (selected + max_options - 1) % max_options;
        else if(key == 'D')     // seta pra baixo
            selected = (selected + 1) % max_options;
        else if(key == '\n')    // Enter
            #endif
        {
            switch(selected)
            {
                case 0:
                    {
                        std::string novo;
                        std::cout << "Nome: ";
                        std::getline(std::cin, novo);
                        u.SetNome(std::move(novo));

                        // Cada cabecinha dividida em 3 linhas
                        std::vector<std::vector<std::string>> cabecas = {
                            { " _|#|_", " |(o)|", " ----- " },
                            { "  ___ ", " (o o)", " (___)" },
                            { " ^   ^", " (o o)", "  \\_/ " },
                            { " \\___/", " (o o)", " ( v )" },
                            { " .-.  ", "(o o) ", " \\_/  " },
                            { "[|||] ", "( o ) ", " \\_/  " },
                            { " /^^\\ ", "( O O)", " \\_-_/" },
                            { "^\\  /^", "( o o)", "  \\_/ " },
                            { "=^_^= ", "(o o )", "(\\\")(\\\")" },
                            { " .---.", "| o o |", " \\_^_/ " }
                        };

                        std::cout << "\nEscolha seu avatar:\n";

                        for(int linhaGrupo = 0; linhaGrupo < 2; ++linhaGrupo)
                        {
                            for(int linha = 0; linha < 3; ++linha)
                            {
                                for(int col = 0; col < 5; ++col)
                                {
                                    std::cout << "  " << cabecas[linhaGrupo * 5 + col][linha] << "   ";
                                }
                                std::cout << "\n";
                            }

                            for(int col = 0; col < 5; ++col)
                            {
                                int idx = linhaGrupo * 5 + col + 1;
                                std::cout << "   [" << idx << "]     ";
                            }
                            std::cout << "\n\n";
                        }

                        int escolha = 0;
                        do
                        {
                            std::cout << "Digite o número do avatar escolhido (1-10): ";
                            std::cin >> escolha;
                            std::cin.ignore();
                        }
                        while(escolha < 1 || escolha > 10);

                        std::string avatarSelecionado;
                        for(const std::string& linha : cabecas[escolha - 1])
                            avatarSelecionado += linha + "\n";

                        u.SetCabeca(avatarSelecionado); // Supondo que existe esse setter

                        salvarPerfil(u);

                        std::cout << "\n✅ Perfil criado com sucesso!\n";
                        std::cout << "Pressione Enter para continuar...";
                        std::cin.ignore();
                        break;
                    }

                case 1:   //Adicionar Album
                    {
                        std::string titulo, nomeAutor;
                        double nota;
                        int anoLancamento;

                        std::cout << "Título: ";
                        std::getline(std::cin, titulo);

                        std::cout << "Nome do artista: ";
                        std::getline(std::cin, nomeAutor);

                        std::cout << "Nota (0-5): ";
                        std::cin >> nota;
                        std::cin.ignore();

                        Autor autor{ nomeAutor, {} };
                        // anoLancamento não foi lido antes — adicione a leitura:
                        std::cout << "Ano de lançamento: ";
                        std::cin >> anoLancamento;
                        std::cin.ignore();

                        u.Albuns().GetAlbuns().emplace_back(titulo, autor, anoLancamento, nota);
                        salvarPerfil(u);

                        std::cout << "\n✅ Álbum \"" << titulo << "\" do artista \"" << nomeAutor << "\" adicionado com sucesso!\n";
                        std::cout << "Pressione Enter para continuar...";
                        std::cin.ignore();

                        break;
                    }

                case 2: //Remover Album
                    {
                        std::cout << "De qual lista você deseja remover o álbum?\n";
                        std::cout << "1. Álbum Ouvido\n";
                        std::cout << "2. Watchlist\n";
                        std::cout << "Escolha (0 para cancelar): ";
                        int escolha;
                        std::cin >> escolha;
                        std::cin.ignore();

                        if(escolha == 1)
                        {
                            auto& lista = u.Albuns().GetAlbuns();
                            if(lista.empty())
                            {
                                std::cout << "Nenhum álbum ouvido.\nPressione Enter...";
                                std::cin.ignore();
                                break;
                            }

                            std::cout << "\nÁlbuns Ouvidos:\n";
                            for(size_t i = 0; i < lista.size(); ++i)
                                std::cout << i + 1 << ". " << lista[i].GetTitulo()
                                << " (" << lista[i].GetNota() << ")\n";

                            std::cout << "Número para remover (0 cancela): ";
                            int idxInput;
                            std::cin >> idxInput;
                            std::cin.ignore();

                            if(idxInput > 0 && idxInput <= (int)lista.size())
                            {
                                lista.erase(lista.begin() + (idxInput - 1));
                                salvarPerfil(u);
                                std::cout << "Álbum removido da lista de ouvidos.\n";
                            }
                            else
                            {
                                std::cout << "Índice fora do intervalo.\n";
                            }
                        }
                        else if(escolha == 2)
                        {
                            auto& watchlist = u.Watchlist().GetWatchlist();
                            if(watchlist.empty())
                            {
                                std::cout << "Nenhum álbum na Watchlist.\nPressione Enter...";
                                std::cin.ignore();
                                break;
                            }

                            std::cout << "\nWatchlist:\n";
                            for(size_t i = 0; i < watchlist.size(); ++i)
                                std::cout << i + 1 << ". " << watchlist[i].GetTitulo() << "\n";

                            std::cout << "Número para remover (0 cancela): ";
                            int idxInput;
                            std::cin >> idxInput;
                            std::cin.ignore();

                            if(idxInput > 0 && idxInput <= (int)watchlist.size())
                            {
                                watchlist.erase(watchlist.begin() + (idxInput - 1));
                                salvarPerfil(u);
                                std::cout << "Álbum removido da Watchlist.\n";
                            }
                            else
                            {
                                std::cout << "Índice fora do intervalo.\n";
                            }
                        }
                        else
                        {
                            std::cout << "Operação cancelada.\n";
                        }

                        break;
                    }

                case 3: //Ver Perfil e Albuns
                    {
                        limparTela();
                        u.MostrarPerfil();
                        std::cout << "Enter para seguir…";
                        std::cin.ignore();
                        break;
                    }

                case 4: //Adicionar à Watchlist
                    {
                        std::string titulo, nomeAutor;

                        std::cout << "Título: ";
                        std::getline(std::cin >> std::ws, titulo);

                        std::cout << "Nome do artista: ";
                        std::getline(std::cin, nomeAutor);

                        Autor autor{ nomeAutor, {} };
                        u.Watchlist().GetWatchlist().emplace_back(titulo, autor, 0, 0.0);
                        salvarPerfil(u);

                        std::cout << "\n✅ Álbum \"" << titulo << "\" do artista \"" << nomeAutor << "\" adicionado à Watchlist com sucesso!\n";
                        std::cout << "Pressione Enter para continuar...";
                        std::cin.ignore();
                        break;
                    }

                case 5: //Gerenciar Favoritos
                    {
                        std::cout << "O que deseja fazer com os Favoritos?\n";
                        std::cout << " 1. Adicionar Favorito\n";
                        std::cout << " 2. Remover Favorito\n";
                        std::cout << " 3. Editar Favorito\n";
                        std::cout << " 4. Listar Favoritos\n";
                        std::cout << " 0. Cancelar\n";
                        std::cout << "Escolha: ";
                        int opt;
                        std::cin >> opt;
                        std::cin.ignore();

                        if(opt == 1)
                        {
                            std::string titulo, nomeAutor;
                            int anoLancamento;
                            double nota;

                            std::cout << "Título: ";
                            std::getline(std::cin, titulo);
                            std::cout << "Nome do artista: ";
                            std::getline(std::cin, nomeAutor);
                            std::cout << "Ano: ";
                            std::cin >> anoLancamento; std::cin.ignore();
                            std::cout << "Nota (0-5): ";
                            std::cin >> nota; std::cin.ignore();

                            Autor autor{ nomeAutor, {} };
                            Album alb{ titulo, autor, anoLancamento, nota };
                            u.FavoritosColecao().Adicionar(alb);
                            salvarPerfil(u);

                        }
                        else if(opt == 2)
                        {
                            std::cout << "Informe o título a remover: ";
                            std::string t;
                            std::getline(std::cin, t);
                            u.FavoritosColecao().Remover(t);
                            salvarPerfil(u);

                        }
                        else if(opt == 3)
                        {
                            std::cout << "Título atual: ";
                            std::string oldT;
                            std::getline(std::cin, oldT);

                            std::string novoTitulo, novoAutor;
                            int novoAno;
                            double novaNota;
                            std::cout << "Novo título: ";
                            std::getline(std::cin, novoTitulo);
                            std::cout << "Novo artista: ";
                            std::getline(std::cin, novoAutor);
                            std::cout << "Novo ano: ";
                            std::cin >> novoAno; std::cin.ignore();
                            std::cout << "Nova nota (0-5): ";
                            std::cin >> novaNota; std::cin.ignore();

                            Autor autorEdit{ novoAutor, {} };
                            Album albEdit{ novoTitulo, autorEdit, novoAno, novaNota };
                            u.FavoritosColecao().Editar(oldT, albEdit);
                            salvarPerfil(u);

                        }
                        else if(opt == 4)
                        {
                            u.FavoritosColecao().Listar();
                            std::cout << "Pressione Enter para continuar...";
                            std::cin.ignore();
                        }
                        // opt == 0 ou inválido: volta ao menu
                        break;
                    }

                case 6:
                    alterarCores();
                    break;

                case 7:
                    mostrarAnimacao();
                    sair = true;
                    break;
            }
        }
    }
}
