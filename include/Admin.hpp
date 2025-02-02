#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <string>

class Admin {
private:
    std::string nome;
    std::string login;
    std::string senha;
    std::string palavraSecreta;

public:
    Admin(std::string nome, std::string login, std::string senha, std::string palavraSecreta);
    ~Admin();
    
    std::string getNome() const;
    std::string getLogin() const;
    std::string getSenha() const;
    std::string getPalavraSecreta() const;

    void setNome(const std::string& nome);
    void setLogin(const std::string& login);
    void setSenha(const std::string& senha);
    void setPalavraSecreta(const std::string& palavraSecreta);

    bool autenticarUsuario(std::string login, std::string senha);
    void cadastrarUsuario(std::string nome, std::string login, std::string senha, std::string palavraSecreta);
    void recuperarSenha(std::string login);
};

#endif
