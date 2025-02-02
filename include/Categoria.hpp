#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <vector>

#include "../include/Fornecedor.hpp"

class Categoria {
private:
    std::string nomeCategoria;
    int prefixoId;
    int contador;

public:
    Categoria(const std::string& nomeCategoria, int prefixoId, int contadorInicial);
    
    Fornecedor* obterFornecedorPorId(int id);
    std::string getNome() const;
    int getPrefixoId() const;
    int getContador() const;
    void setContador(int novoContador);
    int gerarProximoID();
    void atualizarContador(const std::vector<std::string>& idsExistentes);
    void carregarProdutosDoCSV(const std::string& nomeArquivo);
};

#endif