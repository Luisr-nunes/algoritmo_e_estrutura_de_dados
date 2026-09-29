#include <iostream>
#include <string>
using namespace std;

struct Carro {
    string modelo;
    int ano;
    float preco;
};

int main() {
    Carro *carro = new Carro();

    cout << "Modelo do carro: ";
    getline(cin, carro->modelo);

    cout << "Ano do carro: ";
    cin >> carro->ano;

    cout << "Preco do carro: ";
    cin >> carro->preco;

    cout << "\n--- Dados do Carro ---\n";
    cout << "Modelo: " << carro->modelo << "\n";
    cout << "Ano:    " << carro->ano << "\n";
    cout << "Preco:  R$ " << carro->preco << "\n";

    delete carro;
    carro = nullptr;

    return 0;
}
