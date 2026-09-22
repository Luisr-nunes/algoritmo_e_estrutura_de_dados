/* Pilha, Fila e Struct: tarefas */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char descricao[50];
    int prioridade; /* 1 = alta, 2 = média, 3 = baixa */
} Tarefa;

/* Cada "caixinha" da pilha/fila guarda uma Tarefa e aponta para a próxima */
typedef struct NoTarefa {
    Tarefa tarefa;
    struct NoTarefa* prox;
} NoTarefa;

/* ---------- a) PILHA (LIFO: o último que entra é o primeiro que sai) ---------- */
typedef struct { NoTarefa* topo; } Pilha;

void pilha_iniciar(Pilha* p) { p->topo = NULL; }

int pilha_push(Pilha* p, Tarefa t) {
    NoTarefa* novo = (NoTarefa*) malloc(sizeof(NoTarefa));
    if (!novo) return 0;
    novo->tarefa = t;
    novo->prox = p->topo;   /* o novo aponta para quem era o topo */
    p->topo = novo;         /* e vira o novo topo */
    return 1;
}

int pilha_pop(Pilha* p, Tarefa* saida) {
    if (!p->topo) return 0;
    NoTarefa* rem = p->topo;
    *saida = rem->tarefa;
    p->topo = rem->prox;
    free(rem);
    return 1;
}

void pilha_exibir(Pilha* p) {
    printf("=== PILHA (topo -> base) ===\n");
    if (!p->topo) printf("(vazia)\n");
    for (NoTarefa* n = p->topo; n; n = n->prox)
        printf("ID: %d | %s | Prioridade: %d\n", n->tarefa.id, n->tarefa.descricao, n->tarefa.prioridade);
}

void pilha_liberar(Pilha* p) { Tarefa t; while (pilha_pop(p, &t)); }

/* ---------- b) FILA (FIFO: o primeiro que entra é o primeiro que sai) ---------- */
typedef struct { NoTarefa* inicio; NoTarefa* fim; } Fila;

void fila_iniciar(Fila* f) { f->inicio = f->fim = NULL; }

int fila_enfileirar(Fila* f, Tarefa t) {
    NoTarefa* novo = (NoTarefa*) malloc(sizeof(NoTarefa));
    if (!novo) return 0;
    novo->tarefa = t;
    novo->prox = NULL;
    if (f->fim) f->fim->prox = novo; else f->inicio = novo;
    f->fim = novo;
    return 1;
}

int fila_desenfileirar(Fila* f, Tarefa* saida) {
    if (!f->inicio) return 0;
    NoTarefa* rem = f->inicio;
    *saida = rem->tarefa;
    f->inicio = rem->prox;
    if (!f->inicio) f->fim = NULL;
    free(rem);
    return 1;
}

void fila_exibir(Fila* f) {
    printf("=== FILA (inicio -> fim) ===\n");
    if (!f->inicio) printf("(vazia)\n");
    for (NoTarefa* n = f->inicio; n; n = n->prox)
        printf("ID: %d | %s | Prioridade: %d\n", n->tarefa.id, n->tarefa.descricao, n->tarefa.prioridade);
}

void fila_liberar(Fila* f) { Tarefa t; while (fila_desenfileirar(f, &t)); }

/* ---------- c) Programa principal ---------- */
int main(void) {
    Pilha pilha; Fila fila;
    pilha_iniciar(&pilha);
    fila_iniciar(&fila);

    for (int i = 1; i <= 5; i++) {
        Tarefa t;
        printf("\n--- Tarefa %d de 5 ---\n", i);
        printf("ID: ");
        scanf("%d", &t.id);
        printf("Descricao: ");
        scanf(" %49[^\n]", t.descricao);      /* lê a frase inteira, com espaços */
        do {
            printf("Prioridade (1=alta, 2=media, 3=baixa): ");
            scanf("%d", &t.prioridade);
        } while (t.prioridade < 1 || t.prioridade > 3);

        if (t.prioridade == 1) pilha_push(&pilha, t);
        else                   fila_enfileirar(&fila, t);
    }

    printf("\n");
    pilha_exibir(&pilha);
    printf("\n");
    fila_exibir(&fila);

    pilha_liberar(&pilha);
    fila_liberar(&fila);
    return 0;
}
