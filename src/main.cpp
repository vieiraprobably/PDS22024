#include "ProdutosDeLimpeza.hpp"
#include "ProdutosDeAnimais.hpp"
#include <iostream>
#include <cstdlib> 

int main() {
    ProdutosDeLimpeza produtosLimpeza;
    ProdutosDeAnimais produtosAnimais;

    std::string nomenovoProduto;
    int novaQuantidade;
    float novoPreco;
    int escolha;
    int categoria;

    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif

    while (1) {

        #ifdef _WIN32
            system("cls");  
        #else
            system("clear");  
        #endif

        std::cout << "\nEscolha uma opção:\n";
        std::cout << "1. Ler produtos\n";
        std::cout << "2. Adicionar produto\n";
        std::cout << "3. Editar produto\n";
        std::cout << "4. Excluir produto\n";
        std::cout << "5. Sair\n";
        std::cout << "Opção: ";
        std::cin >> escolha; 

        std::cin.ignore(); // limpa o buffer de entrada

        #ifdef _WIN32
            system("cls");  
        #else
            system("clear");  
        #endif

        switch (escolha){
            
            case 1:
                while (true) {
                    std::cout << "\nSelecione a categoria de produtos:\n";
                    std::cout << "1. Produtos de Limpeza\n";
                    std::cout << "2. Produtos de Animais\n";
                    std::cout << "3. Voltar ao menu principal\n";
                    std::cout << "Opção: ";
                    std::cin >> categoria;
                    std::cin.ignore(); // Limpa o buffer de entrada
                
                #ifdef _WIN32
                    system("cls");  
                #else
                    system("clear");  
                #endif 

                switch (categoria){
                      
                    
                    case 1:
                        std::cout << "Produtos existentes no banco de dados:\n";
                        produtosLimpeza.lerBancoDeDados("../data/ProdutosDeLimpeza.txt");
                    break;

                    case 2:
                        std::cout << "Produtos existentes no banco de dados:\n";
                        produtosAnimais.lerBancoDeDados("../data/ProdutosDeAnimais.txt");
                    break;

                    case 3:
                        break;
                    
                    default:
                        std::cout << "Opção inválida. Voltando ao menu principal.\n";
                    break;
                }
                if (categoria == 3) {
                        break; // Sai do loop de categoria
                    
                }
              }
            break;

            case 2:
                while (true) {
                    std::cout << "\nSelecione a categoria de produtos:\n";
                    std::cout << "1. Produtos de Limpeza\n";
                    std::cout << "2. Produtos de Animais\n";
                    std::cout << "3. Voltar ao menu principal\n";
                    std::cout << "Opção: ";
                    std::cin >> categoria;
                    std::cin.ignore(); // Limpa o buffer de entrada
                    
                    #ifdef _WIN32
                        system("cls");  
                    #else
                        system("clear");  
                    #endif 

                switch (categoria){
                        
                    case 1:
                        std::cout << "\n--------------------------\n";
                        std::cout << "\nAdicionar um novo produto\n";
                        std::cout << "\n--------------------------\n";

                        std::cout << "Digite o nome: ";
                        std::getline(std::cin, nomenovoProduto);

                        std::cout << "Digite a quantidade: ";
                        std::cin >> novaQuantidade;

                        std::cout << "Digite o preço: ";
                        std::cin >> novoPreco;  

                        produtosLimpeza.definirProduto(nomenovoProduto, novaQuantidade, novoPreco);

                        produtosLimpeza.escreverBancoDeDados("../data/ProdutosDeLimpeza.txt");

                        std::cout << "\nProdutos atualizados no banco de dados.\n";
                        std::cout << "n";

                    break;

                    case 2:
                        std::cout << "\n--------------------------\n";
                        std::cout << "\nAdicionar um novo produto\n";
                        std::cout << "\n--------------------------\n";

                        std::cout << "Digite o nome: ";
                        std::getline(std::cin, nomenovoProduto);

                        std::cout << "Digite a quantidade: ";
                        std::cin >> novaQuantidade;

                        std::cout << "Digite o preço: ";
                        std::cin >> novoPreco;  

                        produtosLimpeza.definirProduto(nomenovoProduto, novaQuantidade, novoPreco);

                        produtosLimpeza.escreverBancoDeDados("../data/ProdutosDeAnimais.txt");

                        std::cout << "\nProdutos atualizados no banco de dados.\n";
                        std::cout << "n";
                        
                    break;

                    case 3:
                        break;
                    
                    default:
                        std::cout << "Opção inválida. Voltando ao menu principal.\n";
                    break;
                }
                if (categoria == 3) {
                        break; // Sai do loop de categoria
                    
                }
            }
            break;

            case 5:
                std::cout << "Saindo do programa...\n";
                return 0; // Encerra o programa

            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        } 
    }
    
    return 0;
}
