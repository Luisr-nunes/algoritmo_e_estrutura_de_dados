/* Árvore: contar nós cuja soma dos filhos é MAIOR que o próprio nó */
#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore {
    int valor;
    struct NoArvore* esq;
    struct NoArvore* dir;
} NoArvore;

NoArvore* criarNo(int v, NoArvore* e, NoArvore* d) {
    NoArvore* n = (NoArvore*) malloc(sizeof(NoArvore));
    if (!n) exit(1);
    n->valor = v; n->esq = e; n->dir = d;
    return n;
}

void liberarArvore(NoArvore* r) {
    if (!r) return;
    liberarArvore(r->esq); liberarArvore(r->dir); free(r);
}

int contarSomaFilhosMaior(NoArvore* raiz) {
    /* Caso base: árvore vazia não tem nó nenhum para contar */
    if (raiz == NULL) return 0;

    int conta = 0;

    /* Só faz sentido falar em "soma dos filhos" se existir pelo menos um filho */
    if (raiz->esq != NULL || raiz->dir != NULL) {
        int soma = 0;
        if (raiz->esq != NULL) soma += raiz->esq->valor;   /* filho que não existe vale 0 */
        if (raiz->dir != NULL) soma += raiz->dir->valor;

        if (soma > raiz->valor) conta = 1;                 /* este nó entra na contagem */
    }

    return conta + contarSomaFilhosMaior(raiz->esq) + contarSomaFilhosMaior(raiz->dir);
}

int main(void) {
    
    NoArvore* raiz = criarNo(10,
                        criarNo(6, criarNo(2, NULL, NULL), criarNo(3, NULL, NULL)),
                        criarNo(7, NULL, criarNo(9, NULL, NULL)));

    printf("Quantidade: %d\n", contarSomaFilhosMaior(raiz));
    printf("Arvore vazia: %d\n", contarSomaFilhosMaior(NULL));

    liberarArvore(raiz);
    return 0;
}
