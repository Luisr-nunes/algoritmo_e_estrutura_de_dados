#include <iostream>
using namespace std;

struct No {
    int valor;
    No *proximo;
};

No *inserirFim(No *inicio, int valor) {
    No *novo = new No();
    novo->valor = valor;
    novo->proximo = nullptr;

    if (inicio == nullptr) {
        return novo;
    }

    No *atual = inicio;
    while (atual->proximo != nullptr) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return inicio;
}

int contarElementos(No *inicio) {
    int contador = 0;
    No *atual = inicio;

    while (atual != nullptr) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

void exibir(No *inicio) {
    No *atual = inicio;
    cout << "Lista: ";
    while (atual != nullptr) {
        cout << atual->valor;
        if (atual->proximo != nullptr) {
            cout << " -> ";
        }
        atual = atual->proximo;
    }
    cout << "\n";
}

void liberarLista(No *inicio) {
    No *atual = inicio;
    while (atual != nullptr) {
        No *proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

int main() {
    No *lista = nullptr;

    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 20);
    lista = inserirFim(lista, 30);
    lista = inserirFim(lista, 40);

    exibir(lista);
    cout << "Quantidade de elementos: " << contarElementos(lista) << "\n";

    liberarLista(lista);
    return 0;
}
