#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "../include/Fornecedor.hpp"

// Construtor
 Fornecedor::Fornecedor(int id, const std::string& n, const std::string& c, const std::string& e)
        : fornecedorId(id), nome(n), contato(c), endereco(e) {}


// Destrutor
Fornecedor::~Fornecedor() {}

// Getters
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

// Setters

void Fornecedor::setId(int i) {
    fornecedorId = i;
}

void Fornecedor::setNome(string n) {
    nome = n;
}

void Fornecedor::setContato(string c) {
    contato = c;
}

void Fornecedor::setEndereco(float e) {
    endereco = e;
}

void Fornecedor::setProdutos(vector<Produto*> p) {
    produtos = p;
}

// Função para adicionar fornecedor
void Fornecedor::adicionarFornecedor(int i, string n, string c, float e) {
    fornecedorId = i;
    nome = n;
    contato = c;
    endereco = e;
}

// Função para atualizar fornecedor
void Fornecedor::atualizarFornecedor(int i, string n, string c, float e) {
    fornecedorId = i;
    nome = n;
    contato = c;
    endereco = e;
}

// Função para listar fornecedores
void Fornecedor::listarFornecedores() {
    
}

// Função para listar produtos por fornecedor
void Fornecedor::listarProdutosPorFornecedor() {

}

// Função para exibir as informações do fornecedor
void exibirFornecedor() {
    cout << "ID: " << fornecedorId << endl;
    cout << "Nome: " << nome << endl;
    cout << "Contato: " << contato << endl;
    cout << "Endereço: " << endereco << endl;
}

