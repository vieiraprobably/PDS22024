#include <iostream>
#include "../include/GerenciadorDeEstoque.hpp"
#include "../include/MenuInterativo.hpp"
#include "../include/PersistenciaDeDados.hpp"


  int main() {
    PersistenciaDeDados persistencia;
    GerenciadorDeEstoque gerenciador(persistencia);
    MenuInterativo menu(gerenciador);
    menu.init();
    return 0;
}