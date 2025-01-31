#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

class Usuario {
protected:
    int id;
    std::string nome;
    std::string email;
    std::string senha;
    std::string telefone;
    std::string nivelAcesso;
    std::chrono::system_clock::time_point dataCriacao;

public:
    Usuario() : id(0), dataCriacao(std::chrono::system_clock::now()) {}
    Usuario(int id, const std::string& nome, const std::string& email, const std::string& senha,
            const std::string& telefone, const std::string& nivelAcesso)
        : id(id), nome(nome), email(email), senha(senha), telefone(telefone), nivelAcesso(nivelAcesso),
          dataCriacao(std::chrono::system_clock::now()) {}

    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getEmail() const { return email; }
    std::string getSenha() const { return senha; }
    std::string getTelefone() const { return telefone; }
    std::string getNivelAcesso() const { return nivelAcesso; }

    std::string getDataCriacao() const {
        std::time_t data = std::chrono::system_clock::to_time_t(dataCriacao);
        return std::ctime(&data); 
    }
    void setId(int novoId) { id = novoId; }
    void setNome(const std::string& novoNome) { nome = novoNome; }
    void setEmail(const std::string& novoEmail) { email = novoEmail; }
    void setSenha(const std::string& novaSenha) { senha = novaSenha; }
    void setTelefone(const std::string& novoTelefone) { telefone = novoTelefone; }
    void setNivelAcesso(const std::string& novoNivelAcesso) { nivelAcesso = novoNivelAcesso; }


 
};