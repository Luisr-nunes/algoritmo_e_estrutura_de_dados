#include <stdio.h>
#include <string.h>

#define QTD 3

typedef struct {
    int dia;
    char mes[20];
    int ano;
} Data;

typedef struct {
    char nome[100];
    int idade;
    float salario;
    Data nascimento;
} Funcionario;

int main(void) {
    Funcionario func[QTD];

    for (int i = 0; i < QTD; i++) {
        printf("\nInforme os dados do funcionario %d\n", i + 1);

        printf("Digite o nome completo do funcionario: ");
        if (fgets(func[i].nome, sizeof(func[i].nome), stdin)) {
            size_t ln = strlen(func[i].nome);
            if (ln && func[i].nome[ln-1] == '\n') func[i].nome[ln-1] = '\0';
        } else {
            func[i].nome[0] = '\0';
        }

        printf("Digite a idade do funcionario (em anos): ");
        if (scanf("%d", &func[i].idade) != 1) func[i].idade = 0;

        printf("Digite o salario do funcionario (use ponto como separador decimal): ");
        if (scanf("%f", &func[i].salario) != 1) func[i].salario = 0.0f;

        printf("Digite o dia do nascimento (1-31): ");
        if (scanf("%d", &func[i].nascimento.dia) != 1) func[i].nascimento.dia = 0;

        while (getchar() != '\n');

        printf("\nDigite o mes do nascimento por extenso (por exemplo: Janeiro): ");
        if (fgets(func[i].nascimento.mes, sizeof(func[i].nascimento.mes), stdin)) {
            size_t ln2 = strlen(func[i].nascimento.mes);
            if (ln2 && func[i].nascimento.mes[ln2-1] == '\n') func[i].nascimento.mes[ln2-1] = '\0';
        } else {
            func[i].nascimento.mes[0] = '\0';
        }

        printf("Digite o ano do nascimento (por exemplo: 1980): ");
        if (scanf("%d", &func[i].nascimento.ano) != 1) func[i].nascimento.ano = 0;

        while (getchar() != '\n');
    }

    for (int i = 0; i < QTD; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        printf("Nome completo: %s\n", func[i].nome);
        printf("Idade (anos): %d\n", func[i].idade);
        printf("Salario (R$): R$ %.2f\n", func[i].salario);
        printf("Data de nascimento: %d de %s de %d\n",
               func[i].nascimento.dia,
               func[i].nascimento.mes,
               func[i].nascimento.ano);
    }

    return 0;
}