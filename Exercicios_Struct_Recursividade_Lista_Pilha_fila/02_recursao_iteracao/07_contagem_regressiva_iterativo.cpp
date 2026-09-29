#include <iostream>
using namespace std;

void contagem_regressiva_iterativa(int n) {
    for (int i = n; i >= 0; i--) {
        cout << i;
        if (i > 0) {
            cout << ", ";
        } else {
            cout << "\n";
        }
    }
}

int main() {
    int n;

    cout << "Digite um numero para a contagem regressiva: ";
    cin >> n;

    cout << "Contagem: ";
    contagem_regressiva_iterativa(n);

    return 0;
}
