#ifndef PRODUTO_HPP
#define PRODUTO_HPP

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
    Produto(const int id, std::string& nome, Categoria* categoria, int quantidade, float preco, Fornecedor* fornecedor);;  // Construtor parametrizado
    ~Produto(); 
    int getId() const;
    std::string getNome() const;
    Categoria* getCategoria() const;
    int getQuantidade() const;
    float getPreco() const;
    Fornecedor* getFornecedor() const;

    void setId(int id);
    void setNome(const std::string& nome);
    void setCategoria(Categoria* categoria);
    void setQuantidade(int quantidade);
    void setPreco(float preco);
    void setFornecedor(Fornecedor* fornecedor);

    void exibirProduto() const;
};

#endif 
