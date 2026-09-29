#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_CONTATOS = 20;

struct Contato {
    string nome;
    string telefone;
};

void adicionarContato(Contato agenda[], int *total) {
    if (*total >= MAX_CONTATOS) {
        cout << "Agenda cheia!\n";
        return;
    }

    cout << "Nome: ";
    getline(cin, agenda[*total].nome);

    cout << "Telefone: ";
    getline(cin, agenda[*total].telefone);

    (*total)++;
    cout << "Contato adicionado!\n";
}

void buscarContato(Contato agenda[], int total, const string &nomeBusca) {
    for (int i = 0; i < total; i++) {
        if (agenda[i].nome == nomeBusca) {
            cout << "Encontrado: " << agenda[i].nome << " - " << agenda[i].telefone << "\n";
            return;
        }
    }
    cout << "Contato nao encontrado.\n";
}

int main() {
    Contato agenda[MAX_CONTATOS];
    int total = 0;
    int opcao;
    string nomeBusca;

    do {
        cout << "\n--- Agenda de Contatos ---\n";
        cout << "1 - Adicionar contato\n";
        cout << "2 - Buscar contato pelo nome\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &total);
                break;
            case 2:
                cout << "Nome a buscar: ";
                getline(cin, nomeBusca);
                buscarContato(agenda, total, nomeBusca);
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
