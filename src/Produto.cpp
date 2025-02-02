#include "../include/Produto.hpp"
#include <iostream>

Produto::Produto() : id(0), nome(""), categoria(nullptr), quantidade(0), preco(0.0), fornecedor(nullptr) {}

Produto::Produto(const int id, std::string& nome, Categoria* categoria, int quantidade, float preco, Fornecedor* fornecedor)
    : id(id), nome(nome), categoria(categoria), quantidade(quantidade), preco(preco), fornecedor(fornecedor) {}

Produto::~Produto() {}

int Produto::getId() const {
    return id;
}

std::string Produto::getNome() const {
    return nome;
}

Categoria* Produto::getCategoria() const {
    return categoria.nome;
}

int Produto::getQuantidade() const {
    return quantidade;
}

float Produto::getPreco() const {
    return preco;
}

Fornecedor* Produto::getFornecedor() const {
    return fornecedor;
}

void Produto::setId(int id){
    this->id = id; 
}

void Produto::setNome(const std::string& n) {
    nome = n;
}

void Produto::setCategoria(Categoria* c) {
    categoria = c;
}

void Produto::setQuantidade(int qtd) {
    quantidade = qtd;
}

void Produto::setPreco(float p) {
    preco = p;
}

void Produto::setFornecedor(Fornecedor* f) {
    fornecedor = f;
}

void Produto::exibirProduto() const {
    std::cout << "ID: " << id << "\n";
    std::cout << "NOME: " << nome << "\n";
    std::cout << "QUANTIDADE: " << quantidade << "\n";
    std::cout << "PREÇO: R$ " << preco << "\n";
    std::cout << "\nFORNECEDOR: " << fornecedor-> getNome();     
    std::cout << "\nCATEGORIA: " << categoria-> getNome() << "\n";
    std::cout <<"------------------\n";
}