
#ifndef PERSISTENCIA_DE_DADOS_HPP
#define PERSISTENCIA_DE_DADOS_HPP

#include <vector>
#include <string>
#include <iostream>
#include "../include/MenuInterativo.hpp"

class PersistenciaDeDados {
public:
    PersistenciaDeDados(const std::string& caminhoArquivo);
    void adicionarProduto(const std::string& linha);
    std::string buscarProduto(const std::string& palavra);
    void apagarProduto(const std::string& palavra);


};



#endif