#include <iostream>
#include <string>
#include "../include/GerenciadorDeEstoque.hpp"


class MenuInterativo {
  private:
    GerenciadorDeEstoque& gerenciador;
    Relatorio& relatorio;
    std::string usuario;
public:
  MenuInterativo::MenuInterativo(GerenciadorDeEstoque& gerenciador, Relatorio& relatorio) {}
    void init() {
        while (true) {
            exibirInicio();
            int escolha;
            std::cin >> escolha;
            limparBuffer();
            switch (escolha) {
                case 1:
                    fluxoLogin();
                    break;
                case 2:
                    fluxoCadastro();
                    break;
                default:
                    std::cout << "\nOpção inválida!\n";
            }
        }
    }

private:
    void exibirInicio() {
        std::cout << "\n--------------------------------------------------------------\n";
        std::cout << "Bem-vindo ao Gerenciador de Estoque!\n";
        std::cout << "--------------------------------------------------------------\n";
        std::cout << "[1] Entrar\n";
        std::cout << "[2] Realizar cadastro\n";
        std::cout << "[Escolha]: ";
    }

    void fluxoLogin() {
        std::string usuario, senha;
        std::cout << "\n--------------------------------------------------------------\n";
        std::cout << "Área de Login\n";
        std::cout << "--------------------------------------------------------------\n";
        std::cout << "Digite o seu usuário: ";
        std::cin >> usuario;
        std::cout << "Digite a sua senha: ";
        std::cin >> senha;
        
        if (validarCredenciais(usuario, senha)) {
            this->usuario = usuario;
            menuPrincipal(usuario);
        } else {
            std::cout << "\nErro: Usuário ou senha inválidos!\n";
           
        }
    }

    void fluxoCadastro() {
        std::string nome, usuario, senha, palavraSecreta;
        std::cout << "\n--------------------------------------------------------------\n";
        std::cout << "Área de Cadastro\n";
        std::cout << "--------------------------------------------------------------\n";
        std::cout << "Digite o seu nome: ";
        std::cin >> nome;
        std::cout << "Digite o seu nome de usuário: ";
        std::cin >> usuario;
        std::cout << "Digite a sua senha: ";
        std::cin >> senha;
        std::cout << "Digite a palavra secreta: ";
        std::cin >> palavraSecreta;

        cadastrarUsuario(nome, usuario, senha, palavraSecreta);
        menuPrincipal(usuario)
    }

    void menuPrincipal(const std::string& usuario) {
        std::cout << "\n--------------------------------------------------------------\n";
        std::cout << "Bem-vindo, " << usuario << "!\n";
        std::cout << "--------------------------------------------------------------\n";
        std::cout << "[1] Relatório do estoque\n";
        std::cout << "[2] Gerenciar fornecedores\n";
        std::cout << "[3] Buscar produto\n";
        std::cout << "[4] Adicionar novos produtos\n";
        std::cout << "[5] Remover produto\n";
        std::cout << "[6] Sair\n";
        std::cout << "[Escolha]: ";
        std::string opcao;
        std::cin >> opcao;
        switch (opcao) {
                case 1:
                    gerarRelatorio();
                    break;
                case 2:
                    gerenciarFornecedores();
                    break;
                case 3:
                    buscarProduto();
                    break;
                case 4:
                    adicionarNovoProduto();
                    break;
                case 5:
                    removerProduto();
                    break;
                case 6:
                    exit();
                    break;
                    
                default:
                    std::cout << "\nOpção inválida!\n";
            }


    }

    void gerarRelatorio(){
        relatorio.gerarRelatorio();
        std::cout << "\n\n";  // 
        std::cout << "--------------------" << endl;  
        std::cout << "Digite 0 para voltar ao menu principal" << endl;
        int n;
        std::cin >> n;
        if (n == 0){
            menuPrincipal(usuario)
        }
        else{
            std::cout << "Opção inválida !! Saindo da aplicação em 3,2,1..." << endl;
            exit()
        }
    }

    void gerenciarFornecedores(){
        std::cout << "\n--------------------------------------------------------------\n";
        std::cout << "[1] Adicionar Fornecedor\n";
        std::cout << "[2] Listar Fornecedores\n";
        std::cout << "[3] Excluir fornecedor\n";
        std::cout << "[Escolha]: ";
        std::string opcao;
        std::cin >> opcao;
        switch (opcao) {
                case 1:
                    adicionarFornecedor();
                    break;
                case 2:
                    listarFornecedores();
                    break;
                case 3:
                    excluirFornecedore();
                    break;
                 default:
                    std::cout << "\nOpção inválida!\n";
        }


    }


    void buscarProduto(){
        std::cout << "\n--------------------------------------------------------------\n";
        std::cout << "[1] Digite o nome ou id do produto: \n";
        std::string opcao;
        std::cin >> opcao;
        Produto produto = gerenciador.buscarProduto(opcao);
        if (produto != nullptr){
            produto.exibirProduto();
            std::cout << "\nDigite 0 para voltar ao menu principal\n";
            int n;
        std::cin >> n;
            if (n == 0){
            menuPrincipal(usuario)
            }
            else{
            std::cout << "Opção inválida !! Saindo da aplicação em 3,2,1..." << endl;
            exit()
        }
        }
        else{
            std::cout << "\nProduto não encontrado\n";
            buscarProduto();

        }

    }

    void adicionarNovoProduto(){
        std::string  nome, fornecedorID,categoria, descricao;
        int id, quantidade;
        float preco;
        std::cout << "Digite um id para o produto: \n";
        std::cin >> id;
        std::cout << "Digite um nome para o produto: \n";
        std::cin >> nome;
        std::cout << "Digite a quantidade do produto: \n";
        std::cin >> quantidade;
        std::cout << "Digite o preço do produto: \n";
        std::cin >> preco;
        std::cout << "Digite a categoria do produto: \n";
        std::cin >> categoria;
        std::cout << "Digite uma descrição para a categoria: \n";
        std::cin >> descricao;

        Produto novoProduto = Produto(id, nome,Categoria(categoria, descricao), quantidade, preco, nullptr));
        gerenciador.adicionarProduto(novoProduto);

        std::cout << "Produto Adicionado com sucesso !!! \n";

        std::cout << "Retornando ao menu principal. \n";

        menuPrincipal(usuario)
        


    }

    void removerProduto(){
        std::cout << "\n--------------------------------------------------------------\n";
        std::cout << "Vamos remover um produto: \n";
        int id;
        std::cout << "Digite o id do produto a ser removido: \n";
        std::cin >> id;
        gerenciador.removerProduto(id);
        std::cout << "Produto removido com sucesso !! \n";

    }

    bool validarCredenciais(const std::string& usuario, const std::string& senha) {
       
        return (persistencia.validarCredenciais(usuario, senha)); 
       
    }

    void cadastrarUsuario(const std::string& nome, const std::string& usuario, const std::string& senha, const std::string& palavraSecreta) {
        
        persistencia.cadastrarUsuario(nome, usuario, senha, palavraSecreta); 
        std::cout << "Usuário " << usuario << " cadastrado com sucesso!" << std::endl;
    }
};