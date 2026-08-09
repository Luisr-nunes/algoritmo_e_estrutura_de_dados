#include <stdio.h>

int main() {
    int numero;

    printf("Informe um numero entre 1 e 9: ");
    scanf("%d", &numero);

    while (numero < 1 || numero > 9) {
        printf("Numero Invalido! Favor informar um numero entre 1 e 9. \n\n ");

        printf("Digite um numero entre 1 e 9: ");
        scanf("%d", &numero);
    }

    printf("\n Tabuada do numero %d: \n", numero);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
}