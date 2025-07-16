#include "Perfil.h"

#include "ColecaoAlbuns.h"   // classebase abstrata
#include "Cores.h"          
#include <iostream>
#include <sstream>
#include <array>

using namespace std;

void Perfil::MostrarPerfil() const
{
    const int larguraQuadro = 52;

   
    cout << '\n' << corQuadrados
        << "═══■════■════■════■════■════■════■════■════■═══\n"
        << "     ✦✧✦ PERFIL DO USUÁRIO ✦✧✦\n"
        << "═══■════■════■════■════■════■════■════■════■═══\n";

  
    vector<string> linhasCabeca;
    istringstream avatarStream(cabeca_);
    string linha;
    while(getline(avatarStream, linha))
        linhasCabeca.push_back(linha);

    
    while(linhasCabeca.size() < 3) linhasCabeca.push_back("       ");

    for(int i = 0; i < 3; ++i)
    {
        string parte = linhasCabeca[i];
        parte.resize(7, ' ');                        
        cout << "  " << parte << "  ";

        if(i == 1)
        {
            int espacos = larguraQuadro - 7 - 4 - static_cast<int>(nome_.length());
            int esq = espacos / 2;
            int dir = espacos - esq;
            cout << string(esq, ' ') << nome_ << string(dir, ' ');
        }
        else
        {
            cout << string(larguraQuadro - 7 - 4, ' ');
        }
        cout << '\n';
    }

    cout << corQuadrados
        << "═══■════■════■════■════■════■════■════■════■═══\n"
        << reset;

  
    array<const ColecaoAlbuns*, 2> colecoes = { &albunsOuvidos_, &filaDeInteresses_ };
    array<const char*, 2> titulos = { "Meus álbuns avaliados:", "Minha Watchlist:" };
    array<const char*, 2> vazios = { "Nenhum álbum avaliado.", "Nenhuma Watchlist cadastrada." };

    for(size_t i = 0; i < colecoes.size(); ++i)
    {
        const auto* col = colecoes[i];

        if(col->Empty())
        {
            cout << vazios[i] << '\n';
        }
        else
        {
            cout << titulos[i] << "\n\n";
            col->ListarQuadro(5, larguraQuadro);   
        }

        
        if(i + 1 < colecoes.size())
            cout << corQuadrados
            << "═══■════■════■════■════■════■════■════■════■═══\n"
            << reset;
    }

   
    cout << corQuadrados
        << "═══■════■════■════■════■════■════■════■════■═══\n"
        << reset;
}
