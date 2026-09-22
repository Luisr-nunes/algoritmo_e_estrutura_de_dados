/* PDF - Questão 01: intercalar duas filas sem alterá-las */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;   /* quem está na frente da fila (próximo a sair) */
    No* fim;      /* quem está no final da fila (último a entrar) */
} Fila;

Fila* criarFila(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f) { f->inicio = NULL; f->fim = NULL; }
    return f;
}

int enfileirar(Fila* f, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return 0;
    novo->valor = valor;
    novo->prox = NULL;
    if (f->fim) f->fim->prox = novo; else f->inicio = novo;
    f->fim = novo;
    return 1;
}

void liberarFila(Fila* f) {
    No* atual = f->inicio;
    while (atual) { No* p = atual->prox; free(atual); atual = p; }
    free(f);
}

void mostrarFila(const char* nome, Fila* f) {
    printf("%s = [", nome);
    for (No* p = f->inicio; p; p = p->prox)
        printf("%d%s", p->valor, p->prox ? ", " : "");
    printf("]\n");
}

/* Usamos dois "dedos" (p1 e p2) que apenas PASSEIAM pelas filas originais.
   Como só olhamos e não retiramos ninguém, F1 e F2 continuam intactas. */
Fila* intercalarFilas(Fila* F1, Fila* F2) {
    Fila* R = criarFila();
    if (!R) return NULL;

    No* p1 = F1->inicio;
    No* p2 = F2->inicio;

    while (p1 || p2) {
        if (p1) {                                   /* vez da fila 1 */
            if (!enfileirar(R, p1->valor)) { liberarFila(R); return NULL; }
            p1 = p1->prox;
        }
        if (p2) {                                   /* vez da fila 2 */
            if (!enfileirar(R, p2->valor)) { liberarFila(R); return NULL; }
            p2 = p2->prox;
        }
    }
    return R;
}

int main(void) {
    Fila* F1 = criarFila();
    Fila* F2 = criarFila();
    int a[] = {10, 30, 50}, b[] = {20, 40};
    for (int i = 0; i < 3; i++) enfileirar(F1, a[i]);
    for (int i = 0; i < 2; i++) enfileirar(F2, b[i]);

    Fila* R = intercalarFilas(F1, F2);
    if (!R) { printf("Falha de memoria!\n"); return 1; }

    mostrarFila("F1", F1);
    mostrarFila("F2", F2);
    mostrarFila("Resultado", R);

    liberarFila(F1); liberarFila(F2); liberarFila(R);
    return 0;
}
