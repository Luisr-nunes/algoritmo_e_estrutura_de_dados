#include <iostream>
using namespace std;

void contagem_regressiva(int n) {
    if (n < 0) {
        return;
    }

    cout << n;
    if (n > 0) {
        cout << ", ";
    } else {
        cout << "\n";
    }

    contagem_regressiva(n - 1);
}

int main() {
    int n;

    cout << "Digite um numero para a contagem regressiva: ";
    cin >> n;

    cout << "Contagem: ";
    contagem_regressiva(n);

    return 0;
}
