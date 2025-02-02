#ifndef GERENCIADOR_DE_ESTOQUE_HPP
#define GERENCIADOR_DE_ESTOQUE_HPP

#include <vector>
#include <string>
#include "PersistenciaDeDados.hpp"

class GerenciadorDeEstoque {
private:
    std::vector<std::string> produtos;
    PersistenciaDeDados& persistencia; 

public:
  
    GerenciadorDeEstoque(PersistenciaDeDados& persistencia);

   
    void adicionarProduto(const std::string& produto);

    
    std::string buscarProduto(const std::string& nome);

    
    void listarProdutos();
};

#endif
