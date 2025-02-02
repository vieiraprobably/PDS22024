#include <iostream>
#include <string>
#include "../include/GerenciadorDeEstoque.hpp"


class MenuInterativo {
  private:
    GerenciadorDeEstoque& gerenciador;
public:
  MenuInterativo::MenuInterativo(GerenciadorDeEstoque& gerenciador) {}
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
    }

    void menuPrincipal(const std::string& usuario) {
        std::cout << "\n--------------------------------------------------------------\n";
        std::cout << "Bem-vindo, " << usuario << "!\n";
        std::cout << "--------------------------------------------------------------\n";
        std::cout << "[1] Relatório do estoque\n";
        std::cout << "[2] Gerenciar fornecedores\n";
        std::cout << "[3] Buscar produto\n";
        std::cout << "[4] Adicionar novos produtos\n";
        std::cout << "[5] Editar produto\n";
        std::cout << "[6] Remover produto\n";
        std::cout << "[7] Sair\n";
        std::cout << "[Escolha]: ";
    }

    bool validarCredenciais(const std::string& usuario, const std::string& senha) {
       
        return (persistencia.check(usuario, senha)); // falta implementar ainda
       
    }

    void cadastrarUsuario(const std::string& nome, const std::string& usuario, const std::string& senha, const std::string& palavraSecreta) {
        
        persistencia.cadastrar(nome, usuario, senha, palavraSecreta);
        //  Lemrbrar de criar as validações para nome, usuario, senha e palavra secreta 
        std::cout << "Usuário " << usuario << " cadastrado com sucesso!" << std::endl;
    }
};