#include "Categoria.hpp"

Categoria::Categoria(const std::string& nomeCategoria, int prefixoId, int contadorInicial)
        : nomeCategoria(nomeCategoria), prefixoId(prefixoId), contador(contadorInicial) {}


std::string Categoria::getNome() const {
    return nomeCategoria;
}

int Categoria::getPrefixoId() const {
    return prefixoId;
}

int Categoria::getContador() const {
    return contador;
}

void Categoria::setContador(int novoContador) {
    contador = novoContador;
}


int Categoria::gerarProximoID() {
    return prefixoId * 1000 + contador++;  
}

void Categoria::atualizarContador(const std::vector<std::string>& idsExistentes) {
        int maxContador = contador;
        for (const std::string& id : idsExistentes) {
            if (std::stoi(id.substr(0, 2)) != prefixoId) continue;
            std::string parteNumerica = id.substr(2);  
            try {
                int contadorAtual = std::stoi(parteNumerica); 
                if (contadorAtual >= maxContador) {
                    maxContador = contadorAtual + 1;  
                }
            } catch (...) {
                // Ignora IDs inválidos
            }
        }
        contador = maxContador; 
}

