#include <iostream>
#include "PersistenciaDeDados.cpp"
  int main() {
    MenuInterativo menu(PersistenciaDeDados persistencia("dados.csv"));
    menu.init();
     
    return 0;
}
