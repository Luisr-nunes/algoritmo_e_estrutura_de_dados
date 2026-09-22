/* Intercalar duas filas em uma terceira. Assinatura: No* intercalarFilas(No *f1, No *f2); */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

/* Cria um nó e coloca no fim da fila. 'fim' é passado por endereço para
   podermos atualizá-lo sem precisar andar até o final toda vez. */
int enfileirar(No** inicio, No** fim, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return 0;
    novo->valor = valor;
    novo->prox = NULL;
    if (*fim) (*fim)->prox = novo; else *inicio = novo;
    *fim = novo;
    return 1;
}

void liberar(No* f) {
    while (f) { No* p = f->prox; free(f); f = p; }
}

void mostrar(const char* nome, No* f) {
    printf("%s:", nome);
    for (No* p = f; p; p = p->prox) printf(" %d", p->valor);
    printf("\n");
}

No* intercalarFilas(No* f1, No* f2) {
    No* inicio = NULL;   /* frente da fila resultado */
    No* fim = NULL;      /* último da fila resultado */

    while (f1 != NULL || f2 != NULL) {
        if (f1 != NULL) {                                   /* vez da fila 1 */
            if (!enfileirar(&inicio, &fim, f1->valor)) { liberar(inicio); return NULL; }
            f1 = f1->prox;                                  /* f1 é cópia local: só "passeia" */
        }
        if (f2 != NULL) {                                   /* vez da fila 2 */
            if (!enfileirar(&inicio, &fim, f2->valor)) { liberar(inicio); return NULL; }
            f2 = f2->prox;
        }
    }
    return inicio;
}

int main(void) {
    No *F1 = NULL, *fim1 = NULL, *F2 = NULL, *fim2 = NULL;
    int a[] = {1, 3, 5}, b[] = {2, 4, 6};
    for (int i = 0; i < 3; i++) enfileirar(&F1, &fim1, a[i]);
    for (int i = 0; i < 3; i++) enfileirar(&F2, &fim2, b[i]);

    No* R = intercalarFilas(F1, F2);
    mostrar("F1", F1);
    mostrar("F2", F2);
    mostrar("Resultado", R);

    /* Filas de tamanhos diferentes */
    No *G1 = NULL, *g1 = NULL, *G2 = NULL, *g2 = NULL;
    enfileirar(&G1, &g1, 7);
    for (int i = 0; i < 3; i++) enfileirar(&G2, &g2, 20 + i);
    No* R2 = intercalarFilas(G1, G2);
    mostrar("Tamanhos diferentes", R2);

    /* Uma fila vazia */
    No* R3 = intercalarFilas(NULL, G2);
    mostrar("Uma vazia", R3);

    liberar(F1); liberar(F2); liberar(R); liberar(G1); liberar(G2); liberar(R2); liberar(R3);
    return 0;
}
