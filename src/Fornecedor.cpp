#include <iostream>
#include <string>
#include <list>

using namespace std;

class Produto {
public:
    string nome;
    float preco;

    Produto(string n, float p) : nome(n), preco(p) {}
};

class Fornecedor {
private:
    int id;
    string nome;
    string contato;
    float endereco;
    list<Produto> produtos;

public:
    // Construtor
    Fornecedor(int i, string n, string c, float e) : id(i), nome(n), contato(c), endereco(e) {}

    // Função para cadastrar fornecedor
    void cadastrarFornecedor(int i, string n, string c, float e) {
        id = i;
        nome = n;
        contato = c;
        endereco = e;
    }

    // Função para atualizar fornecedor
    void atualizarFornecedor(int i, string n, string c, float e) {
        id = i;
        nome = n;
        contato = c;
        endereco = e;
    }

    // Função para adicionar produto ao fornecedor
    void adicionarProduto(string nomeProduto, float precoProduto) {
        Produto p(nomeProduto, precoProduto);
        produtos.push_back(p);
    }

    // Função para listar os produtos
    void listarProdutos() {
        cout << "Produtos do Fornecedor " << nome << " (" << id << "):" << endl;
        for (auto& p : produtos) {
            cout << "Nome: " << p.nome << " - Preço: " << p.preco << endl;
        }
    }

    // Função para exibir as informações do fornecedor
    void exibirFornecedor() {
        cout << "ID: " << id << endl;
        cout << "Nome: " << nome << endl;
        cout << "Contato: " << contato << endl;
        cout << "Endereço: " << endereco << endl;
    }
};

int main() {
    // Criando um fornecedor
    Fornecedor f(1, "Fornecedor A", "1234-5678", 123.45);

    // Cadastrando e atualizando fornecedor
    f.cadastrarFornecedor(1, "Fornecedor A", "1234-5678", 123.45);
    f.atualizarFornecedor(1, "Fornecedor A Atualizado", "9876-5432", 543.21);

    // Adicionando produtos
    f.adicionarProduto("Produto 1", 15.50);
    f.adicionarProduto("Produto 2", 22.75);

    // Listando produtos
    f.listarProdutos();

    // Exibindo informações do fornecedor
    f.exibirFornecedor();

    return 0;
}