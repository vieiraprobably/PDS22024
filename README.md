# Sistema de Gerenciamento de Estoque para Supermercado - PDS II

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-%232C2C2C.svg?style=for-the-badge&logo=gnu&logoColor=white)

**Projeto Final** da disciplina de **Programação e Desenvolvimento de Software II**  
**Professor:** Eduardo Campos  
**Instituição:** UFMG  

## Tabela de Conteúdo
- [Sobre o projeto](#sobre-o-projeto)
- [Modelo Conceitual](#modelo-conceitual)
- [Requisitos](#requisitos)
- [Funcionalidades](#funcionalidades)
- [Documentação da API](#documentação-da-api)
    - [Acessando localmente](#acessando-localmente)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Aprendizados](#aprendizados)
- [Rodando os testes](#rodando-os-testes)
- [Autores](#autores)

<a id="sobre-o-projeto"></a>
## Sobre o projeto

Este projeto tem como objetivo principal controlar e gerenciar o estoque de um supermercado, registrando a movimentação de produtos, como cadastro, retirada e modificações. lém de .

O DSCommerce é uma API REST desenvolvida durante o curso Java Spring Professional, ministradProfessor Nelio Alves da DevSuperior.

A aplicação permite a gestão de um comércio eletrônico, facilitando o gerenciamento de Produtos, Pedidos e Clientes. Seu foco está em proporcionar uma plataforma robusta e eficiente para operações de vendas e administração de estoque, integrando funcionalidades de controle e monitoramento de dados essenciais para o bom funcionamento de um supermercado.AAA
<a id="modelo-conceitual"></a>
## Modelo Conceitual
![Diagrama de Classe do Sistema]()

<a id="requisitos"></a>
## Requisitos
- [Java JDK (versão 17 ou superior)](https://www.oracle.com/java/technologies/javase/jdk17-archive-downloads.html)
- [Git](https://git-scm.com/downloads) - Sistema de controle de versão de código aberto
- [Uma conta no Github](https://github.com/) - Plataforma de controle de versões
- [Postman](https://www.postman.com/downloads/) ou [Insomnia](https://insomnia.rest/download) - Ferramentas para testar a API
- [Docker (Opcional)](https://www.docker.com/products/docker-desktop/) - Para rodar a aplicação localmente
- [PostgreSQL (Opcional)](https://www.postgresql.org/download/) - Para rodar a aplicação localmente, caso não queira instalar o Docker

<a id="documentação-da-api"></a>
## Documentação da API

<a id="acessando-localmente"></a>
### Acessando localmente

<a id="funcionalidades"></a>
## Funcionalidades

- Cadastrar produtos no sistema
- Gerenciar Produtos

<a id="tecnologias-utilizadas"></a>
## Tecnologias Utilizadas

- **Linguagem:** C++17 (ISO/IEC 14882:2017)
- **Build System:** GNU Make 4.3
- **Persistência:** Arquivos texto estruturados (CSV)
- **Testes:** Google Test Framework (gtest)

<a id="aprendizados"></a>
## Aprendizados

Neste projeto foi possível aprender sobre Bean Validation, usado para fazer validações dos dados de entrada da API, sobre o Spring Security, usado para permitir a autenticação dos usuários, além de gerenciar a autorização para o uso das rotas da API pelo usuário. E, por fim, foi possível aprender mais sobre a criação e utilização de exceções customizadas.

<a id="rodando-localmente"></a>
## Rodando localmente

Clone o projeto

```bash
  git clone https://github.com/hakkinenT/java-spring-boot-dscommerce.git
```

Entre no diretório do projeto

```bash
  cd java-spring-boot-dscommerce
```

Rode a aplicação

```bash
  ./mvnw spring-boot:run
```

<a id="rodando-os-testes"></a>
## Rodando os testes

Para rodar os testes, rode o seguinte comando

```bash
  mvn test
```

<a id="autores"></a>
## Autores

- [@hakkinenT](https://github.com/hakkinenT)
