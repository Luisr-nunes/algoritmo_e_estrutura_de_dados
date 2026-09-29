#include <iostream>
using namespace std;

struct No {
    int valor;
    No *proximo;
};

No *inserirOrdenado(No *inicio, int valor) {
    No *novo = new No();
    novo->valor = valor;

    if (inicio == nullptr || valor < inicio->valor) {
        novo->proximo = inicio;
        return novo;
    }

    No *anterior = inicio;
    while (anterior->proximo != nullptr && anterior->proximo->valor < valor) {
        anterior = anterior->proximo;
    }

    novo->proximo = anterior->proximo;
    anterior->proximo = novo;

    return inicio;
}

void exibir(No *inicio) {
    No *atual = inicio;
    cout << "Lista ordenada: ";
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

    lista = inserirOrdenado(lista, 30);
    lista = inserirOrdenado(lista, 10);
    lista = inserirOrdenado(lista, 50);
    lista = inserirOrdenado(lista, 20);
    lista = inserirOrdenado(lista, 5);

    exibir(lista);

    liberarLista(lista);
    return 0;
}
