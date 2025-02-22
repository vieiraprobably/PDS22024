#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include <string>
#include <vector>
#include "Produto.hpp"

class Fornecedor {
private:
    int fornecedorId;
    std::string nome;
    std::string contato;
    std::string endereco;
    std::vector<Produto*> produtos; 
    std::vector<int> categoriasAssociadas;

public:
    Fornecedor(int id, const std::string& n, const std::string& c, const std::string& e);
    ~Fornecedor();

    int getId() const;
    std::string getNome() const;
    std::string getContato() const;
    std::string getEndereco() const;
    std::vector<Produto*> getProdutos() const;
    std::vector<int> getCategoriasAssociadas() const;

    void setId(int id);
    void setNome(const std::string& n);
    void setContato(const std::string& c);
    void setEndereco(const std::string& e);
    void setProdutos(const std::vector<Produto*>& p);
};

#endif 

