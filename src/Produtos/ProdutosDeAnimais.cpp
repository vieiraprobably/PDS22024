#include "ProdutosDeAnimais.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

void ProdutosDeAnimais::lerBancoDeDados(const std::string& ProdutosDeAnimais){
        std::ifstream bancoDeDados(ProdutosDeAnimais);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo: " << ProdutosDeAnimais << std::endl;
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

    void ProdutosDeAnimais::escreverBancoDeDados(const std::string& ProdutoDeLimpeza){
        std::ofstream bancoDeDados(ProdutoDeLimpeza, std::ios::app);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo para escrita: " << ProdutoDeLimpeza << std::endl;
            return;
        }

        bancoDeDados << nomeProduto << " " << quantidade << " " << preco << "\n";
        bancoDeDados.close();
        }
    
    void ProdutosDeAnimais::definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco){
        nomeProduto = nomeNovoProduto;
        quantidade = novaQuantidade;
        preco = novoPreco;
    }

    void ProdutosDeAnimais::exibirProdutosDoBancoDeDados() const{
        std::cout << "Produto: " << nomeProduto << "\n";
        std::cout << "Quantidade: " << quantidade << "\n";
        std::cout << "Preço: R$" << preco << "\n";
        std::cout << "-------------------" << std::endl;
    }


