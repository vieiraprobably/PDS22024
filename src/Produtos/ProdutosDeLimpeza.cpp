#include "ProdutosDeLimpeza.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

void ProdutosDeLimpeza::lerBancoDeDados(const std::string& ProdutosDeLimpeza){
        std::ifstream bancoDeDados(ProdutosDeLimpeza);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo: " << ProdutosDeLimpeza << std::endl;
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

    void ProdutosDeLimpeza::escreverBancoDeDados(const std::string& ProdutosDeLimpeza){
        std::ofstream bancoDeDados(ProdutosDeLimpeza, std::ios::app);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo para escrita: " << ProdutosDeLimpeza << std::endl;
            return;
        }

        bancoDeDados << nomeProduto << " " << quantidade << " " << preco << "\n";
        bancoDeDados.close();
        }
    
    void ProdutosDeLimpeza::definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco){
        nomeProduto = nomeNovoProduto;
        quantidade = novaQuantidade;
        preco = novoPreco;
    }

    void ProdutosDeLimpeza::exibirProdutosDoBancoDeDados() const{
        std::cout << "Produto: " << nomeProduto << "\n";
        std::cout << "Quantidade: " << quantidade << "\n";
        std::cout << "Preço: R$" << preco << "\n";
        std::cout << "-------------------" << std::endl;
    }


