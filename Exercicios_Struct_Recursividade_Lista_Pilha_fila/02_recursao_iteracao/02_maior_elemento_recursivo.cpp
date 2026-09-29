#include <iostream>
using namespace std;

int maior_elemento(int vet[], int n) {
    if (n == 1) {
        return vet[0];
    }

    int maiorResto = maior_elemento(vet, n - 1);

    if (vet[n - 1] > maiorResto) {
        return vet[n - 1];
    }
    return maiorResto;
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

    cout << "Maior elemento: " << maior_elemento(vet, n) << "\n";

    delete[] vet;
    return 0;
}
