#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_LIVROS = 10;

struct Livro {
    string titulo;
    string autor;
    int anoPublicacao;
};

void exibirLivrosAposAno(Livro livros[], int n, int anoLimite) {
    cout << "\n--- Livros publicados apos " << anoLimite << " ---\n";
    int encontrados = 0;

    for (int i = 0; i < n; i++) {
        if (livros[i].anoPublicacao > anoLimite) {
            cout << livros[i].titulo << " - " << livros[i].autor
                 << " (" << livros[i].anoPublicacao << ")\n";
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "Nenhum livro encontrado apos esse ano.\n";
    }
}

int main() {
    int n;

    cout << "Quantos livros deseja cadastrar (max " << MAX_LIVROS << ")? ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n <= 0 || n > MAX_LIVROS) {
        cout << "Quantidade invalida.\n";
        return 1;
    }

    Livro livros[MAX_LIVROS];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Livro " << (i + 1) << " ---\n";

        cout << "Titulo: ";
        getline(cin, livros[i].titulo);

        cout << "Autor: ";
        getline(cin, livros[i].autor);

        cout << "Ano de publicacao: ";
        cin >> livros[i].anoPublicacao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int anoLimite;
    cout << "\nMostrar livros publicados apos que ano? ";
    cin >> anoLimite;

    exibirLivrosAposAno(livros, n, anoLimite);

    return 0;
}
