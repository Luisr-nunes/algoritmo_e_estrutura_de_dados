#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float notaMatematica;
    float notaFisica;
    float media;
} Aluno;

int main(void) {
    Aluno aluno1, aluno2, aluno3;

    printf("Informe os dados do primeiro aluno\n");
    printf("Digite o nome completo do aluno: ");
    if (fgets(aluno1.nome, sizeof(aluno1.nome), stdin)) {
        size_t ln = strlen(aluno1.nome);
        if (ln && aluno1.nome[ln-1] == '\n') aluno1.nome[ln-1] = '\0';
    } else {
        aluno1.nome[0] = '\0';
    }
    printf("Digite a nota de Matematica (valor entre 0 e 10): ");
    if (scanf("%f", &aluno1.notaMatematica) != 1) aluno1.notaMatematica = 0.0f;
    printf("Digite a nota de Fisica (valor entre 0 e 10): ");
    if (scanf("%f", &aluno1.notaFisica) != 1) aluno1.notaFisica = 0.0f;
    while (getchar() != '\n');

    aluno1.media = (aluno1.notaMatematica + aluno1.notaFisica) / 2.0f;

    printf("\nInforme os dados do segundo aluno\n");
    printf("Digite o nome completo do aluno: ");
    if (fgets(aluno2.nome, sizeof(aluno2.nome), stdin)) {
        size_t ln = strlen(aluno2.nome);
        if (ln && aluno2.nome[ln-1] == '\n') aluno2.nome[ln-1] = '\0';
    } else {
        aluno2.nome[0] = '\0';
    }
    printf("Digite a nota de Matematica (valor entre 0 e 10): ");
    if (scanf("%f", &aluno2.notaMatematica) != 1) aluno2.notaMatematica = 0.0f;
    printf("Digite a nota de Fisica (valor entre 0 e 10): ");
    if (scanf("%f", &aluno2.notaFisica) != 1) aluno2.notaFisica = 0.0f;
    while (getchar() != '\n');

    aluno2.media = (aluno2.notaMatematica + aluno2.notaFisica) / 2.0f;

    printf("\nInforme os dados do terceiro aluno\n");
    printf("Digite o nome completo do aluno: ");
    if (fgets(aluno3.nome, sizeof(aluno3.nome), stdin)) {
        size_t ln = strlen(aluno3.nome);
        if (ln && aluno3.nome[ln-1] == '\n') aluno3.nome[ln-1] = '\0';
    } else {
        aluno3.nome[0] = '\0';
    }
    printf("Digite a nota de Matematica (valor entre 0 e 10): ");
    if (scanf("%f", &aluno3.notaMatematica) != 1) aluno3.notaMatematica = 0.0f;
    printf("Digite a nota de Fisica (valor entre 0 e 10): ");
    if (scanf("%f", &aluno3.notaFisica) != 1) aluno3.notaFisica = 0.0f;
    while (getchar() != '\n');

    aluno3.media = (aluno3.notaMatematica + aluno3.notaFisica) / 2.0f;

    printf("\n\nLISTA DE ALUNOS\n");

    printf("\nAluno 1:\n");
    printf("Nome completo: %s\n", aluno1.nome);
    printf("Nota de Matematica: %.2f\n", aluno1.notaMatematica);
    printf("Nota de Fisica: %.2f\n", aluno1.notaFisica);
    printf("Media: %.2f\n", aluno1.media);

    printf("\nAluno 2:\n");
    printf("Nome completo: %s\n", aluno2.nome);
    printf("Nota de Matematica: %.2f\n", aluno2.notaMatematica);
    printf("Nota de Fisica: %.2f\n", aluno2.notaFisica);
    printf("Media: %.2f\n", aluno2.media);

    printf("\nAluno 3:\n");
    printf("Nome completo: %s\n", aluno3.nome);
    printf("Nota de Matematica: %.2f\n", aluno3.notaMatematica);
    printf("Nota de Fisica: %.2f\n", aluno3.notaFisica);
    printf("Media: %.2f\n", aluno3.media);

    return 0;
}
