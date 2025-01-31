#include "HigienePessoal.hpp"
#include <sstream>
#include "item.cpp" 

class HigienePessoal
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
    HigienePessoal(std::string Nome, int Quantidade, float Preco){
        this->nome=Nome;
        this->quantidade=Quantidade;
        this->preco=Preco;
    }
    HigienePessoal(std::string Nome, float Preco){
        this->nome=Nome;
        this->quantidade=0;
        this->preco=Preco;
    }
    ~HigienePessoal(){}
};

class HigienePessoais : public item
{
private:
    std::vector<HigienePessoal> higienepessoal;
public:
    HigienePessoal* criaUnidade(std::string Nome, float Preco){
        if(encontraUnidade(Nome)==nullptr){
            this->higienepessoal.push_back(HigienePessoal(Nome, Preco));
        }else{
            return encontraUnidade(Nome);
        }
    }
    HigienePessoal* criaUnidade(std::string Nome, int Quantidade, float Preco){
        if(encontraUnidade(Nome)==nullptr){
            this->higienepessoal.push_back(HigienePessoal(Nome, Quantidade, Preco));
            return encontraUnidade(Nome);
        }else{
            modificaUnidadeDe(Nome, Quantidade, 1);
            return encontraUnidade(Nome);
        }
    }    
    HigienePessoal* encontraUnidade(std::string Nome){
        if(higienepessoal.empty()){
            return nullptr;
        }
        for(HigienePessoal m : higienepessoal){
            if(m.verNome() == Nome){
                return& m;
            }
        }
        return nullptr;
    }
    bool modificaUnidadeDe(std::string Nome, int quantia, bool mod){
        HigienePessoal* m=encontraUnidade(Nome);
        if(m!=nullptr){
            m->modificaUnidade(quantia*((2*mod)-1));//1=soma, 0=subtracao
        }else{return 1;}
        return 0;
    }
    void imprimeProdutos(){
        for(HigienePessoal m : higienepessoal){
            m.imprimeProduto();
        }
    }
    HigienePessoais(){
        std::ifstream bancoDeDados("../data/higienepessoals.txt");
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
    ~HigienePessoais(){
        std::remove("../data/higienepessoals.txt");
        std::ofstream bancoDeDados("../data/higienepessoals.txt");
        for(HigienePessoal m : higienepessoal){
            bancoDeDados << m.verNome() << " " << m.verPreco() << " " << m.verQuantidade() << "\n";
        }
        bancoDeDados.close();
    }
};
