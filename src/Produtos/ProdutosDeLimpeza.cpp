#include "../include/ProdutosDeLimpeza.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>


ProdutoDeLimpeza::ProdutoDeLimpeza(const std::string& nome, int quant, float precoProduto)
    : nomeProduto(nome), quantidade(quant), preco(precoProduto) {}

ProdutoDeLimpeza::ProdutoDeLimpeza(const std::string& nome, float precoProduto)
    : nomeProduto(nome), quantidade(0), preco(precoProduto) {}

const std::string& ProdutoDeLimpeza::getNomeProduto() const {
    return nomeProduto;
}

int ProdutoDeLimpeza::getQuantidade() const {
    return quantidade;
}

float ProdutoDeLimpeza::getPreco() const {
    return preco;
}

void ProdutoDeLimpeza::setQuantidade(int novaQuantidade) {
    quantidade = novaQuantidade;
}

void ProdutoDeLimpeza::setPreco(float novoPreco) {
    preco = novoPreco;
}

void ProdutoDeLimpeza::imprimeProduto() const {
    std::cout << "Produto: " << nomeProduto << "\n";
    std::cout << "Quantidade: " << quantidade << "\n";
    std::cout << "Preço: R$" << preco << "\n";
    std::cout << "-------------------" << std::endl;
}

ProdutosDeLimpeza::ProdutosDeLimpeza(const std::string& caminhoBanco) {
    std::ifstream bancoDeDados(caminhoBanco);
    if (!bancoDeDados.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoBanco << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(bancoDeDados, linha)) {
        std::istringstream stream(linha);
        std::string nomeProduto;
        int quantidade;
        float preco;
        stream >> nomeProduto >> quantidade >> preco;
        produtos.emplace_back(nomeProduto, quantidade, preco);
    }
    bancoDeDados.close();
}

ProdutosDeLimpeza::~ProdutosDeLimpeza() {
    std::ofstream bancoDeDados("../data/ProdutosDeLimpeza.txt");
    if (!bancoDeDados.is_open()) {
        std::cerr << "Erro ao salvar o arquivo: ../data/ProdutosDeLimpeza.txt" << std::endl;
        return;
    }
    for (const auto& produto : produtos) {
        bancoDeDados << produto.getNomeProduto() << " " << produto.getQuantidade() << " " << produto.getPreco() << "\n";
    }
    bancoDeDados.close();
}

void ProdutosDeLimpeza::criarUnidade(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco) {
    for (auto& produto : produtos) {
        if (produto.getNomeProduto() == nomeNovoProduto) {
            produto.setQuantidade(novaQuantidade);
            produto.setPreco(novoPreco);
            return;
        }
    }
    produtos.emplace_back(nomeNovoProduto, novaQuantidade, novoPreco);
}

void ProdutosDeLimpeza::encontraUnidade(const std::string& filePath, const std::string& nomeDoProdutoProcurado) {
    std::ifstream bancoDeDados(filePath);
    if (!bancoDeDados.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filePath << std::endl;
        return;
    }

    std::string linha;
    bool produtoEncontrado = false;
    while (std::getline(bancoDeDados, linha)) {
        std::istringstream stream(linha);
        std::string nomeProduto;
        int quantidade;
        float preco;
        stream >> nomeProduto >> quantidade >> preco;

        if (nomeProduto == nomeDoProdutoProcurado) {
            ProdutoDeLimpeza produto(nomeProduto, quantidade, preco);
            std::cout << "Produto encontrado" << "\n";
            std::cout << "------------------" << "\n";

            produto.imprimeProduto();

            produtoEncontrado = true;
            break;
        }
    }

    if (!produtoEncontrado) {
        std::cout << "Produto " << nomeDoProdutoProcurado << " não foi encontrado" << std::endl;
    }

    bancoDeDados.close();
}

void ProdutosDeLimpeza::modificaUnidadeDe(const std::string& filePath, const std::string& nomeDoProdutoProcurado, int novaQuantidade) {
    std::ifstream bancoDeDadosLeitura(filePath);
    if (!bancoDeDadosLeitura.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura: " << filePath << std::endl;
        return;
    }

    std::vector<ProdutoDeLimpeza> produtosTemp;
    std::string linha;
    bool produtoEncontrado = false;

    while (std::getline(bancoDeDadosLeitura, linha)) {
        std::istringstream stream(linha);
        std::string nomeProduto;
        int quantidade;
        stream >> nomeProduto >> quantidade;
        produtosTemp.emplace_back(nomeProduto, quantidade);
    }
    bancoDeDadosLeitura.close();

    for (auto& produto : produtosTemp) {
        if (produto.getNomeProduto() == nomeDoProdutoProcurado) {
            produto.setQuantidade(novaQuantidade);
            produtoEncontrado = true;
            break;
        }
    }

    if (!produtoEncontrado) {
        std::cerr << "Produto " << nomeDoProdutoProcurado << " não encontrado no banco de dados." << std::endl;
        return;
    }

    std::ofstream bancoDeDadosEscrita(filePath);
    if (!bancoDeDadosEscrita.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita: " << filePath << std::endl;
        return;
    }

    for (const auto& produto : produtosTemp) {
        bancoDeDadosEscrita << produto.getNomeProduto() << " " << produto.getQuantidade() << "\n";
    }

        std::cout << "Produto atualizado com sucesso!" << std::endl;
        bancoDeDadosEscrita.close();
    }

void ProdutosDeLimpeza::imprimirProdutos() {
    for (const auto& produto : produtos) {
        produto.imprimeProduto();
    }
}
