#ifndef ITEM_HPP
#define ITEM_HPP

class item{
    public:
    void imprimeProdutos();
    bool modificaUnidadeDe(std::string, int, bool);
    item* encontraUnidade(std::string);
    item* criaUnidade(std::string, int, float);
    item* criaUnidade(std::string, float);
};

#endif