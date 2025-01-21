#include "Massas.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class Massa : public item
{
private:
    std::string nome;
    int quantidade;
    float preco;
public:
    void modificaUnidade(int quantia){
        this->quantidade = quantidade+quantia;
        return;
    }
    std::string verNome(){
        return nome;
    }
    int verQuantidade(){
        return quantidade;
    }
    float verPreco(){
        return preco;
    }
    Massa(std::string Nome, int Quantidade, float Preco){
        this->nome=Nome;
        this->quantidade=Quantidade;
        this->preco=Preco;
    }
    Massa(std::string Nome, float Preco){
        this->nome=Nome;
        this->quantidade=0;
        this->preco=Preco;
    }
    ~Massa(){}
};

class Massas //controlador de massas, quero generalizar para controlar todo o estoque
{
private:
    std::vector<Massa> massa;
public:
    Massa* criaUnidade(std::string Nome, float Preco){
        if(encontraUnidade(Nome)==nullptr){
            this->massa.push_back(Massa(Nome, Preco));
        }else{
            return encontraUnidade(Nome);
        }
    }
    Massa* criaUnidade(std::string Nome, int Quantidade, float Preco){
        if(encontraUnidade(Nome)==nullptr){
            this->massa.push_back(Massa(Nome, Quantidade, Preco));
        }else{
            return encontraUnidade(Nome);
        }
    }    
    Massa* encontraUnidade(std::string Nome){
        if(massa.empty()){
            return nullptr;
        }
        for(Massa m : massa){
            if(m.verNome() == Nome){
                return& m;
            }
        }
        return nullptr;
    }
    bool modificaUnidadeDe(std::string Nome, int quantia, bool mod){
        Massa* m=encontraUnidade(Nome);
        if(m!=nullptr){
            m->modificaUnidade(quantia*(2*mod-1));
        }else{return 1;}
        return 0;
    }
    Massas(){
        //abrir e receber informacoes do arquivo
        //criar se nao existir
    }
    ~Massas(){
        //fechar arquivo
    }
};
