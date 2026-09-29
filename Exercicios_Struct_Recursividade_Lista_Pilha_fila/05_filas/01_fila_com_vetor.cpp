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

void enqueue(Fila *f, int valor) {
    if (isFull(f)) {
        cout << "Fila cheia! Nao foi possivel inserir " << valor << ".\n";
        return;
    }
    f->dados[f->fim] = valor;
    f->fim++;
}

int dequeue(Fila *f) {
    if (isEmpty(f)) {
        cout << "Fila vazia! Nao ha o que remover.\n";
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio++;
    return valor;
}

int front(Fila *f) {
    if (isEmpty(f)) {
        cout << "Fila vazia! Nao ha primeiro elemento.\n";
        return -1;
    }
    return f->dados[f->inicio];
}

int main() {
    Fila fila;
    inicializar(&fila);

    cout << "Fila vazia? " << (isEmpty(&fila) ? "Sim" : "Nao") << "\n";

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);

    cout << "Primeiro da fila: " << front(&fila) << "\n";

    cout << "Removido: " << dequeue(&fila) << "\n";
    cout << "Removido: " << dequeue(&fila) << "\n";

    cout << "Primeiro da fila: " << front(&fila) << "\n";
    cout << "Fila vazia? " << (isEmpty(&fila) ? "Sim" : "Nao") << "\n";

    dequeue(&fila);
    dequeue(&fila);

    return 0;
}
