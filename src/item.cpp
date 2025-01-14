#include "item.hpp" 
#include <string>

class item{
    public:
    void imprimeProdutos(){}
    bool modificaUnidadeDe(std::string Nome, int quantia, bool mod){}
    item* encontraUnidade(std::string Nome){}
    item* criaUnidade(std::string Nome, int Quantidade, float Preco){}
    item* criaUnidade(std::string Nome, float Preco){}
};