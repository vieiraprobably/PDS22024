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

![Diagrama de Classes](documents/class-diagram.png)

O sistema é estruturado em diversas classes, cada uma com responsabilidades específicas para manter a organização e escalabilidade.  

### 🔹 **1. Produto**  
Armazena informações detalhadas sobre os itens do estoque, incluindo:
  * Nome, ID único, quantidade disponível, preço unitário.
  * Categoria do produto (vinculada por ID).
  * Fornecedor associado (referência ao fornecedor do item).

### 🔹 **2. GerenciadorDeEstoque**  
Responsável por gerenciar todas as operações do estoque:
  * Adição, edição, exclusão e busca de produtos.
  * Listagem de produtos por categoria.
  * Integração com a Persistência de Dados para salvar/recuperar informações.
    
### 🔹 **3. Fornecedor**  
Representa os fornecedores dos produtos:
  * ID único, nome, informações de contato.
  * Funcionalidade para consultar fornecedores vinculados aos produtos.

### 🔹 **5. Categoria**  
  * ID único para cada categoriga de produto e nome da categoria.
  * Usada para organizar produtos e filtrar relatórios.

### 🔹 **6. Admin**  
Garante o controle de acesso e segurança do sistema:
  * Autenticação de usuários via login e senha.
  * Permissões restritas para operações críticas.
    
### 🔹 **7. Relatório**  
Gera relatórios estratégicos sobre o estoque:
  * Quantidade total de produtos por categoria.
  * Valor monetário agregado por categoria (quantidade × preço).

### 🔹 **7. MenuInterativo**  
Interface de usuário simples no terminal para interação com o sistema:
  * Exibição de opções (cadastrar produto, gerar relatório, etc.).
  * Processamento de entradas do usuário.
  * Integração direta com o GerenciadorDeEstoque e Admin.
    
### 🔹 **8. Persistência de Dados**  
Gerencia o armazenamento e recuperação de informações:
  * Salvamento em arquivos CSV (um por categoria, ex: Carnes.csv).
  * Carregamento de dados para memória.
  *Estrutura organizada para facilitar buscas e atualizações.

### 🔹 **9. IProduto (Interface)**
Define métodos obrigatórios para a classe Produto:
   * getId(), getNome(), getQuantidade(), getPreco(), etc.
   * Garante consistência no acesso aos dados dos produtos.

---

<a id="documentação-do-sistema"></a>
## 📃 Documentação do Sistema

<a id="funcionalidades"></a>
## ⚙️ Funcionalidades

✅ Cadastro de produtos, fornecedores e categorias.  
✅ Gerenciamento de pedidos de reposição.  
✅ Registro de movimentações de entrada e saída de estoque.  
✅ Geração de relatórios sobre estoque e movimentações.  
✅ Persistência de dados em arquivo de texto (`.csv`).  

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
- Relatórios são gerados para auxiliar na gestão do estoque.  

5️⃣ **Persistência de Dados**  
- Todas as informações são gerenciadas através da classe `PersistenciaDados`.  

---

## 📊 Design do Projeto

O design do projeto foi desenvolvido no **Figma** e pode ser acessado através do link abaixo:

[🔗 Acesse o Design no Figma](https://www.figma.com/design/8oKzeYT89yJ7rK6oEbXSdK/PDS-II?node-id=0-1&t=OGDshJbGERjOFYIG-1)

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

