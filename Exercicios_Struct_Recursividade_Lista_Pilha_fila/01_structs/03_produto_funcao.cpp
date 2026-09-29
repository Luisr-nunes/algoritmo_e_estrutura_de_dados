#include <iostream>
#include <string>
using namespace std;

struct Produto {
    string nome;
    int codigo;
    float preco;
};

void exibirProduto(Produto p) {
    cout << "\n--- Dados do Produto ---\n";
    cout << "Nome:   " << p.nome << "\n";
    cout << "Codigo: " << p.codigo << "\n";
    cout << "Preco:  R$ " << p.preco << "\n";
}

int main() {
    Produto produto;

    cout << "Nome do produto: ";
    getline(cin, produto.nome);

    cout << "Codigo do produto: ";
    cin >> produto.codigo;

    cout << "Preco do produto: ";
    cin >> produto.preco;

    exibirProduto(produto);

    return 0;
}
