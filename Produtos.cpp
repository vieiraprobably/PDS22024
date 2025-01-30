#include <iostream>
#include <string>

class Produto
{
private:
    int id;
    std::string nome;
    std::string categoria;
    int quantidade;
    float preco;
    Fornecedor* fornecedor;

public:
    int getId() { return id; }
    std::string getNome() { return nome; }
    std::string getCategoria() { return categoria; }
    int getQuantidade() { return quantidade; }
    float getPreco() { return preco; }
    Fornecedor* getFornecedor() { return fornecedor; }

    void setQuantidade(int qtd) { quantidade = qtd; }
    void setPreco(float p) { preco = p; }
    void setNome(std::string n){ nome=n; }
    void setFornecedor(Fornecedor* f){ fornecedor=f; }

    void exibirProduto(){
        std::cout << "ID: "<< id;
        std::cout << "\nNOME: "<< nome;
        std::cout << "\nQUANTIDADE: "<< quantidade;
        std::cout << "\nPRECO: R$ "<< preco;
        std::cout << "\nFORNECEDOR: " << fornecedor->getNome();     
        std::cout << "\nCATEGORIA: "<< categoria<< "\n";
        std::cout <<"------------------\n";
    }

    Produto();
    ~Produto();
};

Produto::Produto()
{
}

Produto::~Produto()
{
}
