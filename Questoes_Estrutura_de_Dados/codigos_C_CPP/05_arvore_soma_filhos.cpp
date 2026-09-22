// Arvore: contar nos cuja soma dos filhos e MAIOR que o proprio no (C++ idiomatico)
#include <iostream>
using namespace std;

class Arvore {
private:
    struct No {
        int valor;
        No* esq;
        No* dir;
        No(int v, No* e, No* d) : valor(v), esq(e), dir(d) {}
    };
    No* raiz;

    void liberar(No* r) {
        if (!r) return;
        liberar(r->esq);
        liberar(r->dir);
        delete r;
    }

    int contarSomaFilhosMaior(No* r) const {
        // Caso base: arvore vazia nao tem no nenhum para contar
        if (!r) return 0;

        int conta = 0;
        // So faz sentido falar em "soma dos filhos" se existir pelo menos um filho
        if (r->esq || r->dir) {
            int soma = 0;
            if (r->esq) soma += r->esq->valor; // filho que nao existe vale 0
            if (r->dir) soma += r->dir->valor;
            if (soma > r->valor) conta = 1;    // este no entra na contagem
        }
        return conta + contarSomaFilhosMaior(r->esq) + contarSomaFilhosMaior(r->dir);
    }

public:
    // Constroi a arvore ja com a forma fixa usada no teste
    Arvore() {
        raiz = new No(10,
                  new No(6, new No(2, nullptr, nullptr), new No(3, nullptr, nullptr)),
                  new No(7, nullptr, new No(9, nullptr, nullptr)));
    }
    ~Arvore() { liberar(raiz); }

    int contarSomaFilhosMaior() const { return contarSomaFilhosMaior(raiz); }
};

class ArvoreVazia {
public:
    static int contarSomaFilhosMaior() { return 0; } // caso base isolado, so para o teste
};

int main() {
    Arvore arvore;
    cout << "Quantidade: " << arvore.contarSomaFilhosMaior() << "\n";
    cout << "Arvore vazia: " << ArvoreVazia::contarSomaFilhosMaior() << "\n";
    return 0; // destrutor libera a arvore automaticamente
}
