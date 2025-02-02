#include <iostream>
#include <vector>
using namespace std;

class Categoria {
private:
    string nome;
    vector<string> produtos;
    string descricao;

public:

    Categoria(string nome, string descricao) {
        this->nome = nome;
        this->descricao = descricao;
    }

    
    string getNome() const {
        return nome;
    }

    void setNome(const string& novoNome) {
        nome = novoNome;
    }

    
    string getDescricao() const {
        return descricao;
    }

    void setDescricao(const string& novaDescricao) {
        descricao = novaDescricao;
    }

   
    vector<string> getProdutos() const {
        return produtos;
    }

    void adicionarProduto(const string& produto) {
        produtos.push_back(produto);
    }

    void removerProduto(const string& produto) {
        for (auto it = produtos.begin(); it != produtos.end(); ++it) {
            if (*it == produto) {
                produtos.erase(it);
                break;
            }
        }
    }

    void listarProdutos() const {
        cout << "Produtos disponíveis na categoria " << nome << ":" << endl;
        for (const auto& produto : produtos) {
            cout << "- " << produto << endl;
        }
    }
};

