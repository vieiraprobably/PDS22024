#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "include/Admin.hpp"
#include "include/PersistenciaDeDados.hpp"

Admin::Admin(const std::string& nome, const std::string& username, 
             const std::string& senha, const std::string& palavraSecreta)
    : nome(nome), username(username), senha(senha), palavraSecreta(palavraSecreta) {}

std::string Admin::getNome() const { 
    return nome; 
}

std::string Admin::getUsername() const { 
    return username;
}

std::string Admin::getSenha() const { 
    return senha; 
}

std::string Admin::getPalavraSecreta() const { 
    return palavraSecreta;
}

void Admin::setNome(const std::string& nome) { 
    this->nome = nome; 
}

void Admin::setUsername(const std::string& username) { 
    this->username = username; 
}

void Admin::setSenha(const std::string& senha) { 
    this->senha = senha; 
}

void Admin::setPalavraSecreta(const std::string& palavraSecreta) { 
    this->palavraSecreta = palavraSecreta; 
}

bool Admin::autenticarUsuario(const std::string& username, const std::string& senha, PersistenciaDeDados& persistencia) {
    std::vector<Admin> admins;
    persistencia.carregarAdmins(admins);
    for (const Admin& admin : admins) {
        if (admin.username == username && admin.senha == senha) {
            return true;
        }
    }
    return false;
}


bool Admin::cadastrarUsuario(const std::string& nome, const std::string& username, const std::string& senha, const std::string& palavraSecreta, PersistenciaDeDados& persistencia) {
    std::vector<Admin> admins;
    persistencia.carregarAdmins(admins);
    for (const Admin& admin : admins) {
        if (admin.getUsername() == username) {
            return false;
        }
    }
    Admin novoAdmin(nome, username, senha, palavraSecreta);
    persistencia.salvarAdmin(novoAdmin);
    return true;
}

bool Admin::recuperarSenha(const std::string& nome, const std::string& username, const std::string& novaSenha, const std::string& palavraSecreta, PersistenciaDeDados& persistencia) {
    std::vector<Admin> admins;
    persistencia.carregarAdmins(admins);
    for (Admin& admin : admins) {
        if (admin.username == username && admin.palavraSecreta == palavraSecreta) {
            admin.senha = novaSenha;
            std::ofstream file("data/estoque/Admin.csv");
            for (const Admin& a : admins) {
                file << a.nome << "," << a.username << "," << a.senha << "," 
                     << a.palavraSecreta << std::endl;
            }
            return true;
        }
    }
    return false;
}
