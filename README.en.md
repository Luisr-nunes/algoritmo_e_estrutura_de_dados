# Algorithms and Data Structures

<!-- badges -->
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white) ![C](https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=c&logoColor=white) ![GCC](https://img.shields.io/badge/GCC-A42E2B?style=flat-square&logo=gnu&logoColor=white)

[Ler em Português](README.md)

Exercises and graded assignments from the Algorithms and Data Structures course, in C and C++.

## About

The repository has two parts:

- **Exercise list** (C++), organized by topic: structs, recursion versus iteration, linked lists, stacks and queues.
- **Data structure assignments** (C and C++): solutions for the homework, the 2026.2 mock exam and the group and individual questions, each with a PDF containing the statement, explanation, code and test.

## Contents

### Exercicios_Struct_Recursividade_Lista_Pilha_fila

| Folder | Topic | Examples |
| --- | --- | --- |
| `01_structs` | Structs and pointers to structs | person, student array, contact book, bank account |
| `02_recursao_iteracao` | The same solution in recursive and iterative form | count digits, largest element, palindrome, countdown |
| `03_listas` | Singly linked list | count elements, sorted insertion, reverse list |
| `04_pilhas` | Array-based stack and applications | balanced parentheses, reverse string, decimal to binary |
| `05_filas` | Array-based and circular queue | bank queue simulation, reverse a queue using a stack |

### Questoes_Estrutura_de_Dados

| # | Question |
| --- | --- |
| 01 | Stack, queue and struct (homework) |
| 02 | Linked list: append and count values |
| 03 | 2026.2 mock exam, question 01: interleave queues (group) |
| 04 | 2026.2 mock exam, question 02: copy a binary search tree (individual) |
| 05 | Count nodes whose children sum to more than the node itself (group) |
| 06 | Interleave queues with `No* intercalarFilas(No *f1, No *f2)` (individual) |

- `codigos/`: one C solution per question.
- `codigos_C_CPP/`: the same solutions in C and C++.
- `pdfs/`: statement, explanation, code and test for each question.

## Running

Requirement: GCC/G++ (on Windows, MinGW or WSL).

```bash
git clone https://github.com/Luisr-nunes/algoritmo_e_estrutura_de_dados.git
cd algoritmo_e_estrutura_de_dados

# C question
gcc -Wall -o program Questoes_Estrutura_de_Dados/codigos/02_lista_encadeada.c
./program

# C++ exercise
g++ -Wall -o program Exercicios_Struct_Recursividade_Lista_Pilha_fila/04_pilhas/02_parenteses_balanceados.cpp
./program
```

## Author

Luís Nunes — [GitHub](https://github.com/Luisr-nunes) · [LinkedIn](https://www.linkedin.com/in/luis-nunes-dev/)

Academic project from the Systems Analysis and Development program at Cesar School.
