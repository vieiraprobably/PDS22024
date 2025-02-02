#include "PersistenciaDeDados.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

PersistenciaDeDados::PersistenciaDeDados() {
    arquivosCSV = {
        {"Animais", "Animais.csv"},
        {"Bebidas", "Bebidas.csv"},
        {"Carnes", "Carnes.csv"},
        {"Enlatados", "Enlatados.csv"},
        {"Frutas", "Frutas.csv"},
        {"GraosECereais", "GraosECereais.csv"},
        {"HigienePessoal", "HigienePessoal.csv"},
        {"Laticinios", "Laticinios.csv"},
        {"Limpeza", "Limpeza.csv"},
        {"Massas", "Massas.csv"},
        {"Padaria", "Padaria.csv"},
        {"Verduras", "Verduras.csv"}
    };
}

void PersistenciaDeDados::salvarDados() {
    for (const auto& [categoria, arquivo] : arquivosCSV) {
        
        std::vector<std::tuple<int, std::string, int, double, std::string>> dados = {
            {40001, "Alface", 5000, 0.5, "Brasil Fartura Comercio Atacadista de Frutas e Legumes Global Ltda"}
        };
        salvarArquivo(arquivo, dados); 
    }
}

void PersistenciaDeDados::carregarDados() {
    for (const auto& [categoria, arquivo] : arquivosCSV) {
        auto dados = carregarArquivo(arquivo); 
        std::cout << "Dados carregados de " << categoria << ":\n";
        for (const auto& [id, nome, quantidade, preco, fornecedor] : dados) {
            std::cout << id << ", " << nome << ", " << quantidade << ", " << preco << ", " << fornecedor << "\n";
        }
    }
}

void PersistenciaDeDados::salvarArquivo(const std::string& arquivo, const std::vector<std::tuple<int, std::string, int, double, std::string>>& dados) {
    std::ofstream arquivoSaida(arquivo);
    if (arquivoSaida.is_open()) {
        for (const auto& [id, nome, quantidade, preco, fornecedor] : dados) {
            arquivoSaida << id << "," << nome << "," << quantidade << "," << std::fixed << std::setprecision(2) << preco << "," << fornecedor << "\n";
        }
        arquivoSaida.close(); // Fecha o arquivo após a escrita
    } else {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << " para escrita." << std::endl;
    }
}

std::vector<std::tuple<int, std::string, int, double, std::string>> PersistenciaDeDados::carregarArquivo(const std::string& arquivo) {
    std::vector<std::tuple<int, std::string, int, double, std::string>> dados;
    std::ifstream arquivoEntrada(arquivo); // Abre o arquivo para leitura
    std::string linha;

    if (arquivoEntrada.is_open()) {
        while (std::getline(arquivoEntrada, linha)) {
            std::istringstream ss(linha); // Cria uma string stream para dividir a linha
            std::string campo;
            int id, quantidade;
            double preco;
            std::string nome, fornecedor;

            if (std::getline(ss, campo, ',')) id = std::stoi(campo);
            if (std::getline(ss, campo, ',')) nome = campo; // Obtém o nome diretamente sem remover aspas
            if (std::getline(ss, campo, ',')) quantidade = std::stoi(campo);
            if (std::getline(ss, campo, ',')) preco = std::stod(campo);
            if (std::getline(ss, campo)) fornecedor = campo;
            dados.emplace_back(id, nome, quantidade, preco, fornecedor);
        }
        arquivoEntrada.close(); // Fecha o arquivo após a leitura
    } else {
   
        std::cerr << "Erro ao abrir o arquivo " << arquivo << " para leitura." << std::endl;
    }

    return dados; 
}
