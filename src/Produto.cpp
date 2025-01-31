#include <iostream>
#include <string>
#include "../include/Produto.hpp"
#include "../include/Fornecedor.hpp"
#include "../include/Categoria.hpp"
#include "../include/IProduto.hpp"


Produto::Produto()
{
}

Produto::~Produto()
{
}

int Produto::getId() const {
    return id;
}

std::string Produto::getNome() const {
    return nome;
}

Categoria* Produto::getCategoria() const {
    return categoria;
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
    std::cout << "\nFORNECEDOR: " << fornecedor-> getNomeDoFornecedor();     
    std::cout << "\nCATEGORIA: " << categoria-> getNomeDaCategoria() << "\n";
    std::cout <<"------------------\n";
}

