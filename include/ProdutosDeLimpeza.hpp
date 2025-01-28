#ifndef PRODUTOSDEANIMAIS_HPP
#define PRODUTOSDEANIMAIS_HPP

#include <string>
#include <vector>
#include <iostream>
#include "item.hpp"


class ProdutoDeLimpeza{

private:
    std::string nomeProduto;
    int quantidade;
    float preco;

public:
    ProdutoDeLimpeza(const std::string& nome, int quant, float precoProduto);
    ProdutoDeLimpeza(const std::string& nome, float precoProduto);

    const std::string& getNomeProduto() const;
    int getQuantidade() const;
    float getPreco() const;

    void setQuantidade(int novaQuantidade);
    void setPreco(float novoPreco);

    void imprimeProduto() const;

};

class ProdutosDeLimpeza : public item {

private:
    std::vector<class ProdutoDeLimpeza> produtos;

public:
    ProdutosDeLimpeza(const std::string& caminhoBanco); 
    ~ProdutosDeLimpeza(); 

    void criarUnidade(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco);
    void encontraUnidade(const std::string& filePath, const std::string& nomeDoProdutoProcurado);
    void modificaUnidadeDe(const std::string& filePath, const std::string& nomeDoProdutoProcurado, int novaQuantidade);
    void imprimirProdutos();
};

#endif 