#include "enlatados.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Enlatados::imprimeProdutos() {
    for (const auto& produto : produtos) {
        std::cout << "Produto: " << produto.nome << "\n";
        std::cout << "Quantidade: " << produto.quantidade << "\n";
        std::cout << "Preço: R$" << produto.preco << "\n";
        std::cout << "-------------------" << std::endl;
    }
}

bool Enlatados::modificaUnidadeDe(std::string Nome, int quantia, bool mod) {
    for (auto& produto : produtos) {
        if (produto.nome == Nome) {
            if (mod) {
                produto.quantidade += quantia;
            } else {
                if (produto.quantidade < quantia) {
                    return false;
                }
                produto.quantidade -= quantia;
            }
            return true;
        }
    }
    return false;
}

item* Enlatados::encontraUnidade(std::string Nome) {
    for (auto& produto : produtos) {
        if (produto.nome == Nome) {
            return this;
        }
    }
    return nullptr;
}

item* Enlatados::criaUnidade(std::string Nome, int Quantidade, float Preco) {
    if (!encontraUnidade(Nome)) {
        produtos.push_back({Nome, Quantidade, Preco});
    } else {
        modificaUnidadeDe(Nome, Quantidade, true);
    }
    return this;
}

item* Enlatados::criaUnidade(std::string Nome, float Preco) {
    if (!encontraUnidade(Nome)) {
        produtos.push_back({Nome, 0, Preco});
    }
    return this;
}

Enlatados::Enlatados() {
    std::ifstream bancoDeDados("../data/enlatados.txt");
    if (!bancoDeDados.is_open()) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return;
    }
    std::string nomeProduto, linha;
    int quantidade;
    float preco;
    while (std::getline(bancoDeDados, linha)) {
        std::istringstream stream(linha);
        std::getline(stream, nomeProduto, ' ');
        stream >> quantidade >> preco;
        criaUnidade(nomeProduto, quantidade, preco);
    }
    bancoDeDados.close();
}

Enlatados::~Enlatados() {
    std::remove("../data/enlatados.txt");
    std::ofstream bancoDeDados("../data/enlatados.txt");
    for (const auto& produto : produtos) {
        bancoDeDados << produto.nome << " " << produto.quantidade << " " << produto.preco << "\n";
    }
    bancoDeDados.close();
}
