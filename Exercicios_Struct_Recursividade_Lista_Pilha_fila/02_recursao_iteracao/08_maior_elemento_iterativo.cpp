#include <iostream>
using namespace std;

int maior_elemento_iterativo(int vet[], int n) {
    int maior = vet[0];

    for (int i = 1; i < n; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }

    return maior;
}

int main() {
    int n;

    cout << "Quantos elementos tera o vetor? ";
    cin >> n;

    if (n <= 0) {
        cout << "Quantidade invalida.\n";
        return 1;
    }

    int *vet = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "vet[" << i << "] = ";
        cin >> vet[i];
    }

    cout << "Maior elemento: " << maior_elemento_iterativo(vet, n) << "\n";

    delete[] vet;
    return 0;
}
