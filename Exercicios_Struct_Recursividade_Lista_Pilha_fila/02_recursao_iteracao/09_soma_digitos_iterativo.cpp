#include <iostream>
using namespace std;

int soma_digitos_iterativo(int n) {
    if (n < 0) {
        n = -n;
    }

    int soma = 0;
    while (n != 0) {
        soma += n % 10;
        n /= 10;
    }

    return soma;
}

int main() {
    int numero;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    cout << "Soma dos digitos: " << soma_digitos_iterativo(numero) << "\n";

    cout << "\nTeste do enunciado:\n";
    cout << "soma_digitos(1234) = " << soma_digitos_iterativo(1234) << " (esperado: 10)\n";

    return 0;
}
