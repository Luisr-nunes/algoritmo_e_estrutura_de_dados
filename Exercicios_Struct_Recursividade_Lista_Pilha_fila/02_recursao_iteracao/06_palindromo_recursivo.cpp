#include <iostream>
#include <string>
using namespace std;

int palindromoRec(const string &str, int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    }
    if (str[inicio] != str[fim]) {
        return 0;
    }
    return palindromoRec(str, inicio + 1, fim - 1);
}

int palindromo(const string &str) {
    return palindromoRec(str, 0, (int) str.size() - 1);
}

int main() {
    string texto;

    cout << "Digite uma palavra ou frase (sem espacos): ";
    cin >> texto;

    if (palindromo(texto)) {
        cout << "\"" << texto << "\" e um palindromo.\n";
    } else {
        cout << "\"" << texto << "\" NAO e um palindromo.\n";
    }

    cout << "\nTestes do enunciado:\n";
    cout << "palindromo(\"arara\") = " << palindromo("arara") << " (esperado: 1)\n";
    cout << "palindromo(\"casa\")  = " << palindromo("casa") << " (esperado: 0)\n";

    return 0;
}
