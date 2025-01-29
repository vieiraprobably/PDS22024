#ifndef PADARIA_HPP
#define PADARIA_HPP

#include "item.hpp"
#include <string>
#include <vector>

class Padaria : public item {
private:
    struct Produto {
        std::string nome;
        int quantidade;
        float preco;
    };

    std::vector<Produto> produtos;

public:
    Padaria();
    ~Padaria();

    void imprimeProdutos() override;
    bool modificaUnidadeDe(std::string Nome, int quantia, bool mod) override;
    item* encontraUnidade(std::string Nome) override;
    item* criaUnidade(std::string Nome, int Quantidade, float Preco) override;
    item* criaUnidade(std::string Nome, float Preco) override;
};

#endif
