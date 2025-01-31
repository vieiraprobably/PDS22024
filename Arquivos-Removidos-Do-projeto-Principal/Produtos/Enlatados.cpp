// classe enlatados (sem herdar classe "item")
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

class Enlatados {
private:
    struct InfoProduto {
        std::string nome;
        int disponivel;
        double preco;
        int vendido;
    };

    std::vector<InfoProduto> produtos;
    double faturamentoTotal;
    double gastosTotais;

    InfoProduto* buscarProduto(const std::string &nomeProduto) {
        for (auto &produto : produtos) {
            if (produto.nome == nomeProduto) {
                return &produto;
            }
        }
        return nullptr;
    }

public:
    Enlatados() : faturamentoTotal(0.0), gastosTotais(0.0) {}

    void carregarDoArquivo(const std::string &nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
            return;
        }

        std::string nome;
        int quantidade;
        double preco;

        while (arquivo >> nome >> quantidade >> preco) {
            produtos.push_back({nome, quantidade, preco, 0});
        }
        arquivo.close();
    }

    void salvarNoArquivo(const std::string &nomeArquivo) {
        std::ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao salvar o arquivo." << std::endl;
            return;
        }

        for (const auto &produto : produtos) {
            arquivo << produto.nome << " " << produto.disponivel << " " << produto.preco << "\n";
        }
        arquivo << "Faturamento Total: " << faturamentoTotal << "\n";
        arquivo << "Gastos Totais: " << gastosTotais << "\n";

        arquivo.close();
    }

    void mostrarPreco(const std::string &nomeProduto) {
        InfoProduto* produto = buscarProduto(nomeProduto);
        if (produto) {
            std::cout << produto->nome << " - Preco: R$ " << std::fixed << std::setprecision(2) << produto->preco << std::endl;
        } else {
            std::cout << "Produto nao encontrado." << std::endl;
        }
    }

    void venderProduto(const std::string &nomeProduto, int quantidade) {
        InfoProduto* produto = buscarProduto(nomeProduto);
        if (produto) {
            if (produto->disponivel >= quantidade) {
                produto->disponivel -= quantidade;
                produto->vendido += quantidade;
                faturamentoTotal += produto->preco * quantidade;
                std::cout << "Transacao concluida!" << std::endl;
            } else {
                std::cout << "Estoque insuficiente." << std::endl;
            }
        } else {
            std::cout << "Produto nao encontrado." << std::endl;
        }
    }

    void adicionarEstoque(const std::string &nomeProduto, int quantidade) {
        InfoProduto* produto = buscarProduto(nomeProduto);
        if (produto) {
            produto->disponivel += quantidade;
            gastosTotais += (produto->preco * 0.6) * quantidade;
            std::cout << "Estoque atualizado!" << std::endl;
        } else {
            std::cout << "Produto nao encontrado." << std::endl;
        }
    }

    void mostrarQuantidadeVendida(const std::string &nomeProduto) {
        InfoProduto* produto = buscarProduto(nomeProduto);
        if (produto) {
            std::cout << produto->nome << " - Quantidade vendida: " << produto->vendido << std::endl;
        } else {
            std::cout << "Produto nao encontrado." << std::endl;
        }
    }

    void mostrarFaturamento() {
        std::cout << "Faturamento total: R$ " << std::fixed << std::setprecision(2) << faturamentoTotal << std::endl;
    }

    void mostrarGastos() {
        std::cout << "Gastos totais: R$ " << std::fixed << std::setprecision(2) << gastosTotais << std::endl;
    }

    void menu() {
        int opcao;
        std::string nomeArquivo;
        std::cout << "Informe o nome do arquivo para carregar os produtos: ";
        std::cin >> nomeArquivo;
        carregarDoArquivo(nomeArquivo);

        do {
            std::cout << "\nMenu de Opcoes:\n";
            std::cout << "1. Mostrar preco de produto\n";
            std::cout << "2. Vender produto\n";
            std::cout << "3. Adicionar estoque\n";
            std::cout << "4. Mostrar quantidade vendida\n";
            std::cout << "5. Mostrar faturamento\n";
            std::cout << "6. Mostrar gastos\n";
            std::cout << "7. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cin >> opcao;

            std::string nomeProduto;
            int quantidade;

            switch (opcao) {
                case 1:
                    std::cout << "Nome do produto: ";
                    std::cin >> nomeProduto;
                    mostrarPreco(nomeProduto);
                    break;
                case 2:
                    std::cout << "Nome do produto: ";
                    std::cin >> nomeProduto;
                    std::cout << "Quantidade: ";
                    std::cin >> quantidade;
                    venderProduto(nomeProduto, quantidade);
                    break;
                case 3:
                    std::cout << "Nome do produto: ";
                    std::cin >> nomeProduto;
                    std::cout << "Quantidade a adicionar: ";
                    std::cin >> quantidade;
                    adicionarEstoque(nomeProduto, quantidade);
                    break;
                case 4:
                    std::cout << "Nome do produto: ";
                    std::cin >> nomeProduto;
                    mostrarQuantidadeVendida(nomeProduto);
                    break;
                case 5:
                    mostrarFaturamento();
                    break;
                case 6:
                    mostrarGastos();
                    break;
                case 7:
                    std::cout << "Saindo do sistema...\n";
                    salvarNoArquivo(nomeArquivo);
                    break;
                default:
                    std::cout << "Opcao invalida. Tente novamente." << std::endl;
            }
        } 
          while (opcao != 7);
    }
};

int main() {
    Enlatados enlatados;
    enlatados.menu();

    return 0;
}
