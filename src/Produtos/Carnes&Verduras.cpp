#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Carnes{
public:

float preco;
int quantidade;
string tipo;

};

class Boi: public Carnes {

int picanha = 100;
int alcatra = 150;
int patinho = 200;
int cumpim = 200;
int contrafile = 150;

};

class Frango: public Carnes {

int coxa = 800;
int asa = 800;
int peito = 1000;
int foot = 500;
int coracao = 500;
};

class Porco: public Carnes {

int lompo = 500;
int copalombro = 600;
int linguica = 500;
int pernil = 500;
int bacon = 1000;

};

class Peixes: public Carnes {

    int tilapia;
    int salmao;
    int tucunare;
    int bagre;
    int lambarim;


};
class Frutas {
public:

    int quantidade;
    float preco;
    int tipo;

};

class Verduras {
public:
    int quantidade;
    float preco;
    int tipo;

};

int main(){

FILE *arq;

arq = fopen ("estoque.txt", "r");



    return 0;
}