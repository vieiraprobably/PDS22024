#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <string>

class Admin {

private:
    std::string nome;
    std::string username;
    std::string senha;
    std::string palavraSecreta;

public:
    Admin(const std::string& nome, const std::string& username, const std::string& senha, const std::string& palavraSecreta);
    ~Admin();
    
    std::string getNome() const;
    std::string getUsername() const;
    std::string getSenha() const;
    std::string getPalavraSecreta() const;

    void setNome(const std::string& nome);
    void setUsername(const std::string& username);
    void setSenha(const std::string& senha);
    void setPalavraSecreta(const std::string& palavraSecreta);

    bool autenticarUsuario(const std::string& username, const std::string& senha, PersistenciaDeDados& persistencia);
    bool cadastrarUsuario(const std::string& nome, const std::string& username, const std::string& senha, const std::string& palavraSecreta, PersistenciaDeDados& persistencia);
    bool recuperarSenha(const std::string& nome, const std::string& username, const std::string& novaSenha, const std::string& palavraSecreta, PersistenciaDeDados& persistencia);
};

#endif
