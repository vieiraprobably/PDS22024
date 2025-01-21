#ifndef MASSAS_HPP
#define MASSAS_HPP
#include "item.hpp"

class Massa : public item
{
private:
    std::string nome;
    int quantidade;
    float preco;
public:
    void modificaUnidade(int quantia);
    std::string verNome();
    int verQuantidade();
    float verPreco();
    Massa(std::string Nome, int Quantidade, float Preco);
    Massa(std::string Nome, float Preco);
    ~Massa();
};

class Massas //controlador de massas, quero generalizar para controlar todo o estoque
{
private:
    std::vector<Massa> massa;
public:
    Massa* criaUnidade(std::string Nome, float Preco);
    Massa* encontraUnidade(std::string Nome);
    bool modificaUnidadeDe(std::string Nome, int quantia, bool mod);
    Massas();
    ~Massas();
};
#endif
