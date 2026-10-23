# Algoritmos e Estruturas de Dados

<!-- badges -->
![C](https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=c&logoColor=white) ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white) ![GCC](https://img.shields.io/badge/GCC-A42E2B?style=flat-square&logo=gnu&logoColor=white)

[Read in English](README.en.md)

Exercícios e questões avaliativas da disciplina de Algoritmos e Estruturas de Dados, em C e C++.

## Sobre

O repositório reúne duas frentes de estudo:

- **Lista de exercícios** (C++), organizada por tema, cobrindo structs, recursão versus iteração, listas encadeadas, pilhas e filas.
- **Questões de estrutura de dados** (C e C++), com as soluções das tarefas, do simulado 2026.2 e das questões em grupo e individuais, acompanhadas de um PDF por questão com enunciado, explicação, código e teste.

## Conteúdo

### Exercicios_Struct_Recursividade_Lista_Pilha_fila

| Pasta | Tema | Exemplos |
| --- | --- | --- |
| `01_structs` | Structs e ponteiros para structs | pessoa, vetor de alunos, agenda de contatos, conta bancária |
| `02_recursao_iteracao` | A mesma solução nas versões recursiva e iterativa | contar dígitos, maior elemento, palíndromo, contagem regressiva |
| `03_listas` | Lista encadeada simples | contar elementos, inserção ordenada, reverter lista |
| `04_pilhas` | Pilha com vetor e aplicações | parênteses balanceados, inverter string, decimal para binário |
| `05_filas` | Fila com vetor e fila circular | atendimento bancário, inverter fila com pilha |

### Questoes_Estrutura_de_Dados

| Nº | Questão |
| --- | --- |
| 01 | Pilha, fila e struct (tarefas) |
| 02 | Lista encadeada: inserir no final e contar valores |
| 03 | Simulado 2026.2, questão 01: intercalar filas (grupo) |
| 04 | Simulado 2026.2, questão 02: copiar árvore binária de busca (individual) |
| 05 | Contar nós cuja soma dos filhos é maior que o próprio nó (grupo) |
| 06 | Intercalar filas com `No* intercalarFilas(No *f1, No *f2)` (individual) |

- `codigos/`: uma solução em C por questão.
- `codigos_C_CPP/`: as mesmas soluções em C e em C++.
- `pdfs/`: enunciado, explicação, código e teste de cada questão.

## Como executar

Pré-requisito: GCC/G++ (no Windows, MinGW ou WSL).

```bash
git clone https://github.com/Luisr-nunes/algoritmo_e_estrutura_de_dados.git
cd algoritmo_e_estrutura_de_dados

# Questão em C
gcc -Wall -o programa Questoes_Estrutura_de_Dados/codigos/02_lista_encadeada.c
./programa

# Exercício em C++
g++ -Wall -o programa Exercicios_Struct_Recursividade_Lista_Pilha_fila/04_pilhas/02_parenteses_balanceados.cpp
./programa
```

## Autor

Luís Nunes — [GitHub](https://github.com/Luisr-nunes) · [LinkedIn](https://www.linkedin.com/in/luis-nunes-dev/)

Projeto acadêmico do curso de Análise e Desenvolvimento de Sistemas da Cesar School.
