#include "Categoria.hpp"

Categoria::Categoria(const std::string& nome, const std::string& prefixo, int contadorInicial)
    : nome(nome), prefixo(prefixo), contador(contadorInicial) {}

std::string Categoria::getNomeDaCategoria() const {
    return nome;
}

std::string Categoria::getPrefixoId() const {
    return prefixo;
}

int Categoria::getContador() const {
    return contador;
}

void Categoria::setContador(int novoContador) {
    contador = novoContador;
}

std::string Categoria::gerarProximoID() {
    std::stringstream ss;
    ss << std::setw(3) << std::setfill('0') << contador; 
    return prefixo + ss.str(); 
}

void Categoria::atualizarContador(const std::vector<std::string>& idsExistentes) {
    int maxContador = 0;
    for (const std::string& id : idsExistentes) {
        if (id.substr(0, prefixo.length()) != prefixo) continue;
        std::string parteNumerica = id.substr(prefixo.length());
        try {
            int contadorAtual = std::stoi(parteNumerica);
            if (contadorAtual > maxContador) maxContador = contadorAtual;
        } catch (...) {
            // Ignora IDs inválidos
        }
    }
    contador = maxContador + 1;
}