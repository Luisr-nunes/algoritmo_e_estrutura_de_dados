#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_PACIENTES = 10;

struct Paciente {
    string nome;
    int idade;
    string diagnostico;
};

void exibirPacientesAcimaDe60(Paciente pacientes[], int n) {
    cout << "\n--- Pacientes com mais de 60 anos ---\n";
    int encontrados = 0;

    for (int i = 0; i < n; i++) {
        if (pacientes[i].idade > 60) {
            cout << pacientes[i].nome << ", " << pacientes[i].idade
                 << " anos - " << pacientes[i].diagnostico << "\n";
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "Nenhum paciente acima de 60 anos.\n";
    }
}

int main() {
    int n;

    cout << "Quantos pacientes deseja cadastrar (max " << MAX_PACIENTES << ")? ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n <= 0 || n > MAX_PACIENTES) {
        cout << "Quantidade invalida.\n";
        return 1;
    }

    Paciente pacientes[MAX_PACIENTES];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Paciente " << (i + 1) << " ---\n";

        cout << "Nome: ";
        getline(cin, pacientes[i].nome);

        cout << "Idade: ";
        cin >> pacientes[i].idade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Diagnostico: ";
        getline(cin, pacientes[i].diagnostico);
    }

    exibirPacientesAcimaDe60(pacientes, n);

    return 0;
}
