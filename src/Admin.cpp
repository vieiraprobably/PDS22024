#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Admin{
public:
    string login;
    string senha;
    string palavraSecreta;

    void Cadastra_usuario(){ 

        cout << "Digite seu login";
        cin >> login;
        cout << "Digite sua senha";
        cin >> senha;
        cout << "Digite uma palavra secreta para recuperacao de senha";
        cin >> palavraSecreta;

        ofstream arq;

        arq.open("Bando_de_Dados.csv", ios:: app);

        arq << login << " " << senha <<" " << palavraSecreta << endl;

        cout<< "Cadastro realizado com sucesso" << "\n";

        arq.close();   

    } 

bool Verifica(string& usuario, string& senha){};

ifstream arq ("Banco_de_Dados.csv");

if(arq.is_open()){

    while(arq >> login >> senha){
        if(p.login == usuario && p.senha == senha){
        return true;
        }

        else{
            return false;    
        }
    } 

}   

void Acesso(){

    cout << "Digite seu login: ";
    cin >> login;
    cout <, "Digite sua senha: ";
    cin >> senha;

    if(Verifica(login,senha)){

        cout << "Login efetuado com sucesso\n";

    } else {

            cout << "Usuario ou senha incorretos";
    }
    

}

void Recupera_Senha(login){

    string s;
    string novaSenha;
    int contador;

    cout << "Digite sua palavra secreta";
    cin >> s;

    arq.open("Banco_de_Dados.csv");

        while(arq >> palavraSecreta){

            if(s == palavraSecreta){

                cout << "Digite sua nova senha";
                cin >> novaSenha;

            } else {
                cout << "palavraSecreta incorreta";
                return;
            }

        } 

        senha = novaSenha;
    
};  
}