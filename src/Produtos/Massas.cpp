#include "Massas.hpp"
#include <sstream>
#include "item.cpp" 

class Massa
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
    void imprimeProduto(){
        std::cout << "Produto: " << nome << "\n";
        std::cout << "Quantidade: " << quantidade << "\n";
        std::cout << "Preço: R$" << preco << "\n";
        std::cout << "-------------------" << std::endl;
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

class Massas : public item
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
            return encontraUnidade(Nome);
        }else{
            modificaUnidadeDe(Nome, Quantidade, 1);
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
            m->modificaUnidade(quantia*((2*mod)-1));//1=soma, 0=subtracao
        }else{return 1;}
        return 0;
    }
    void imprimeProdutos(){
        for(Massa m : massa){
            m.imprimeProduto();
        }
    }
    Massas(){
        std::ifstream bancoDeDados("../data/massas.txt");
        if (!bancoDeDados.is_open()){
            std::cerr << "Erro ao abrir o arquivo" << std::endl;
            return;
        }
        std::string nomeProduto, linha;
        int quantidade;
        float preco;
        while (std::getline(bancoDeDados, linha)) {
            std::istringstream stream(linha);
            std::getline(stream, nomeProduto, ' ');  
            stream >> quantidade >> preco; 
            criaUnidade(nomeProduto, quantidade, preco);
        }
        bancoDeDados.close();
    }
    ~Massas(){
        std::remove("../data/massas.txt");
        std::ofstream bancoDeDados("../data/massas.txt");
        for(Massa m : massa){
            bancoDeDados << m.verNome() << " " << m.verPreco() << " " << m.verQuantidade() << "\n";
        }
        bancoDeDados.close();
    }
};
