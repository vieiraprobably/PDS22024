#ifndef PRODUTOSDEANIMAIS_HPP
#define PRODUTOSDEANIMAIS_HPP

#include <string>
#include <vector>
#include <iostream>
#include "item.hpp"


class ProdutoDeAnimal {

private:
    std::string nomeProduto;
    int quantidade;
    float preco;

public:
    ProdutoDeAnimal(const std::string& nome, int quant, float precoProduto);
    ProdutoDeAnimal(const std::string& nome, float precoProduto);

    const std::string& getNomeProduto() const;
    int getQuantidade() const;
    float getPreco() const;

    void setQuantidade(int novaQuantidade);
    void setPreco(float novoPreco);

    void imprimeProduto() const;

};

class ProdutosDeAnimais : public item {

private:
    std::vector<class ProdutoDeAnimal> produtos; 

public:
    ProdutosDeAnimais(const std::string& caminhoBanco); 
    ~ProdutosDeAnimais(); 

    void criarUnidade(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco);
    void encontraUnidade(const std::string& filePath, const std::string& nomeDoProdutoProcurado);
    void modificaUnidadeDe(const std::string& filePath, const std::string& nomeDoProdutoProcurado, int novaQuantidade);
    void imprimirProdutos();
};

#endif
