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

![Diagrama de Classes](https://private-user-images.githubusercontent.com/107570879/407669625-9a634019-2801-44a6-a0cb-ad5a97522330.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzgxNDM0MTAsIm5iZiI6MTczODE0MzExMCwicGF0aCI6Ii8xMDc1NzA4NzkvNDA3NjY5NjI1LTlhNjM0MDE5LTI4MDEtNDRhNi1hMGNiLWFkNWE5NzUyMjMzMC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMTI5JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDEyOVQwOTMxNTBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mZThkMTcyYmRkMmI1ZThlMjIyMDdkZTc5OTU4YjE2OWYxYjY1NWJmMTFiNjRlZDg4NGMyZGMwYWNmZDhiZGUwJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.VWetWN3Mx_DsRCzR99ruoHnEgTg_ZYIslj8NelDRt_E)

O sistema é estruturado em diversas classes, cada uma com responsabilidades específicas para manter a organização e escalabilidade.  

### 🔹 **1. Produto**  
Armazena informações sobre os itens do estoque, como nome, quantidade, preço e fornecedor.  

### 🔹 **2. Estoque**  
Gerencia a lista de produtos armazenados, permitindo a adição, remoção e verificação de disponibilidade.  

### 🔹 **3. Fornecedor**  
Representa os fornecedores dos produtos, armazenando nome, contato e itens fornecidos.  

### 🔹 **4. Pedido**  
Registra solicitações de reposição de produtos ao fornecedor. O status do pedido é controlado por um **Enum**, podendo ser:  
- **PENDENTE** – Pedido criado, aguardando aprovação.  
- **APROVADO** – Pedido aprovado para processamento.  
- **EM_ANDAMENTO** – Pedido sendo preparado ou enviado pelo fornecedor.  
- **ENTREGUE** – Pedido recebido e incorporado ao estoque.  
- **CANCELADO** – Pedido cancelado e não processado.  

### 🔹 **5. Movimentação de Estoque**  
Registra todas as operações de entrada e saída de produtos, armazenando informações como data, quantidade e usuário responsável.  

### 🔹 **6. Usuário**  
Representa os funcionários que gerenciam o estoque, garantindo controle de acesso e segurança.  

### 🔹 **7. Relatório**  
Gera relatórios sobre os produtos disponíveis, movimentações realizadas e pedidos efetuados.  

### 🔹 **8. Persistência de Dados**  
Responsável pela **leitura e escrita** dos dados em  arquivos `.txt`. Essa classe permite:  
- **Ler dados** do arquivo.  
- **Adicionar novas linhas** ao final do arquivo.  
- **Buscar registros** por palavra-chave.  
- **Remover ou atualizar registros** de forma eficiente.  

---

<a id="documentação-do-sistema"></a>
## 📃 Documentação do Sistema

<a id="funcionalidades"></a>
## ⚙️ Funcionalidades

✅ Cadastro de produtos, fornecedores e categorias.  
✅ Gerenciamento de pedidos de reposição.  
✅ Registro de movimentações de entrada e saída de estoque.  
✅ Geração de relatórios sobre estoque e movimentações.  
✅ Persistência de dados em arquivo de texto (`.txt`).  

---

## ⚙️ Fluxo de Funcionamento  

1️⃣ **Cadastro de Produtos**  
- O usuário adiciona um novo produto ao estoque, informando nome, categoria, quantidade e fornecedor.  

2️⃣ **Gerenciamento de Pedidos**  
- Quando um produto atinge um nível crítico de estoque, um pedido de reposição é criado.  
- O status do pedido é atualizado conforme o andamento da solicitação.  

3️⃣ **Movimentação de Estoque**  
- Cada entrada ou saída de produto é registrada, com detalhes sobre a quantidade e o responsável pela operação.  

4️⃣ **Geração de Relatórios**  
- Relatórios periódicos são gerados para auxiliar na gestão do estoque.  

5️⃣ **Persistência de Dados**  
- Todas as informações são gerenciadas através da classe `PersistenciaDados`.  

---

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

