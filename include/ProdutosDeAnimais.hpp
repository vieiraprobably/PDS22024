#ifndef PRODUTOS_DE_ANIMAIS_HPP
#define PRODUTOS_DE_ANIMAIS_HPP

#include <string>

class ProdutosDeAnimais{

private:
    std::string nomeProduto;
    int quantidade;
    float preco;

public:
    ProdutosDeAnimais() {};
    ~ProdutosDeAnimais() {};

    void lerBancoDeDados(const std::string& ProdutosDeAnimais);
    void escreverBancoDeDados(const std::string& ProdutosDeAnimais);
    void definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco);
    void exibirProdutosDoBancoDeDados() const;
};

#endif