#include <iostream>
using namespace std;

int contar_digitos(int n) {
    if (n < 0) {
        n = -n;
    }
    if (n <= 9) {
        return 1;
    }
    return 1 + contar_digitos(n / 10);
}

int main() {
    int numero;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    cout << "Quantidade de digitos: " << contar_digitos(numero) << "\n";

    cout << "\nTestes do enunciado:\n";
    cout << "contar_digitos(12345) = " << contar_digitos(12345) << " (esperado: 5)\n";
    cout << "contar_digitos(7)     = " << contar_digitos(7) << " (esperado: 1)\n";

    return 0;
}
