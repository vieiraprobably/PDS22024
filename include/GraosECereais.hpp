#ifndef GRAOS_E_CEREAIS_HPP
#define GRAOS_E_CEREAIS_HPP

#include <string>

class GraosECereais{

private:
    std::string nomeProduto;
    int quantidade;
    float preco;

public:
    GraosECereais() {};
    ~GraosECereais() {};

    void lerBancoDeDados(const std::string& GraosECereais);
    void escreverBancoDeDados(const std::string& GraosECereais);
    void definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco);
    void exibirProdutosDoBancoDeDados() const;
};

#endif