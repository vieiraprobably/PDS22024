#include <iostream>
#include <string>
#include "Categoria.cpp"

class Produto {
protected:
    int id;
    std::string nome;
    Categoria categoria;
    float precoUnitario;
    int quantidadeEstoque;

public:
    Produto(int id, const std::string& nome, Categoria categoria, float precoUnitario, int quantidadeEstoque)
        : id(id), nome(nome), categoria(categoria), precoUnitario(precoUnitario), quantidadeEstoque(quantidadeEstoque) {}

    int getId() const { return id; }
    std::string getNome() const { return nome; }
    Categoria getCategoria() const { return categoria; }
    float getPrecoUnitario() const { return precoUnitario; }
    int getQuantidadeEstoque() const { return quantidadeEstoque; }

    void setPrecoUnitario(float novoPreco) { precoUnitario = novoPreco; }
    void setQuantidadeEstoque(int novaQuantidade) { quantidadeEstoque = novaQuantidade; }

    virtual void atualizarEstoque(int quantidade) = 0;

    virtual ~Produto() = default;
};