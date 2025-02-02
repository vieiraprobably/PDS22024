#ifndef MENU_INTERATIVO_HPP
#define MENU_INTERATIVO_HPP

#include "GerenciadorDeEstoque.hpp"

class MenuInterativo {
public:
    MenuInterativo(GerenciadorDeEstoque& gerenciador);
    void init();
};

#endif