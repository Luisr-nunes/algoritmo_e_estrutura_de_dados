#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int NUM_ALUNOS = 5;

struct Aluno {
    string nome;
    int matricula;
    float nota;
};

int main() {
    Aluno alunos[NUM_ALUNOS];
    float soma = 0.0f;

    for (int i = 0; i < NUM_ALUNOS; i++) {
        cout << "\n--- Aluno " << (i + 1) << " ---\n";

        cout << "Nome: ";
        getline(cin, alunos[i].nome);

        cout << "Matricula: ";
        cin >> alunos[i].matricula;

        cout << "Nota: ";
        cin >> alunos[i].nota;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        soma += alunos[i].nota;
    }

    float media = soma / NUM_ALUNOS;

    cout << "\n--- Resumo da Turma ---\n";
    for (int i = 0; i < NUM_ALUNOS; i++) {
        cout << alunos[i].nome << " (matricula " << alunos[i].matricula
             << ") - nota " << alunos[i].nota << "\n";
    }
    cout << "\nMedia da turma: " << media << "\n";

    return 0;
}
