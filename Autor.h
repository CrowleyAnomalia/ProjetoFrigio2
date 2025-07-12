#pragma once
#include <string>
#include <vector>

class Album;           
class Autor
{    
    std::string nome;
    std::vector<Album*> albuns;   
    public: 
          Autor() : nome("Desconhecido") {}
          Autor(std::string nome)
          {
              this->nome = nome;
          }
         
          Autor(std::string nome, std::vector<Album*> albuns)
          {
              this->nome = nome;
              this->albuns = albuns;

          }
          const std::string GetNome() const;

            
};
