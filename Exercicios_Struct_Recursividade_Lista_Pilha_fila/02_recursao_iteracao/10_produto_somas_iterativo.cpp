#include <iostream>
using namespace std;

int produto_iterativo(int a, int b) {
    int bAbs = (b < 0) ? -b : b;
    int resultado = 0;

    for (int i = 0; i < bAbs; i++) {
        resultado += a;
    }

    if (b < 0) {
        resultado = -resultado;
    }

    return resultado;
}

int main() {
    int a, b;

    cout << "Digite o primeiro numero (a): ";
    cin >> a;
    cout << "Digite o segundo numero (b): ";
    cin >> b;

    cout << "Produto: " << produto_iterativo(a, b) << "\n";

    cout << "\nTestes do enunciado:\n";
    cout << "produto(5, 3) = " << produto_iterativo(5, 3) << " (esperado: 15)\n";
    cout << "produto(7, 2) = " << produto_iterativo(7, 2) << " (esperado: 14)\n";

    return 0;
}
