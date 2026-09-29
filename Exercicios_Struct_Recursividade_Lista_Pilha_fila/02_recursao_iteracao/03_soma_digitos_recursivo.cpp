#include <iostream>
using namespace std;

int soma_digitos(int n) {
    if (n < 0) {
        n = -n;
    }
    if (n == 0) {
        return 0;
    }
    return (n % 10) + soma_digitos(n / 10);
}

int main() {
    int numero;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    cout << "Soma dos digitos: " << soma_digitos(numero) << "\n";

    cout << "\nTeste do enunciado:\n";
    cout << "soma_digitos(1234) = " << soma_digitos(1234) << " (esperado: 10)\n";

    return 0;
}
