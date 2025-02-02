#include <iostream>
#include <vector>
#include <string>
#include "..include/PersistenciaDeDados.hpp"

class GerenciadorDeEstoque {
private:
    std::vector<Produto> produtos;
    PersistenciaDeDados* persistencia;
public:
    GerenciadorDeEstoque(PersistenciaDeDados* persistencia)
        : persistencia(persistencia) {}
  
    void adicionarProduto(const Produto& produto) {
        produtos.push_back(produto);
        persistencia.salvarDados(produto);
    }

    void editarProduto(int id, const std::string& novoNome, const std::string& novaCategoria, int novaQuantidade, float novoPreco, Fornecedor novoFornecedor) {
       
    }
    void removerProduto(int id) {
        persistencia.apagarProdutoPorId(id);
        
    }

    void removerProduto(const std::string& nome) {
        persistencia.apagarProdutoPorNome(nome);

        
    }
   
    void buscarProduto(const std::string& nome)  {
        persistencia.buscarProduto(nome)
      
    }
    void listarPorCategoria(const std::string& categoria) {
       persistencia.listarProdutosPorCategoria(categoria);
    }

    std::vector<Produto> carregarProdutos(){
        produtos = persistencia.carregarProdutos();
    }
};