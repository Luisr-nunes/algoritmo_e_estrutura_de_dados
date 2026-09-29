#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Pilha {
    char dados[MAX];
    int topo;
};

void inicializar(Pilha *p) {
    p->topo = -1;
}

bool isEmpty(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, char valor) {
    p->topo++;
    p->dados[p->topo] = valor;
}

char pop(Pilha *p) {
    char valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

string inverterString(const string &origem) {
    Pilha pilha;
    inicializar(&pilha);

    for (char c : origem) {
        push(&pilha, c);
    }

    string destino;
    while (!isEmpty(&pilha)) {
        destino += pop(&pilha);
    }
    return destino;
}

int main() {
    string texto;

    cout << "Digite uma palavra (sem espacos): ";
    cin >> texto;

    string invertido = inverterString(texto);

    cout << "Original:  " << texto << "\n";
    cout << "Invertida: " << invertido << "\n";

    return 0;
}
