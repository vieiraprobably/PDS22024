
#ifndef PERSISTENCIA_DE_DADOS_HPP
#define PERSISTENCIA_DE_DADOS_HPP

#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <iostream>

class PersistenciaDeDados {
private:
    std::map<std::string, std::string> arquivosCSV;

    void salvarArquivo(const std::string& arquivo, const std::vector<std::tuple<int, std::string, int, double, std::string>>& dados);

    std::vector<std::tuple<int, std::string, int, double, std::string>> carregarArquivo(const std::string& arquivo);

public:
    PersistenciaDeDados();
    void salvarDados(const Produto& produto);
    Produto buscarProduto(const std::string& nomeProduto);
    void apagarProdutoPorId(int id);
    void apagarProdutoPorNome(const std::string& nomeProduto);
    std::string listarProdutosPorCategoria(const std::string& categoriaBusca);
    void carregarDados();
};

#endif
