#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <limits>

class ProdutosDeLimpeza
{
private:
    std::string nomeProduto;
    int quantidade;
    float preco;
public:
    ProdutosDeLimpeza() {}
    ~ProdutosDeLimpeza() {}

    void lerBancoDeDados(const std::string& arquivo){
        std::ifstream bancoDeDados(arquivo);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo: " << arquivo << std::endl;
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

    void escreverBancoDeDados(const std::string& ProdutoDeLimpeza){
        std::ofstream bancoDeDados(ProdutoDeLimpeza, std::ios::app);
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo para escrita: " << ProdutoDeLimpeza << std::endl;
            return;
        }

        bancoDeDados << nomeProduto << " " << quantidade << " " << preco << "\n";
        bancoDeDados.close();
        }
    
    void definirProduto(const std::string& nomeNovoProduto, int novaQuantidade, float novoPreco){
        nomeProduto = nomeNovoProduto;
        quantidade = novaQuantidade;
        preco = novoPreco;
    }

    void exibirProdutosDoBancoDeDados() const{
        std::cout << "Produto: " << nomeProduto << "\n";
        std::cout << "Quantidade: " << quantidade << "\n";
        std::cout << "Preço: R$" << preco << "\n";
        std::cout << "-------------------" << std::endl;
    }
};

int main() {
    ProdutosDeLimpeza produto;

    std::string nomenovoProduto;
    int novaQuantidade;
    float novoPreco;
    char escolha;
    
    std::cout << "\nQuer adicionar um novo produto ou ver o banco de dados?(Digite A/a para adicionar e V/v para ver): \n";
    std::cin >> escolha;
    std::cin.ignore(); // limpa o buffer de entrada

    if (escolha == 'A' || escolha == 'a'){
        std::cout << "\n--------------------------\n";
        std::cout << "\nAdicionar um novo produto\n";
        std::cout << "\n--------------------------\n";

            std::cout << "Digite o nome: ";
            std::getline(std::cin, nomenovoProduto);

            std::cout << "Digite a quantidade: ";
            std::cin >> novaQuantidade;

            std::cout << "Digite o preço: ";
            std::cin >> novoPreco;  

            produto.definirProduto(nomenovoProduto, novaQuantidade, novoPreco);

            produto.escreverBancoDeDados("/home/analu/Documentos/PDS22024/ProdutosDeLimpeza.txt");

            std::cout << "\nProdutos atualizados no banco de dados.\n";
            std::cout << "n";

    }else if (escolha == 'V' || escolha == 'v'){
        std::cout << "Produtos existentes no banco de dados:\n";
        produto.lerBancoDeDados("/home/analu/Documentos/PDS22024/ProdutosDeLimpeza.txt");
        
    }else{
        std::cout << "Voce nao escolheu uma opcao valida!";
    }
    
    
    
    
   
        
    
    

    return 0;
}
