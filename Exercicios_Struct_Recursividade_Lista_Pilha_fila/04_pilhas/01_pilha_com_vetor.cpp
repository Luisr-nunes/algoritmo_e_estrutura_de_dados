#include <iostream>
using namespace std;

const int MAX = 100;

struct Pilha {
    int dados[MAX];
    int topo;
};

void inicializar(Pilha *p) {
    p->topo = -1;
}

bool isEmpty(Pilha *p) {
    return p->topo == -1;
}

bool isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if (isFull(p)) {
        cout << "Pilha cheia! Nao foi possivel inserir " << valor << ".\n";
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor;
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        cout << "Pilha vazia! Nao ha o que remover.\n";
        return -1;
    }
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

int top(Pilha *p) {
    if (isEmpty(p)) {
        cout << "Pilha vazia! Nao ha topo.\n";
        return -1;
    }
    return p->dados[p->topo];
}

int main() {
    Pilha pilha;
    inicializar(&pilha);

    cout << "Pilha vazia? " << (isEmpty(&pilha) ? "Sim" : "Nao") << "\n";

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    cout << "Topo da pilha: " << top(&pilha) << "\n";

    cout << "Removido: " << pop(&pilha) << "\n";
    cout << "Removido: " << pop(&pilha) << "\n";

    cout << "Topo da pilha: " << top(&pilha) << "\n";
    cout << "Pilha vazia? " << (isEmpty(&pilha) ? "Sim" : "Nao") << "\n";

    pop(&pilha);
    pop(&pilha);

    return 0;
}
