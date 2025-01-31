#include "User.cpp"
#include <iostream>
#include <string>
#include <vector>

class Admin : public Usuario {
private:
    std::vector<Usuario> listaAdmins; 

public:

    Admin() : Usuario() {}

    Admin(int id, const std::string& nome, const std::string& email, const std::string& senha,
          const std::string& telefone, const std::string& nivelAcesso)
        : Usuario(id, nome, email, senha, telefone, nivelAcesso) {}

    void cadastrarProduto();
    void adicionarProduto();
    void removerProduto();
    void adicionarAdmin();
    
    const std::vector<Usuario>& getListaAdmins() const { return listaAdmins; }

    void adicionarNaListaAdmins(const Usuario& admin) {
        listaAdmins.push_back(admin);
    }

         virtual ~Admin() = default;
};