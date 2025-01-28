#include "Laticinios.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

void Laticinios::lerBancoDeDados(const std::string& Laticinios){
        std::ifstream bancoDeDados(Laticinios);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo: " << Laticinios << std::endl;
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

    void Laticinios::escreverBancoDeDados(const std::string& Laticinios){
        std::ofstream bancoDeDados(Laticinios, std::ios::app);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo para escrita: " << Laticinios << std::endl;
            return;
        }

        bancoDeDados << nomeProduto << " " << quantidade << " " << preco << "\n";
        bancoDeDados.close();
        }
    
    void Laticinios::definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco){
        nomeProduto = nomeNovoProduto;
        quantidade = novaQuantidade;
        preco = novoPreco;
    }

    void Laticinios::exibirProdutosDoBancoDeDados() const{
        std::cout << "Produto: " << nomeProduto << "\n";
        std::cout << "Quantidade: " << quantidade << "\n";
        std::cout << "Preço: R$" << preco << "\n";
        std::cout << "-------------------" << std::endl;
    }