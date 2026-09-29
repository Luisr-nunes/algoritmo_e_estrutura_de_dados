#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Funcionario {
    string nome;
    string cargo;
    float salario;
};

int main() {
    int n;

    cout << "Quantos funcionarios deseja cadastrar? ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n <= 0) {
        cout << "Quantidade invalida.\n";
        return 1;
    }

    Funcionario *funcionarios = new Funcionario[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Funcionario " << (i + 1) << " ---\n";

        cout << "Nome: ";
        getline(cin, funcionarios[i].nome);

        cout << "Cargo: ";
        getline(cin, funcionarios[i].cargo);

        cout << "Salario: ";
        cin >> funcionarios[i].salario;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n--- Lista de Funcionarios ---\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ") " << funcionarios[i].nome << " - "
             << funcionarios[i].cargo << " - R$ " << funcionarios[i].salario << "\n";
    }

    delete[] funcionarios;
    funcionarios = nullptr;

    return 0;
}
