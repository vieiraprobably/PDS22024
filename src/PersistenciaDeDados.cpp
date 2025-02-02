#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../include/Produto.hpp"
class PersistenciaDeDados {
private:
    std::string caminhoArquivo;

public:
    
    PersistenciaDeDados::PersistenciaDeDados(const std::string& caminhoArquivo) {
    
}

    
    void adicionarProduto(const std::string& linha) {
        std::ofstream arquivo(caminhoArquivo, std::ios::app);
        if (arquivo.is_open()) {
            arquivo << linha << "\n";
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        }
    }

    
    std::string buscarProduto(const std::string& palavra) {
        std::ifstream arquivo(caminhoArquivo);
        std::string linha;

        if (arquivo.is_open()) {
            while (std::getline(arquivo, linha)) {
                if (linha.find(palavra) != std::string::npos) {
                    arquivo.close();
                    return linha;
                }
            }
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        }
        return ""; 
    }

    
    void apagarProduto(const std::string& palavra) {
        std::ifstream arquivo(caminhoArquivo);
        std::vector<std::string> linhas;
        std::string linha;

        if (arquivo.is_open()) {
            while (std::getline(arquivo, linha)) {
                if (linha.find(palavra) == std::string::npos) {
                    linhas.push_back(linha);
                }
            }
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
            return;
        }

        std::ofstream arquivoSaida(caminhoArquivo);
        if (arquivoSaida.is_open()) {
            for (const auto& l : linhas) {
                arquivoSaida << l << "\n";
            }
            arquivoSaida.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        }
    }
};