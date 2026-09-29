#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    int idade;
    float altura;
};

int main() {
    Pessoa p;

    cout << "Digite o nome: ";
    getline(cin, p.nome);

    cout << "Digite a idade: ";
    cin >> p.idade;

    cout << "Digite a altura (em metros, ex: 1.75): ";
    cin >> p.altura;

    cout << "\n--- Dados da Pessoa ---\n";
    cout << "Nome:   " << p.nome << "\n";
    cout << "Idade:  " << p.idade << " anos\n";
    cout << "Altura: " << p.altura << " m\n";

    return 0;
}
