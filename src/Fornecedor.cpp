#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "../include/Fornecedor.hpp"


 Fornecedor::Fornecedor(int id, const std::string& n, const std::string& c, const std::string& e)
        : fornecedorId(id), nome(n), contato(c), endereco(e) {}



Fornecedor::~Fornecedor() {}


int Fornecedor::getId() const {
    return fornecedorId;
}

string Fornecedor::getNome() const {
    return nome;
}

string Fornecedor::getContato() const {
    return contato;
}

string Fornecedor::getEndereco() const {
    return endereco;
}

vector<Produto*> Fornecedor::getProdutos() const {
    return produtos;
}

vector<int> Fornecedor::getCategoriasAssociadas() const {
    return categoriasAssociadas;
}



void Fornecedor::setId(int i) {
    fornecedorId = i;
}

void Fornecedor::setNome(const std::string& n) {
    nome = n;
}

void Fornecedor::setContato(const std::string& c) {
    contato = c;
}

void Fornecedor::setEndereco(const std::string& e) {
    endereco = e;
}

void Fornecedor::setProdutos(const std::vector<Produto*>& p) {
    produtos = p;
}



