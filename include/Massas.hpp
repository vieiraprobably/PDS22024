#ifndef MASSAS_HPP
#define MASSAS_HPP
#include "item.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class Massa : public item
{
private:
    std::string nome;
    int quantidade;
    float preco;
public:
    void removeUnidade(int quantia);
    int verQuantidadeDe(std::string Nome);
    float verPrecoDe(std::string Nome);
    Massa(std::string Nome);
    ~Massa();
};

class Massas
{
private:
    std::vector<Massa> massa;
public:
    Massa* criaUnidade(std::string Nome);
    Massa* encontraUnidade(std::string Nome);
    Massas();
    ~Massas();
};

#endif