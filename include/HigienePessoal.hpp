#ifndef HIGIENEPESSOAL_HPP
#define HIGIENEPESSOAL_HPP
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class HigienePessoal
{
private:
    std::string nome;
    int quantidade;
    float preco;
public:
    void removeUnidade(int quantia);
    int verQuantidadeDe(std::string Nome);
    float verPrecoDe(std::string Nome);
    HigienePessoal(std::string Nome);
    ~HigienePessoal();
};

class HigienePessoais
{
private:
    std::vector<HigienePessoais> higienepessoal;
public:
    HigienePessoal* criaUnidade(std::string Nome);
    HigienePessoal* encontraUnidade(std::string Nome);
    HigienePessoais();
    ~HigienePessoais();
};

#endif