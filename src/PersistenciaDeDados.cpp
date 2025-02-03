#include "PersistenciaDeDados.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <Produto.hpp>
#include <utility> 
std::vector<std::pair<std::string, std::string>> arquivosCSV = {
        {"Animais", "Animais.csv"},
        {"Bebidas", "Bebidas.csv"},
        {"Carnes", "Carnes.csv"},
        {"Enlatados", "Enlatados.csv"},
        {"Frutas", "Frutas.csv"},
        {"GraosECereais", "GraosECereais.csv"},
        {"HigienePessoal", "HigienePessoal.csv"},
        {"Laticinios", "Laticinios.csv"},
        {"Limpeza", "Limpeza.csv"},
        {"Massas", "Massas.csv"},
        {"Padaria", "Padaria.csv"},
        {"Verduras", "Verduras.csv"}
    };

PersistenciaDeDados::PersistenciaDeDados() {
    
}

void PersistenciaDeDados::salvarDados(const Produto& produto) {
    for (const auto& [categoria, arquivo] : arquivosCSV) {
        if (produto.getCategoria() == categoria) {
            std::vector<std::tuple<int, std::string, int, double, std::string>> dados = {
                {produto.getId(), produto.getNome(), produto.getQuantidade(), produto.getPreco(), produto.getFornecedor()}
            };
            salvarArquivo(arquivo, dados); 
        }
    }
}


void PersistenciaDeDados::carregarDados() {
    for (const auto& [categoria, arquivo] : arquivosCSV) {
        auto dados = carregarArquivo(arquivo); 
        std::cout << "Dados carregados de " << categoria << ":\n";
        for (const auto& [id, nome, quantidade, preco, fornecedor] : dados) {
            std::cout << id << ", " << nome << ", " << quantidade << ", " << preco << ", " << fornecedor << "\n";
        }
    }
}

void PersistenciaDeDados::salvarArquivo(const std::string& arquivo, const std::vector<std::tuple<int, std::string, int, double, std::string>>& dados) {
    std::ofstream arquivoSaida(arquivo, std::ios::app);
    if (arquivoSaida.is_open()) {
        for (const auto& [id, nome, quantidade, preco, fornecedor] : dados) {
            arquivoSaida << id << "," << nome << "," << quantidade << "," << std::fixed << std::setprecision(2) << preco << "," << fornecedor << "\n";
        }
        arquivoSaida.close(); 
    } else {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << " para escrita." << std::endl;
    }
}

std::vector<std::tuple<int, std::string, int, double, std::string>> PersistenciaDeDados::carregarArquivo(const std::string& arquivo) {
    std::vector<std::tuple<int, std::string, int, double, std::string>> dados;
    std::ifstream arquivoEntrada(arquivo); 
    std::string linha;

    if (arquivoEntrada.is_open()) {
        while (std::getline(arquivoEntrada, linha)) {
            std::istringstream ss(linha); 
            std::string campo;
            int id, quantidade;
            double preco;
            std::string nome, fornecedor;

            if (std::getline(ss, campo, ',')) id = std::stoi(campo);
            if (std::getline(ss, campo, ',')) nome = campo; 
            if (std::getline(ss, campo, ',')) quantidade = std::stoi(campo);
            if (std::getline(ss, campo, ',')) preco = std::stod(campo);
            if (std::getline(ss, campo)) fornecedor = campo;
            dados.emplace_back(id, nome, quantidade, preco, fornecedor);
        }
        arquivoEntrada.close(); 
    } else {
   
        std::cerr << "Erro ao abrir o arquivo " << arquivo << " para leitura." << std::endl;
    }

    return dados; 
}

Produto PersistenciaDeDados::buscarProduto(const std::string& nomeProduto) {
    for (const auto& [categoria, arquivo] : arquivosCSV) {
        std::ifstream arquivoEntrada(arquivo);
        if (!arquivoEntrada.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
            continue;
        }

        std::string linha;
        while (std::getline(arquivoEntrada, linha)) {
            std::stringstream ss(linha);
            std::string idStr, nome, quantidadeStr, precoStr, fornecedor;
            int id, quantidade;
            double preco;

            std::getline(ss, idStr, ',');
            std::getline(ss, nome, ',');
            std::getline(ss, quantidadeStr, ',');
            std::getline(ss, precoStr, ',');
            std::getline(ss, fornecedor, ',');

            id = std::stoi(idStr);
            quantidade = std::stoi(quantidadeStr);
            preco = std::stod(precoStr);

           
            if (nome == nomeProduto) {
                return Produto(id, nome, quantidade, preco, fornecedor, categoria);
            }
        }
    }

    throw std::runtime_error("Produto não encontrado");
}


void PersistenciaDeDados::apagarProdutoPorId(int id) {
    for (auto& [categoria, arquivo] : arquivosCSV) {
        std::ifstream arquivoEntrada(arquivo);
        if (!arquivoEntrada.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
            continue;
        }

        std::vector<std::string> linhas;
        std::string linha;
        bool produtoEncontrado = false;

        
        while (std::getline(arquivoEntrada, linha)) {
            std::stringstream ss(linha);
            std::string idStr, nome, quantidadeStr, precoStr, fornecedor;
            int idProduto;

    
            std::getline(ss, idStr, ',');
            std::getline(ss, nome, ',');
            std::getline(ss, quantidadeStr, ',');
            std::getline(ss, precoStr, ',');
            std::getline(ss, fornecedor, ',');

            idProduto = std::stoi(idStr);
            if (idProduto == id) {
                produtoEncontrado = true;
                continue;  
            }

            linhas.push_back(linha);
        }

        if (produtoEncontrado) {
            std::ofstream arquivoSaida(arquivo);
            for (const auto& linha : linhas) {
                arquivoSaida << linha << "\n";
            }
        }
    }
}


void PersistenciaDeDados::apagarProdutoPorNome(const std::string& nomeProduto) {
    for (auto& [categoria, arquivo] : arquivosCSV) {
        std::ifstream arquivoEntrada(arquivo);
        if (!arquivoEntrada.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
            continue;
        }

        std::vector<std::string> linhas;
        std::string linha;
        bool produtoEncontrado = false;

    
        while (std::getline(arquivoEntrada, linha)) {
            std::stringstream ss(linha);
            std::string idStr, nome, quantidadeStr, precoStr, fornecedor;
            int idProduto;

          
            std::getline(ss, idStr, ',');
            std::getline(ss, nome, ',');
            std::getline(ss, quantidadeStr, ',');
            std::getline(ss, precoStr, ',');
            std::getline(ss, fornecedor, ',');

            idProduto = std::stoi(idStr);

           
            if (nome == nomeProduto) {
                produtoEncontrado = true;
                continue;  
            }

            
            linhas.push_back(linha);
        }

        if (produtoEncontrado) {
            std::ofstream arquivoSaida(arquivo);
            for (const auto& linha : linhas) {
                arquivoSaida << linha << "\n";
            }
        }
    }
}


std::string PersistenciaDeDados::listarProdutosPorCategoria(const std::string& categoriaBusca) {
    std::stringstream tabela;
    bool categoriaEncontrada = false;

    
    tabela << std::left << std::setw(10) << "ID" 
           << std::setw(20) << "Nome" 
           << std::setw(12) << "Quantidade" 
           << std::setw(10) << "Preço" 
           << std::setw(30) << "Fornecedor" 
           << "\n";
    tabela << std::string(82, '-') << "\n";  

    
    for (const auto& [categoria, arquivo] : arquivosCSV) {
        if (categoria == categoriaBusca) {
            categoriaEncontrada = true;
            std::ifstream arquivoEntrada(arquivo);
            if (!arquivoEntrada.is_open()) {
                std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
                continue;
            }

            std::string linha;
            while (std::getline(arquivoEntrada, linha)) {
                std::stringstream ss(linha);
                std::string idStr, nome, quantidadeStr, precoStr, fornecedor;
                int id, quantidade;
                double preco;

                std::getline(ss, idStr, ',');
                std::getline(ss, nome, ',');
                std::getline(ss, quantidadeStr, ',');
                std::getline(ss, precoStr, ',');
                std::getline(ss, fornecedor, ',');

                id = std::stoi(idStr);
                quantidade = std::stoi(quantidadeStr);
                preco = std::stod(precoStr);

                tabela << std::left << std::setw(10) << id
                       << std::setw(20) << nome
                       << std::setw(12) << quantidade
                       << std::setw(10) << std::fixed << std::setprecision(2) << preco
                       << std::setw(30) << fornecedor
                       << "\n";
            }
        }
    }

    if (!categoriaEncontrada) {
        return "Categoria não encontrada.\n";
    }

    return tabela.str();
}



std::vector<Produto> PersistenciaDeDados::carregarProdutos() {
    arquivosCSV = {
        {"Animais", "Animais.csv"},
        {"Bebidas", "Bebidas.csv"},
        {"Carnes", "Carnes.csv"},
        {"Enlatados", "Enlatados.csv"},
        {"Frutas", "Frutas.csv"},
        {"GraosECereais", "GraosECereais.csv"},
        {"HigienePessoal", "HigienePessoal.csv"},
        {"Laticinios", "Laticinios.csv"},
        {"Limpeza", "Limpeza.csv"},
        {"Massas", "Massas.csv"},
        {"Padaria", "Padaria.csv"},
        {"Verduras", "Verduras.csv"}
    };
    std::vector<Produto> produtos;

    for (const auto& [categoria, arquivo] : arquivosCSV) {
        std::ifstream arquivoEntrada(arquivo);
        if (!arquivoEntrada.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
            continue;
        }

        std::string linha;
        while (std::getline(arquivoEntrada, linha)) {
            std::stringstream ss(linha);
            std::string idStr, nome, quantidadeStr, precoStr, fornecedor;
            int id, quantidade;
            double preco;

            
            std::getline(ss, idStr, ',');
            std::getline(ss, nome, ',');
            std::getline(ss, quantidadeStr, ',');
            std::getline(ss, precoStr, ',');
            std::getline(ss, fornecedor, ',');

            id = std::stoi(idStr);
            quantidade = std::stoi(quantidadeStr);
            preco = std::stod(precoStr);

            Produto produto(id, nome, quantidade, preco, fornecedor);
            produtos.push_back(produto);
        }
    }

    return produtos;
}


bool PersistenciaDeDados::validarCredenciais() {

 std::ifstream arquivo("Admin.csv"); 
    std::string linha;

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo!" << std::endl;
        return false;
    }

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string nome, login, senhaArquivo, palavraSecreta;

        std::getline(ss, nome, ',');
        std::getline(ss, login, ',');
        std::getline(ss, senhaArquivo, ',');
        std::getline(ss, palavraSecreta, ',');

        
        if (login == usuario && senhaArquivo == senha) {
            arquivo.close();
            return true;  
        }
    }

    arquivo.close();
    return false;  
}


void PersistenciaDeDados::cadastrarUsuario(const std::string& nome, const std::string& usuario, const std::string& senha, const std::string& palavraSecreta) {
    std::ofstream arquivo("./data/Admin.csv", std::ios::app);  

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo para cadastro!" << std::endl;
        return;
    }

   
    arquivo << nome << "," << usuario << "," << senha << "," << palavraSecreta << "\n";

    arquivo.close();
    std::cout << "Usuário cadastrado com sucesso!" << std::endl;
}


std::vector<std::string> PersistenciaDeDados::getCategorias() {
    std::ifstream arquivo("Categorias.csv");
    std::string linha;
    std::vector<std::string> categorias;

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo Categorias.csv!" << std::endl;
        return categorias;  
    }


    std::getline(arquivo, linha);


    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string nomeCategoria, prefixoId, contador;


        std::getline(ss, nomeCategoria, ',');
        std::getline(ss, prefixoId, ',');
        std::getline(ss, contador, ',');

       
        categorias.push_back(nomeCategoria);
    }

    arquivo.close();
    return categorias;
}


std::vector<Produto> PersistenciaDeDados::listarProdutosPorCategoria(const std::string& categoriaBusca) {
    std::vector<Produto> produtosNaCategoria;

    for (const auto& [categoria, arquivo] : arquivosCSV) {
        if (categoria == categoriaBusca) {
            std::ifstream arquivoEntrada(arquivo);
            if (!arquivoEntrada.is_open()) {
                std::cerr << "Erro ao abrir o arquivo " << arquivo << std::endl;
                continue;
            }

            std::string linha;
            while (std::getline(arquivoEntrada, linha)) {
                std::stringstream ss(linha);
                std::string idStr, nome, quantidadeStr, precoStr, fornecedor;
                int id, quantidade;
                double preco;

                std::getline(ss, idStr, ',');
                std::getline(ss, nome, ',');
                std::getline(ss, quantidadeStr, ',');
                std::getline(ss, precoStr, ',');
                std::getline(ss, fornecedor, ',');

                id = std::stoi(idStr);
                quantidade = std::stoi(quantidadeStr);
                preco = std::stod(precoStr);

                Produto produto(id, nome, quantidade, preco, fornecedor);
                produtosNaCategoria.push_back(produto);
            }
        }
    }

    return produtosNaCategoria;
}