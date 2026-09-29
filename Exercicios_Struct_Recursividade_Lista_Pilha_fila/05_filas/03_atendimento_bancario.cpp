#include <iostream>
using namespace std;

const int MAX = 100;

struct Fila {
    int dados[MAX];
    int inicio;
    int fim;
};

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

bool isEmpty(Fila *f) {
    return f->inicio == f->fim;
}

bool isFull(Fila *f) {
    return f->fim == MAX;
}

void enqueue(Fila *f, int senha) {
    if (isFull(f)) {
        cout << "Fila cheia! Nao e possivel receber mais clientes agora.\n";
        return;
    }
    f->dados[f->fim] = senha;
    f->fim++;
    cout << "Cliente com senha " << senha << " entrou na fila.\n";
}

int dequeue(Fila *f) {
    if (isEmpty(f)) {
        cout << "Nao ha clientes esperando.\n";
        return -1;
    }
    int senha = f->dados[f->inicio];
    f->inicio++;
    return senha;
}

int clientesEsperando(Fila *f) {
    return f->fim - f->inicio;
}

int main() {
    Fila fila;
    inicializar(&fila);

    int proximaSenha = 1;
    int opcao;

    do {
        cout << "\n--- Atendimento Bancario ---\n";
        cout << "1 - Cliente chega (entra na fila)\n";
        cout << "2 - Chamar proximo cliente\n";
        cout << "3 - Ver quantidade de clientes esperando\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                enqueue(&fila, proximaSenha);
                proximaSenha++;
                break;
            case 2: {
                int senha = dequeue(&fila);
                if (senha != -1) {
                    cout << "Atendendo cliente com senha " << senha << ".\n";
                }
                break;
            }
            case 3:
                cout << "Clientes esperando: " << clientesEsperando(&fila) << "\n";
                break;
            case 0:
                cout << "Encerrando atendimento...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    return 0;
}
