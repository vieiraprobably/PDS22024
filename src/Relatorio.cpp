#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

struct Produto {
    int id;
    std::string nome;
    int quantidade;
    double preco;
    std::string fornecedor;
};

void lerCSV(const std::string& nomeArquivo, std::vector<Produto>& produtos) {
    std::ifstream arquivo(nomeArquivo);
    std::string linha;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return;
    }

    // Ignora a primeira linha (cabeçalho)
    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;
        Produto produto;

        std::getline(ss, campo, ',');
        produto.id = campo.empty() ? 0 : std::stoi(campo);

        if (ss.peek() == '"') {
            ss.ignore();
            std::getline(ss, produto.nome, '"');
            ss.ignore(); // Ignorar a vírgula seguinte
        } else {
            std::getline(ss, produto.nome, ',');
        }

        std::getline(ss, campo, ',');
        produto.quantidade = campo.empty() ? 0 : std::stoi(campo);

        std::getline(ss, campo, ',');
        produto.preco = campo.empty() ? 0.0 : std::stod(campo);

        if (ss.peek() == '"') {
            ss.ignore();
            std::getline(ss, produto.fornecedor, '"');
        } else {
            std::getline(ss, produto.fornecedor, ',');
        }

        produtos.push_back(produto);
    }

    arquivo.close();
}

void gerarRelatorio(const std::string& categoria, const std::vector<Produto>& produtos, int& totalQuantidade, double& totalValor) {
    int quantidadeTotal = 0;
    double valorTotal = 0.0;

    for (const auto& produto : produtos) {
        quantidadeTotal += produto.quantidade;
        valorTotal += produto.quantidade * produto.preco;
    }

    totalQuantidade += quantidadeTotal;
    totalValor += valorTotal;

    std::cout << std::left << std::setw(20) << categoria << " | "
              << std::setw(16) << quantidadeTotal << " | "
              << std::fixed << std::setprecision(2) << valorTotal << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
}

int main() {
    std::vector<std::pair<std::string, std::string>> arquivos = {
        {"\data\estoque\Enlatados.csv", "Enlatados"},
        {"\data\estoque\Carnes.csv", "Carnes"},
        {"\data\estoque\Frutas.csv", "Frutas"},
        {"\data\estoque\GraosECereais.csv", "Grãos e Cereais"},
        {"\data\estoque\Animais.csv", "Animais"},
        {"\data\estoque\Bebidas.csv", "Bebidas"},
        {"\data\estoque\Verduras.csv", "Verduras"},
        {"\data\estoque\HigienePessoal.csv", "Higiene Pessoal"},
        {"\data\estoque\Limpeza.csv", "Limpeza"},
        {"\data\estoque\Padaria.csv", "Padaria"},
        {"\data\estoque\Massas.csv", "Massas"},
        {"\data\estoque\Laticinios.csv", "Laticinios"}
    };

    int totalQuantidadeGeral = 0;
    double totalValorGeral = 0.0;

    std::cout << "Relatório do Estoque" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Categoria             | Quantidade Total | Valor Total (R$)" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    for (const auto& arquivo : arquivos) {
        std::vector<Produto> produtos;
        lerCSV(arquivo.first, produtos);
        gerarRelatorio(arquivo.second, produtos, totalQuantidadeGeral, totalValorGeral);
    }

    std::cout << "\nTotal Geral do Estoque:" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Quantidade Total: " << totalQuantidadeGeral << std::endl;
    std::cout << "Valor Total (R$): " << std::fixed << std::setprecision(2) << totalValorGeral << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    return 0;
}
