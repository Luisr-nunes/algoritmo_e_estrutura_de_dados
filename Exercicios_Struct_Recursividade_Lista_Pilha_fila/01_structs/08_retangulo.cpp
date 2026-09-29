#include <iostream>
using namespace std;

struct Retangulo {
    float base;
    float altura;
};

float calcularArea(Retangulo r) {
    return r.base * r.altura;
}

float calcularPerimetro(Retangulo r) {
    return 2 * (r.base + r.altura);
}

int main() {
    Retangulo retangulo;

    cout << "Base do retangulo: ";
    cin >> retangulo.base;

    cout << "Altura do retangulo: ";
    cin >> retangulo.altura;

    float area = calcularArea(retangulo);
    float perimetro = calcularPerimetro(retangulo);

    cout << "\nArea:      " << area << "\n";
    cout << "Perimetro: " << perimetro << "\n";

    return 0;
}
