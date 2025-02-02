#include "include/Relatorio.hpp"
#include "include/PersistenciaDeDados.hpp"
#include "include/Categoria.hpp"

#include <iostream>
#include <iomanip>

Relatorio::Relatorio(PersistenciaDeDados& persistencia) : persistencia(persistencia) {}

void Relatorio::imprimirCabecalho() const {
    std::cout << "\n— Relatório do Estoque —\n";
    std::cout << "Categoria       | Quantidade | Valor Total (R$)\n";
    std::cout << "------------------------------------------------\n";
}

void Relatorio::imprimirLinha(const std::string& categoria, int quantidade, double valorTotal) const {
    std::cout << std::left << std::setw(15) << categoria << " | "
              << std::right << std::setw(9) << quantidade << " | "
              << std::setw(12) << std::fixed << std::setprecision(2) << valorTotal << "\n";
}

void Relatorio::imprimirTotalGeral(int totalProdutos, double valorTotal) const {
    std::cout << "------------------------------------------------\n";
    std::cout << "Total Geral:     | "
              << std::right << std::setw(9) << totalProdutos << " | "
              << std::setw(12) << valorTotal << "\n";
    std::cout << "------------------------------------------------\n\n";
}

void Relatorio::gerarRelatorio() const {
    int quantidadeTotalGeral = 0;
    double valorTotal = 0.0;
    
    imprimirCabecalho();
    
    for (const auto& categoria : persistencia.getCategorias()) {
        auto produtos = persistencia.carregarProdutosPorCategoria(categoria);
        
        int totalQuantidadeCategoria = 0;
        double valorTotalCategoria = 0.0;
        
        for (const auto& produto : produtos) {
            totalQuantidadeCategoria += produto.getQuantidade();
            valorTotalCategoria += produto.getQuantidade() * produto.getPreco();
        }
        
        quantidadeTotalGeral += totalQuantidadeCategoria;
        valorTotal += valorTotalCategoria;
        
        imprimirLinha(categoria, totalQuantidadeCategoria, valorTotalCategoria);
    }
    
    imprimirTotalGeral(quantidadeTotalGeral, valorTotal);
}
