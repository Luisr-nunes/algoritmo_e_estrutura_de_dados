// Lista simplesmente encadeada de inteiros (versao C++ idiomatica)
#include <iostream>
#include <vector>
using namespace std;

class ListaEncadeada {
private:
    struct No {
        int valor;
        No* prox;
        No(int v, No* p) : valor(v), prox(p) {}
    };
    No* inicio;

public:
    ListaEncadeada() : inicio(nullptr) {}

    ~ListaEncadeada() { // RAII: libera tudo automaticamente
        No* p = inicio;
        while (p) {
            No* prox = p->prox;
            delete p;
            p = prox;
        }
    }

    // a) Inserir no final
    void inserirFinal(int valor) {
        No* novo = new No(valor, nullptr);
        if (!inicio) { inicio = novo; return; }
        No* p = inicio;
        while (p->prox) p = p->prox; // anda ate o ultimo vagao
        p->prox = novo;              // engata o novo vagao no final
    }

    void mostrar() const {
        cout << "Lista: ";
        for (No* p = inicio; p; p = p->prox)
            cout << p->valor << (p->prox ? " -> " : " -> NULL");
        cout << "\n";
    }

    // b) Conta quantas vezes 'alvo' aparece
    int contarValores(int alvo) const {
        int cont = 0;
        for (No* p = inicio; p; p = p->prox)
            if (p->valor == alvo) cont++;
        return cont;
    }
};

int main() {
    ListaEncadeada lista;
    vector<int> valores = {5, 8, 5, 10, 8, 12, 5}; // c) valores do teste

    for (int v : valores) lista.inserirFinal(v);

    lista.mostrar();

    int busca;
    cout << "Digite um numero para contar: ";
    cin >> busca;
    cout << "O numero " << busca << " aparece " << lista.contarValores(busca)
         << " vez(es) na lista.\n";

    // destrutor libera a lista automaticamente ao sair do escopo
    return 0;
}
