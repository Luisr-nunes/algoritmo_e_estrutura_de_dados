/* Lista simplesmente encadeada de inteiros */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

/* a) Inserir no final. Retorna o início (pode mudar se a lista estava vazia) */
No* inserir_final(No* inicio, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) { printf("Sem memoria!\n"); return inicio; }
    novo->valor = valor;
    novo->prox = NULL;

    if (inicio == NULL) return novo;         /* lista vazia: o novo é o primeiro */

    No* p = inicio;
    while (p->prox != NULL) p = p->prox;     /* anda até o último vagão */
    p->prox = novo;                          /* engata o novo vagão no final */
    return inicio;
}

void mostrar_lista(No* inicio) {
    printf("Lista: ");
    for (No* p = inicio; p; p = p->prox)
        printf("%d%s", p->valor, p->prox ? " -> " : " -> NULL");
    printf("\n");
}

/* b) Conta quantas vezes 'alvo' aparece */
int contar_valores(No* inicio, int alvo) {
    int cont = 0;
    for (No* p = inicio; p; p = p->prox)
        if (p->valor == alvo) cont++;
    return cont;
}

void liberar_lista(No* inicio) {
    while (inicio) { No* p = inicio->prox; free(inicio); inicio = p; }
}

int main(void) {
    No* lista = NULL;
    int valores[] = {5, 8, 5, 10, 8, 12, 5};      /* c) valores do teste */
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) lista = inserir_final(lista, valores[i]);

    mostrar_lista(lista);

    int busca;
    printf("Digite um numero para contar: ");
    scanf("%d", &busca);
    printf("O numero %d aparece %d vez(es) na lista.\n", busca, contar_valores(lista, busca));

    liberar_lista(lista);
    return 0;
}
