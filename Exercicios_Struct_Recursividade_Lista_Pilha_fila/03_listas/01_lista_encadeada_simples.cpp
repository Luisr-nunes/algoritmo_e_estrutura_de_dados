#include <iostream>
using namespace std;

struct No {
    int valor;
    No *proximo;
};

No *inserirInicio(No *inicio, int valor) {
    No *novo = new No();
    novo->valor = valor;
    novo->proximo = inicio;
    return novo;
}

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

No *remover(No *inicio, int valor) {
    if (inicio == nullptr) {
        cout << "Lista vazia.\n";
        return nullptr;
    }

    if (inicio->valor == valor) {
        No *proximo = inicio->proximo;
        delete inicio;
        return proximo;
    }

    No *anterior = inicio;
    No *atual = inicio->proximo;

    while (atual != nullptr && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << "Valor " << valor << " nao encontrado na lista.\n";
        return inicio;
    }

    anterior->proximo = atual->proximo;
    delete atual;
    return inicio;
}

void exibir(No *inicio) {
    if (inicio == nullptr) {
        cout << "Lista vazia.\n";
        return;
    }

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
    exibir(lista);

    lista = inserirInicio(lista, 5);
    exibir(lista);

    lista = remover(lista, 20);
    exibir(lista);

    lista = remover(lista, 99);
    exibir(lista);

    liberarLista(lista);
    return 0;
}
