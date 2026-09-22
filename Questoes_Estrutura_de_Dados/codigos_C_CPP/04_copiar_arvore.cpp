// Questao 02: copiar arvore binaria de busca (versao C++ idiomatica)
#include <iostream>
using namespace std;

class ArvoreBusca {
private:
    struct No {
        int valor;
        No* esq;
        No* dir;
        No(int v) : valor(v), esq(nullptr), dir(nullptr) {}
    };
    No* raiz;

    No* inserir(No* r, int v) {
        if (!r) return new No(v);
        if (v < r->valor) r->esq = inserir(r->esq, v);
        else               r->dir = inserir(r->dir, v);
        return r;
    }

    void liberar(No* r) {
        if (!r) return;
        liberar(r->esq);
        liberar(r->dir);
        delete r;
    }

    // Copia profunda recursiva: nenhum no e compartilhado com o original
    No* copiar(No* r) const {
        if (!r) return nullptr;
        No* novo = new No(r->valor);
        novo->esq = copiar(r->esq);
        novo->dir = copiar(r->dir);
        return novo;
    }

    void emOrdem(No* r) const {
        if (!r) return;
        emOrdem(r->esq);
        cout << r->valor << " ";
        emOrdem(r->dir);
    }

public:
    ArvoreBusca() : raiz(nullptr) {}

    // Construtor de copia: chamado em "ArvoreBusca copia = original;"
    ArvoreBusca(const ArvoreBusca& outra) : raiz(copiar(outra.raiz)) {}

    ~ArvoreBusca() { liberar(raiz); }

    void inserir(int v) { raiz = inserir(raiz, v); }
    void emOrdem() const { emOrdem(raiz); }
    bool vazia() const { return raiz == nullptr; }
    int valorRaiz() const { return raiz->valor; }
    void setValorRaiz(int v) { raiz->valor = v; }
    No* raizBruta() const { return raiz; } // só para comparar endereços no teste
};

int main() {
    int v[] = {50, 30, 70, 20, 40, 60, 80};
    ArvoreBusca original;
    for (int x : v) original.inserir(x);

    ArvoreBusca copia(original); // usa o construtor de copia (deep copy)

    cout << "Original: "; original.emOrdem(); cout << "\n";
    cout << "Copia:    "; copia.emOrdem();     cout << "\n";
    cout << "Raizes em enderecos diferentes? "
         << (original.raizBruta() != copia.raizBruta() ? "sim" : "nao") << "\n";

    // Teste de independencia: mexer na copia nao afeta a original
    copia.setValorRaiz(999);
    cout << "Depois de mudar a raiz da copia -> original: " << original.valorRaiz()
         << " | copia: " << copia.valorRaiz() << "\n";

    ArvoreBusca vazia;
    ArvoreBusca copiaVazia(vazia);
    cout << "Arvore vazia: " << (copiaVazia.vazia() ? "ok (NULL)" : "erro") << "\n";

    return 0; // destrutores liberam original e copia automaticamente
}
