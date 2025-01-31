#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

class Categoria {
private:
    std::string nome;
    std::string prefixo;
    int contador;

public:
    Categoria(const std::string& nome, const std::string& prefixo, int contadorInicial = 1);
    
    std::string getNomeDaCategoria() const;
    std::string getPrefixoId() const;
    int getContador() const;
    void setContador(int novoContador);
    std::string gerarProximoID();
    void atualizarContador(const std::vector<std::string>& idsExistentes);
};

#endif // CATEGORIA_H