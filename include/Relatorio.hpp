#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include "include/PersistenciaDeDados.hpp"

class Relatorio {

private:
    PersistenciaDeDados& persistencia;
    
    void imprimirCabecalho() const;
    void imprimirLinha(const std::string& categoria, int quantidade, double valorTotal) const;
    void imprimirTotalGeral(int totalProdutos, double valorTotal) const;

public:
    Relatorio(PersistenciaDeDados& persistencia);
    void gerarRelatorio() const;
};

#endif
