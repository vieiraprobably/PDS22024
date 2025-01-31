#include "padaria.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Padaria::imprimeProdutos() {
    for (const auto& produto : produtos) {
        std::cout << "Produto: " << produto.nome << "\n"
                  << "Quantidade: " << produto.quantidade << "\n"
                  << "Preço: R$" << produto.preco << "\n"
                  << "-------------------" << std::endl;
    }
}

bool Padaria::modificaUnidadeDe(std::string Nome, int quantia, bool mod) {
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

item* Padaria::encontraUnidade(std::string Nome) {
    for (auto& produto : produtos) {
        if (produto.nome == Nome) {
            return this;
        }
    }
    return nullptr;
}

item* Padaria::criaUnidade(std::string Nome, int Quantidade, float Preco) {
    if (!encontraUnidade(Nome)) {
        produtos.push_back({Nome, Quantidade, Preco});
    } else {
        modificaUnidadeDe(Nome, Quantidade, true);
    }
    return this;
}

item* Padaria::criaUnidade(std::string Nome, float Preco) {
    if (!encontraUnidade(Nome)) {
        produtos.push_back({Nome, 0, Preco});
    }
    return this;
}

Padaria::Padaria() {
    std::ifstream bancoDeDados("../data/padaria.txt");
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

Padaria::~Padaria() {
    std::remove("../data/padaria.txt");

    std::ofstream bancoDeDados("../data/padaria.txt");
    for (const auto& produto : produtos) {
        bancoDeDados << produto.nome << " " << produto.quantidade << " " << produto.preco << "\n";
    }
    bancoDeDados.close();
}
