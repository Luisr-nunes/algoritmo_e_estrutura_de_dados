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

void push(Pilha *p, int valor) {
    p->topo++;
    p->dados[p->topo] = valor;
}

int pop(Pilha *p) {
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

void decimalParaBinario(int numero) {
    if (numero == 0) {
        cout << "0\n";
        return;
    }

    Pilha pilha;
    inicializar(&pilha);

    while (numero > 0) {
        int resto = numero % 2;
        push(&pilha, resto);
        numero = numero / 2;
    }

    while (!isEmpty(&pilha)) {
        cout << pop(&pilha);
    }
    cout << "\n";
}

int main() {
    int numero;

    cout << "Digite um numero decimal: ";
    cin >> numero;

    cout << "Binario: ";
    decimalParaBinario(numero);

    cout << "\nTestes do enunciado:\n";
    cout << "10 -> "; decimalParaBinario(10);
    cout << "25 -> "; decimalParaBinario(25);

    return 0;
}
