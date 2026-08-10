#include <stdio.h>
#include <string.h>

#define QTD 10

typedef struct {
    char nome[100];
    float preco;
    int quantidade;
} Produto;

int main(void) {
    Produto produtos[QTD];
    float totalVendas = 0.0f;

    for (int i = 0; i < QTD; i++) {
        printf("\nInforme os dados do produto %d\n", i + 1);

        printf("Digite o nome do produto: ");
        if (fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin)) {
            size_t ln = strlen(produtos[i].nome);
            if (ln && produtos[i].nome[ln-1] == '\n') produtos[i].nome[ln-1] = '\0';
        } else {
            produtos[i].nome[0] = '\0';
        }

        printf("Digite o preco unitario do produto (use ponto como separador decimal): ");
        if (scanf("%f", &produtos[i].preco) != 1) produtos[i].preco = 0.0f;

        printf("Digite a quantidade vendida deste produto: ");
        if (scanf("%d", &produtos[i].quantidade) != 1) produtos[i].quantidade = 0;

        while (getchar() != '\n');

        totalVendas += produtos[i].preco * produtos[i].quantidade;
    }

    printf("\n\nRELATORIO DE VENDA\n");
    for (int i = 0; i < QTD; i++) {
        float subtotal = produtos[i].preco * produtos[i].quantidade;

        printf("\nProduto %d:\n", i + 1);
        printf("Nome do produto: %s\n", produtos[i].nome);
        printf("Preco unitario (R$): R$ %.2f\n", produtos[i].preco);
        printf("Quantidade vendida: %d\n", produtos[i].quantidade);
        printf("Subtotal (R$): R$ %.2f\n", subtotal);
    }

    printf("\n\nVALOR TOTAL DE TODAS AS VENDAS (R$): R$ %.2f\n", totalVendas);

    return 0;
}
