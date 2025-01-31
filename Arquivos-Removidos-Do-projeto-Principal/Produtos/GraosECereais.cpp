#include "GraosECereais.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

void GraosECereais::lerBancoDeDados(const std::string& GraosECereais){
        std::ifstream bancoDeDados(GraosECereais);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo: " << GraosECereais << std::endl;
            return;
        }

        std::string linha;
        while (std::getline(bancoDeDados, linha)) {
            std::istringstream stream(linha);
            std::getline(stream, nomeProduto, ' ');  
            stream >> quantidade >> preco; 

            exibirProdutosDoBancoDeDados();
        }
       bancoDeDados.close();
    }

    void GraosECereais::escreverBancoDeDados(const std::string& GraosECereais){
        std::ofstream bancoDeDados(GraosECereais, std::ios::app);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo para escrita: " << GraosECereais << std::endl;
            return;
        }

        bancoDeDados << nomeProduto << " " << quantidade << " " << preco << "\n";
        bancoDeDados.close();
        }
    
    void GraosECereais::definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco){
        nomeProduto = nomeNovoProduto;
        quantidade = novaQuantidade;
        preco = novoPreco;
    }

    void GraosECereais::exibirProdutosDoBancoDeDados() const{
        std::cout << "Produto: " << nomeProduto << "\n";
        std::cout << "Quantidade: " << quantidade << "\n";
        std::cout << "Preço: R$" << preco << "\n";
        std::cout << "-------------------" << std::endl;
    }