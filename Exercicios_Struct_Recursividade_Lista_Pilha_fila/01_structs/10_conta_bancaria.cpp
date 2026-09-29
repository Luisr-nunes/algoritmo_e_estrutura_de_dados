#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct ContaBancaria {
    string titular;
    int numeroConta;
    float saldo;
};

void depositar(ContaBancaria *conta, float valor) {
    if (valor <= 0) {
        cout << "Valor de deposito invalido.\n";
        return;
    }
    conta->saldo += valor;
    cout << "Deposito de R$ " << valor << " realizado com sucesso.\n";
}

void sacar(ContaBancaria *conta, float valor) {
    if (valor <= 0) {
        cout << "Valor de saque invalido.\n";
        return;
    }
    if (valor > conta->saldo) {
        cout << "Saldo insuficiente para esse saque.\n";
        return;
    }
    conta->saldo -= valor;
    cout << "Saque de R$ " << valor << " realizado com sucesso.\n";
}

void exibirSaldo(ContaBancaria conta) {
    cout << "Saldo atual de " << conta.titular << " (conta " << conta.numeroConta
         << "): R$ " << conta.saldo << "\n";
}

int main() {
    ContaBancaria conta;
    int opcao;
    float valor;

    cout << "Nome do titular: ";
    getline(cin, conta.titular);

    cout << "Numero da conta: ";
    cin >> conta.numeroConta;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    conta.saldo = 0.0f;

    do {
        cout << "\n--- Menu Bancario ---\n";
        cout << "1 - Depositar\n";
        cout << "2 - Sacar\n";
        cout << "3 - Exibir saldo\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Valor a depositar: ";
                cin >> valor;
                depositar(&conta, valor);
                break;
            case 2:
                cout << "Valor a sacar: ";
                cin >> valor;
                sacar(&conta, valor);
                break;
            case 3:
                exibirSaldo(conta);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    return 0;
}
