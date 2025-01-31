#ifndef LATICINIOS_HPP
#define LATICINIOS_HPP

#include <string>

class Laticinios{

private:
    std::string nomeProduto;
    int quantidade;
    float preco;

public:
    Laticinios() {};
    ~Laticinios() {};

    void lerBancoDeDados(const std::string& Laticinios);
    void escreverBancoDeDados(const std::string& Laticinios);
    void definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco);
    void exibirProdutosDoBancoDeDados() const;
};

#endif