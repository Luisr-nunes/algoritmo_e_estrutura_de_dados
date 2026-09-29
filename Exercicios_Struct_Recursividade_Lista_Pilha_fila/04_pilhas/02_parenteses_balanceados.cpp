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

bool expressaoValida(const string &expressao) {
    Pilha pilha;
    inicializar(&pilha);

    for (char c : expressao) {
        if (c == '(') {
            push(&pilha, c);
        } else if (c == ')') {
            if (isEmpty(&pilha)) {
                return false;
            }
            pop(&pilha);
        }
    }

    return isEmpty(&pilha);
}

int main() {
    string expressao;

    cout << "Digite uma expressao com parenteses: ";
    cin >> expressao;

    cout << (expressaoValida(expressao) ? "Valido" : "Invalido") << "\n";

    cout << "\nTestes do enunciado:\n";
    cout << "\"(())()\" -> " << (expressaoValida("(())()") ? "Valido" : "Invalido")
         << " (esperado: Valido)\n";
    cout << "\"(()\"    -> " << (expressaoValida("(()") ? "Valido" : "Invalido")
         << " (esperado: Invalido)\n";

    return 0;
}
