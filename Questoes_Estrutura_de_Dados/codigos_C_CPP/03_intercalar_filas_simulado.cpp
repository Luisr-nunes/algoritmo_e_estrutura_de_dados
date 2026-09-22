// Questao 01: intercalar duas filas sem altera-las (versao C++ idiomatica)
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
    No* inicio; // quem esta na frente da fila (proximo a sair)
    No* fim;    // quem esta no final da fila (ultimo a entrar)

public:
    Fila() : inicio(nullptr), fim(nullptr) {}

    ~Fila() { // RAII: libera automaticamente
        No* p = inicio;
        while (p) { No* prox = p->prox; delete p; p = prox; }
    }

    void enfileirar(int valor) {
        No* novo = new No(valor, nullptr);
        if (fim) fim->prox = novo; else inicio = novo;
        fim = novo;
    }

    No* primeiro() const { return inicio; }
    // dá acesso apenas leitura à cadeia, para o intercalador "passear"

    void mostrar(const string& nome) const {
        cout << nome << " = [";
        for (No* p = inicio; p; p = p->prox)
            cout << p->valor << (p->prox ? ", " : "");
        cout << "]\n";
    }

    friend Fila intercalarFilas(const Fila& f1, const Fila& f2);
};

// Usamos dois "dedos" (p1 e p2) que apenas PASSEIAM pelas filas originais.
// Como so olhamos e nao retiramos ninguem, F1 e F2 continuam intactas.
Fila intercalarFilas(const Fila& f1, const Fila& f2) {
    Fila resultado;

    Fila::No* p1 = f1.inicio;
    Fila::No* p2 = f2.inicio;

    while (p1 || p2) {
        if (p1) { resultado.enfileirar(p1->valor); p1 = p1->prox; }
        if (p2) { resultado.enfileirar(p2->valor); p2 = p2->prox; }
    }
    return resultado; // move semantics evita copia desnecessaria
}

int main() {
    Fila F1, F2;
    for (int v : {10, 30, 50}) F1.enfileirar(v);
    for (int v : {20, 40})     F2.enfileirar(v);

    Fila R = intercalarFilas(F1, F2);

    F1.mostrar("F1");
    F2.mostrar("F2");
    R.mostrar("Resultado");

    return 0; // destrutores liberam F1, F2 e R automaticamente
}
