#include "Controle.hpp"
#include "Massas.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class Controle
{
private:
    item *operador;
    std::string nome;
    int quantia;
    float preco;
public:
    void operacao(){
        int op=0;
        do{
            std::cout << "\nEscolha uma opção:\n";
            std::cout << "0. Sair\n";
            std::cout << "1. Massas\n";
            std::cout << "n. classe n\n";
            std::cin >> op;
            switch (op)
            {
            case 0:
                op=-1;
                break;
            case 1:
                operador = new Massas();
                break;
    //        case n:
    //            operador = new classe_n();
    //            break;
            
            default:
                std::cout << "ainda nao implementado\n";
                break;
            }
            do{
                std::cout << "\nEscolha uma opção:\n";
                std::cout << "0. Sair\n";
                std::cout << "1. Ler produtos\n";
                std::cout << "2. Adicionar produto\n";
                std::cout << "3. Remover produto\n";
                std::cin >> op;
                switch (op)
                {
                case 1:
                    operador->imprimeProdutos();
                    break;
                case 2:
                    std::cout << "\nDigite o nome do produto e a quantidade:\n";
                    std::cin >> nome >> quantia;
                    if(operador->encontraUnidade(nome)==nullptr){
                        std::cout << "\nDigite o preco:\n";
                        operador->criaUnidade(nome, quantia, preco);
                    }else{
                        operador->modificaUnidadeDe(nome, quantia, 1);
                    }
                    break;
                case 3:
                    break;    
                case 4:
                    break;    
                case 5:
                    break;            
                default:
                    break;
                };
                }while(op!=0);
        }while (op >=0);      
    }
    Controle::Controle(){}
    Controle::~Controle(){}
};
