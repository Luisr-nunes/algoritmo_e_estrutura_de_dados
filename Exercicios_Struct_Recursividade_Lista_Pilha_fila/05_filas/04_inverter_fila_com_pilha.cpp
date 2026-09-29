#include <iostream>
using namespace std;

const int MAX = 100;

struct Fila {
    int dados[MAX];
    int inicio;
    int fim;
};

struct Pilha {
    int dados[MAX];
    int topo;
};

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

bool filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

void enqueue(Fila *f, int valor) {
    f->dados[f->fim] = valor;
    f->fim++;
}

int dequeue(Fila *f) {
    int valor = f->dados[f->inicio];
    f->inicio++;
    return valor;
}

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

bool pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, int valor) {
    p->topo++;
    p->dados[p->topo] = valor;
}

int pop(Pilha *p) {
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

void inverterFila(Fila *f) {
    Pilha pilha;
    inicializarPilha(&pilha);

    while (!filaVazia(f)) {
        push(&pilha, dequeue(f));
    }

    while (!pilhaVazia(&pilha)) {
        enqueue(f, pop(&pilha));
    }
}

void exibirFila(Fila *f) {
    int i = f->inicio;
    cout << "Fila: ";
    while (i < f->fim) {
        cout << f->dados[i] << " ";
        i++;
    }
    cout << "\n";
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    enqueue(&fila, 40);

    exibirFila(&fila);

    inverterFila(&fila);

    exibirFila(&fila);

    return 0;
}
