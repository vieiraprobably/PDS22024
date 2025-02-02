#include <iostream>

  int main() {
    MenuInterativo menu(GerenciadorDeEstoque gerenciador(PersistenciaDeDados persistencia("dados.csv")));
    menu.init();
}