
#ifndef PERSISTENCIA_DE_DADOS_HPP
#define PERSISTENCIA_DE_DADOS_HPP

#include <vector>
#include <string>
#include "Produto.cpp"
#include "Categoria.hpp"
#include "Fornecedor.hpp"

class PersistenciaDeDados {
public:
    void salvarCSV();
    void carregarCSV();
};

#endif