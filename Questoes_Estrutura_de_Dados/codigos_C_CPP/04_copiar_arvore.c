/* PDF - Questão 02: copiar árvore binária de busca (recursivo) */
#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore {
    int valor;
    struct NoArvore* esq;
    struct NoArvore* dir;
} NoArvore;

NoArvore* inserir(NoArvore* raiz, int v) {
    if (!raiz) {
        NoArvore* n = (NoArvore*) malloc(sizeof(NoArvore));
        if (!n) return NULL;
        n->valor = v; n->esq = n->dir = NULL;
        return n;
    }
    if (v < raiz->valor) raiz->esq = inserir(raiz->esq, v);
    else                 raiz->dir = inserir(raiz->dir, v);
    return raiz;
}

void liberarArvore(NoArvore* raiz) {
    if (!raiz) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

NoArvore* copiarArvore(NoArvore* raiz) {
    /* Caso base: árvore vazia -> a cópia também é vazia */
    if (raiz == NULL) return NULL;

    /* Cria um nó NOVO (nada de compartilhar com a original) */
    NoArvore* novo = (NoArvore*) malloc(sizeof(NoArvore));
    if (novo == NULL) return NULL;                 /* falha de alocação */

    novo->valor = raiz->valor;

    /* Copia o lado esquerdo */
    novo->esq = copiarArvore(raiz->esq);
    if (raiz->esq != NULL && novo->esq == NULL) {  /* tinha filho, mas a cópia falhou */
        free(novo);
        return NULL;
    }

    /* Copia o lado direito */
    novo->dir = copiarArvore(raiz->dir);
    if (raiz->dir != NULL && novo->dir == NULL) {
        liberarArvore(novo->esq);                  /* desfaz o que já foi copiado */
        free(novo);
        return NULL;
    }
    return novo;
}

void emOrdem(NoArvore* r) {
    if (!r) return;
    emOrdem(r->esq); printf("%d ", r->valor); emOrdem(r->dir);
}

int main(void) {
    int v[] = {50, 30, 70, 20, 40, 60, 80};
    NoArvore* orig = NULL;
    for (int i = 0; i < 7; i++) orig = inserir(orig, v[i]);

    NoArvore* copia = copiarArvore(orig);

    printf("Original: "); emOrdem(orig);  printf("\n");
    printf("Copia:    "); emOrdem(copia); printf("\n");
    printf("Raizes em enderecos diferentes? %s\n", (orig != copia) ? "sim" : "nao");

    /* Teste de independência: mexer na cópia não afeta a original */
    copia->valor = 999;
    printf("Depois de mudar a raiz da copia -> original: %d | copia: %d\n",
           orig->valor, copia->valor);

    printf("Arvore vazia: %s\n", copiarArvore(NULL) == NULL ? "ok (NULL)" : "erro");

    liberarArvore(orig); liberarArvore(copia);
    return 0;
}
