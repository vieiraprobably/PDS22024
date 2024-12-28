#ifndef MASSAS_HPP
#define MASSAS_HPP
#include <string>
#include <iostream>

class Massas
{
private:
    std::string nome;
    int quantidade;
    float preco;
public:
    void adicionaUnidade(int quantia);
    void removeUnidade(int quantia);
    int verQuantidade();
    float verPreco();
    Massas(std::string Nome);
    ~Massas();
};

Massas::Massas(std::string Nome)
{
    this->nome=Nome;
}

Massas::~Massas()
{
}


#endif
