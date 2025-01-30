#include <iostream>
#include <string>
#include "Fornecedor.hpp"
#include "Categoria.hpp"

class IProduto{

    private:

    public:
        virtual int getId() = 0;
        virtual std::string getNome() = 0;
        virtual Categoria* getCategoria() = 0;
        virtual int getQuantidade() = 0;
        virtual float getPreco() = 0;
        virtual Fornecedor* getFornecedor() = 0;

        virtual void setNome(std::string nome) = 0;
        virtual void setCategoria(Categoria* categoria) = 0;
        virtual void setQuantidade(int quantidade) = 0;
        virtual void setPreco(float preco) = 0;
        virtual void setFornecedor(Fornecedor* fornecedor) = 0;

        virtual void exibirProduto() = 0;

        virtual ~IProduto() = default;

};