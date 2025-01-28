#ifndef PRODUTOSDEANIMAIS_HPP
#define PRODUTOSDEANIMAIS_HPP

#include <string>
#include <vector>
#include <iostream>
#include "item.hpp"


// Classe ProdutoDeAnimal (encapsula os dados de um produto)
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

// Relação de herança entre item e ProdutosDeAnimais
class ProdutosDeAnimais : public item {

private:
    std::vector<class ProdutoDeAnimal> produtos; // Vetor de produtos

public:
    ProdutosDeAnimais(const std::string& caminhoBanco); // Construtor da classe ProdutosDeAnimais para inicializar o banco de dados
    ~ProdutosDeAnimais(); // Destrutor da classe ProdutosDeAnimais para fechar o banco de dados

    void criarUnidade(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco);
    void encontraUnidade(const std::string& filePath, const std::string& nomeDoProdutoProcurado);
    void modificaUnidadeDe(const std::string& filePath, const std::string& nomeDoProdutoProcurado, int novaQuantidade);
    void imprimirProdutos();
};

#endif // PRODUTOSDEANIMAIS_HPP