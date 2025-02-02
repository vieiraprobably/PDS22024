#include <iostream>
#include <vector>
#include <string>

class GerenciadorDeEstoque {
private:
    std::vector<Produto> produtos;
    PersistenciaDeDados* persistencia;

public:
    GerenciadorDeEstoque(PersistenciaDeDados* persistencia)
        : persistencia(persistencia) {}
  
    void adicionarProduto(const Produto& produto) {
        
    }

    void editarProduto(int id, const std::string& novoNome, const std::string& novaCategoria, int novaQuantidade, float novoPreco, Fornecedor novoFornecedor) {
       
    }

    void removerProduto(int id) {
        
    }
   
    void buscarProduto(const std::string& nome)  {
      
    }

    void listarPorCategoria(const std::string& categoria) {
       
    }
};