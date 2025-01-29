# Sistema de Gerenciamento de Estoque para Supermercado - PDS II

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-%232C2C2C.svg?style=for-the-badge&logo=gnu&logoColor=white)

* **Projeto Final** Sistema Gerenciador de Estoque de um Supermercado

* **Disciplina** Programação e Desenvolvimento de Software II 

* **Professor:** Eduardo Campos dos Santos

* **Instituição:** Universidade Federal de Minas Gerais - UFMG  

## Tabela de Conteúdo
- [📚 Sobre o projeto](#-sobre-o-projeto)
- [📝 Modelo Conceitual](#modelo-conceitual)
- [📃 Documentação do Sistema](#documentação-do-sistema)
- [⚙️ Funcionalidades](#️-funcionalidades)
- [🛠 Tecnologias Utilizadas](#-tecnologias-utilizadas)
- [📂 Estrutura do Projeto](#-estrutura-do-projeto)
- [📖 Aprendizados](#-aprendizados)
- [📦 Instalação](#-instalação)
- [👥 Autores](#-autores)

<a id="sobre-o-projeto"></a>
## 📚 Sobre o projeto

Este projeto tem como objetivo principal controlar e gerenciar o estoque de um supermercado, registrando a movimentação de produtos, incluindo cadastro, retirada e modificações. Além disso, o sistema é capaz de gerar um relatório de faturamento ao término da sua utilização.

O Gerenciador de Estoque de Supermercado foi desenvolvido como parte da disciplina de Programação e Desenvolvimento de Software II (PDS II), ministrada pelo professor Eduardo Campos.

A aplicação utiliza arquivos .txt como banco de dados para armazenar informações, permitindo o controle eficiente dos produtos disponíveis no estoque, bem como dos itens que serão adicionados. O foco deste projeto está em proporcionar um aprendizado aprofundado em C++, além de explorar funcionalidades práticas relacionadas ao desenvolvimento de sistemas e gestão de dados.

<a id="modelo-conceitual"></a>
## 📝 Modelo Conceitual
![Diagrama de Classe do Sistema]()
![Diagrama de Classes](https://github.com/vieiraprobably/PDS22024/issues/7#issue-2817635895)

<a id="documentação-do-sistema"></a>
## 📃 Documentação do Sistema

<a id="funcionalidades"></a>
## ⚙️ Funcionalidades
- Cadastro e organização de produtos.
- Controle de estoque com adição, remoção e atualização de produtos.
- Persistência de dados para garantir que as informações não sejam perdidas entre as execuções.
- Gestão de controle de acesso para administradores.
- Busca inteligente pelo nome do produto no banco de dados.
- Saida formatada em forma de um relatorio sobre o estoque.

<a id="tecnologias-utilizadas"></a>
## 🛠 Tecnologias Utilizadas

- **Linguagem:** C++17 (ISO/IEC 14882:2017)
- **Build System:** GNU Make 4.3
- **Persistência:** Sistema de arquivos texto
- **Controle de Versão:** Git
- **Testes:** Google Test Framework (gtest)
- **Organização**: Arquitetura modular com separação clara de:
  - Lógica de negócio (`ControleEstoque`)
  - Entidades (`Produtos`)
  - Serviços auxiliares (`Servicos`)
  - Gestão de usuários (`Usuario`)


<a id="estrutura-do-projeto"></a>
## 📂 Estrutura do Projeto
```bash
├── data/                              # Dados persistidos
│   ├── Carnes.txt
│   ├── GraosECereais.txt
│   ├── Laticionios.txt                
│   ├── Massas.txt
│   ├── ProdutosDeAnimais.txt
│   ├── ProdutosDeLimpeza.txt       
│   └── Verduras.txt
├── include/                           # Headers
│   ├── Controle.hpp
│   ├── GraosECereais.hpp
│   ├── Item.hpp
│   ├── Laticionios.hpp                
│   ├── Massas.hpp
│   ├── ProdutosDeAnimais.hpp
│   ├── ProdutosDeLimpeza.hpp       
│   └── Verduras.hpp
├── src/
│   ├── ControleEstoque/               # Lógica de controle
│   │   └── Controle.cpp               
│   ├── Produtos/                      # Implementações de produtos
│   │   ├── Carnes.cpp
│   │   ├── Categoria.cpp
│   │   ├── GraosECereais.cpp
│   │   ├── Item.cpp
│   │   ├── Laticionios.cpp                
│   │   ├── Massas.cpp
│   │   ├── Produtos.cpp
│   │   ├── ProdutosDeAnimais.cpp
│   │   ├── ProdutosDeLimpeza.cpp       
│   │   └── Verduras.cpp          
│   ├── Servicos/                      # Serviços auxiliares
│   │   ├── 
│   │   ├── 
│   │   └── 
│   ├── Usuario/                       # Gestão de usuários
│   │   └── Admin.cpp           
│   └── main.cpp                       # Ponto de entrada
├── .gitignore
├── tests/                             # Testes unitários
│   ├── ProdutosTests.cpp
│   └── ControleTests.cpp
└── Makefile                           # Sistema de build
```

<a id="aprendizados"></a>
## 📖 Aprendizados
  
* Manipulação avançada de arquivos em C++
* Implementação de TADs (Tipos Abstratos de Dados)
* Técnicas de validação de entrada de dados
* Organização de projetos em múltiplos módulos
* Princípios SOLID aplicados em C++
  
<a id="instalacao"></a>
## 📦 Instalação

### Pré-requisitos:

* Compilador C++17 (g++ ou clang++)
* GNU Make 4.3+
* Git (opcional)

1. Clone o projeto

```bash
  git clone https://github.com/vieiraprobably/PDS22024.git
```

2. Entre no diretório do projeto

```bash
  cd 
```

3. Compile

```bash
    g++ -o estoque main.cpp
```
4. Execute

```bash
  
```

<a id="autores"></a>
## 👥 Autores

- [@analeopoldino](https://github.com/analeopoldino)
- [@vieiraprobably](https://github.com/vieiraprobably)
- [@Dhdepaula](https://github.com/Dhdepaula)
- [@Danielguimass](https://github.com/Danielguimass)
- [@felipesvm](https://github.com/felipesvm)
- [@joaoPedroRG](https://github.com/joaoPedroRG)
- [@loullouts](https://github.com/loullouts)

