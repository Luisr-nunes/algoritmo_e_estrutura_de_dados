#include <iostream>
using namespace std;

const int MAX = 5;

struct FilaCircular {
    int dados[MAX];
    int inicio;
    int fim;
    int quantidade;
};

void inicializar(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

bool isEmpty(FilaCircular *f) {
    return f->quantidade == 0;
}

bool isFull(FilaCircular *f) {
    return f->quantidade == MAX;
}

void enqueue(FilaCircular *f, int valor) {
    if (isFull(f)) {
        cout << "Fila cheia! Nao foi possivel inserir " << valor << ".\n";
        return;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->quantidade++;
}

int dequeue(FilaCircular *f) {
    if (isEmpty(f)) {
        cout << "Fila vazia! Nao ha o que remover.\n";
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->quantidade--;
    return valor;
}

int main() {
    FilaCircular fila;
    inicializar(&fila);

    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);

    cout << "Removido: " << dequeue(&fila) << "\n";
    cout << "Removido: " << dequeue(&fila) << "\n";

    enqueue(&fila, 4);
    enqueue(&fila, 5);
    enqueue(&fila, 6);

    cout << "Fila (do inicio ao fim): ";
    while (!isEmpty(&fila)) {
        cout << dequeue(&fila) << " ";
    }
    cout << "\n";

    return 0;
}
