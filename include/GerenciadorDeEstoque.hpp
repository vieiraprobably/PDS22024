#ifndef GERENCIADOR_DE_ESTOQUE_HPP
#define GERENCIADOR_DE_ESTOQUE_HPP

#include <vector>
#include <string>
#include "PersistenciaDeDados.hpp"
#include "Fornecedor.hpp"


class GerenciadorDeEstoque {
private:
    std::vector<std::string> produtos;
    PersistenciaDeDados& persistencia; 

public:
  
    GerenciadorDeEstoque(PersistenciaDeDados& persistencia);

    void adicionarProduto(const std::string& produto);

    void removerProduto(int id);
    
    std::string buscarProduto(const std::string& nome);

    void editarProduto(int id, const std::string& novoNome, const std::string& novaCategoria, int novaQuantidade, float novoPreco, Fornecedor novoFornecedor);
    
    void listarPorCategoria(const std::string& categoria);
};

#endif
