#include <iostream>
using namespace std;

int produtoPositivo(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + produtoPositivo(a, b - 1);
}

int produto(int a, int b) {
    if (b < 0) {
        return -produtoPositivo(a, -b);
    }
    return produtoPositivo(a, b);
}

int main() {
    int a, b;

    cout << "Digite o primeiro numero (a): ";
    cin >> a;
    cout << "Digite o segundo numero (b): ";
    cin >> b;

    cout << "Produto: " << produto(a, b) << "\n";

    cout << "\nTestes do enunciado:\n";
    cout << "produto(5, 3) = " << produto(5, 3) << " (esperado: 15)\n";
    cout << "produto(7, 2) = " << produto(7, 2) << " (esperado: 14)\n";

    return 0;
}
