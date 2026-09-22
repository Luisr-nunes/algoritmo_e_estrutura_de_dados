// Intercalar duas filas em uma terceira (versao C++ idiomatica)
// Assinatura equivalente: Fila intercalarFilas(const Fila& f1, const Fila& f2);
#include <iostream>
#include <string>
using namespace std;

class Fila {
private:
    struct No {
        int valor;
        No* prox;
        No(int v, No* p) : valor(v), prox(p) {}
    };
    No* inicio;
    No* fim;

public:
    Fila() : inicio(nullptr), fim(nullptr) {}
    ~Fila() {
        No* p = inicio;
        while (p) { No* prox = p->prox; delete p; p = prox; }
    }

    void enfileirar(int valor) {
        No* novo = new No(valor, nullptr);
        if (fim) fim->prox = novo; else inicio = novo;
        fim = novo;
    }

    void mostrar(const string& nome) const {
        cout << nome << ":";
        for (No* p = inicio; p; p = p->prox) cout << " " << p->valor;
        cout << "\n";
    }

    friend Fila intercalarFilas(const Fila& f1, const Fila& f2);
};

Fila intercalarFilas(const Fila& f1, const Fila& f2) {
    Fila resultado;
    Fila::No* p1 = f1.inicio;
    Fila::No* p2 = f2.inicio;

    while (p1 || p2) {
        if (p1) { resultado.enfileirar(p1->valor); p1 = p1->prox; } // vez da fila 1
        if (p2) { resultado.enfileirar(p2->valor); p2 = p2->prox; } // vez da fila 2
    }
    return resultado; // move semantics
}

int main() {
    Fila F1, F2;
    for (int v : {1, 3, 5}) F1.enfileirar(v);
    for (int v : {2, 4, 6}) F2.enfileirar(v);

    Fila R = intercalarFilas(F1, F2);
    F1.mostrar("F1");
    F2.mostrar("F2");
    R.mostrar("Resultado");

    // Filas de tamanhos diferentes
    Fila G1, G2;
    G1.enfileirar(7);
    for (int v : {20, 21, 22}) G2.enfileirar(v);
    Fila R2 = intercalarFilas(G1, G2);
    R2.mostrar("Tamanhos diferentes");

    // Uma fila vazia
    Fila vazia;
    Fila R3 = intercalarFilas(vazia, G2);
    R3.mostrar("Uma vazia");

    return 0; // todas as filas sao liberadas automaticamente pelos destrutores
}
