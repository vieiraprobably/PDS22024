#ifndef PRODUTO_DE_LIMPEZA_HPP
#define PRODUTO_DE_LIMPEZA_HPP

#include <string>

class ProdutosDeLimpeza{

private:
    std::string nomeProduto;
    int quantidade;
    float preco;

public:
    ProdutosDeLimpeza() {};
    ~ProdutosDeLimpeza() {};

    void lerBancoDeDados(const std::string& ProdutosDeLimpeza);
    void escreverBancoDeDados(const std::string& ProdutoDeLimpeza);
    void definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco);
    void exibirProdutosDoBancoDeDados() const;
};

#endif