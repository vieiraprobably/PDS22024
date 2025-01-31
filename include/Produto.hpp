#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
#include <string>
#include "Fornecedor.hpp"
#include "Categoria.hpp"
#include "IProduto.hpp"

class Produto : public IProduto { 
private:
    int id;
    std::string nome;
    Categoria* categoria;
    int quantidade;
    float preco;
    Fornecedor* fornecedor;

public:
    Produto();
    ~Produto();

    int getId() const;
    std::string getNome() const;
    Categoria* getCategoria() const;
    int getQuantidade() const;
    float getPreco() const;
    Fornecedor* getFornecedor() const;

    void setId(int id);
    void setNome(const std::string& n);
    void setCategoria(Categoria* c);
    void setQuantidade(int qtd);
    void setPreco(float p);
    void setFornecedor(Fornecedor* f);

    void exibirProduto() const;
};

#endif // PRODUTO_HPP
