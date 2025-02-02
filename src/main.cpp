#include <iostream>
#include "PersistenciaDeDados.cpp"
#include "GerenciadorDeEstoque.cpp"
#include "MenuInterativo.cpp"

  int main() {
    MenuInterativo menu(GerenciadorDeEstoque gerenciador(PersistenciaDeDados persistencia("dados.csv")));
    menu.init();
}