// Pilha, Fila e Struct: tarefas (versao C++ idiomatica)
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Tarefa {
public:
    int id;
    string descricao;
    int prioridade; // 1 = alta, 2 = media, 3 = baixa

    Tarefa() : id(0), descricao(""), prioridade(0) {}
    Tarefa(int id_, const string& desc_, int prio_)
        : id(id_), descricao(desc_), prioridade(prio_) {}
};

// Cada "caixinha" da pilha/fila guarda uma Tarefa e aponta para a proxima
class NoTarefa {
public:
    Tarefa tarefa;
    NoTarefa* prox;
    NoTarefa(const Tarefa& t, NoTarefa* p) : tarefa(t), prox(p) {}
};

// ---------- a) PILHA (LIFO) ----------
class Pilha {
private:
    NoTarefa* topo;
public:
    Pilha() : topo(nullptr) {}
    ~Pilha() { liberar(); }

    void push(const Tarefa& t) {
        topo = new NoTarefa(t, topo); // o novo vira o topo
    }

    bool pop(Tarefa& saida) {
        if (!topo) return false;
        NoTarefa* rem = topo;
        saida = rem->tarefa;
        topo = rem->prox;
        delete rem;
        return true;
    }

    void exibir() const {
        cout << "=== PILHA (topo -> base) ===\n";
        if (!topo) cout << "(vazia)\n";
        for (NoTarefa* n = topo; n; n = n->prox)
            cout << "ID: " << n->tarefa.id << " | " << n->tarefa.descricao
                 << " | Prioridade: " << n->tarefa.prioridade << "\n";
    }

    void liberar() {
        Tarefa t;
        while (pop(t)) {}
    }
};

// ---------- b) FILA (FIFO) ----------
class Fila {
private:
    NoTarefa* inicio;
    NoTarefa* fim;
public:
    Fila() : inicio(nullptr), fim(nullptr) {}
    ~Fila() { liberar(); }

    void enfileirar(const Tarefa& t) {
        NoTarefa* novo = new NoTarefa(t, nullptr);
        if (fim) fim->prox = novo; else inicio = novo;
        fim = novo;
    }

    bool desenfileirar(Tarefa& saida) {
        if (!inicio) return false;
        NoTarefa* rem = inicio;
        saida = rem->tarefa;
        inicio = rem->prox;
        if (!inicio) fim = nullptr;
        delete rem;
        return true;
    }

    void exibir() const {
        cout << "=== FILA (inicio -> fim) ===\n";
        if (!inicio) cout << "(vazia)\n";
        for (NoTarefa* n = inicio; n; n = n->prox)
            cout << "ID: " << n->tarefa.id << " | " << n->tarefa.descricao
                 << " | Prioridade: " << n->tarefa.prioridade << "\n";
    }

    void liberar() {
        Tarefa t;
        while (desenfileirar(t)) {}
    }
};

// ---------- c) Programa principal ----------
int main() {
    Pilha pilha;
    Fila fila;

    for (int i = 1; i <= 5; i++) {
        int id, prioridade;
        string descricao;

        cout << "\n--- Tarefa " << i << " de 5 ---\n";
        cout << "ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Descricao: ";
        getline(cin, descricao);
        do {
            cout << "Prioridade (1=alta, 2=media, 3=baixa): ";
            cin >> prioridade;
        } while (prioridade < 1 || prioridade > 3);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Tarefa t(id, descricao, prioridade);
        if (t.prioridade == 1) pilha.push(t);
        else                   fila.enfileirar(t);
    }

    cout << "\n";
    pilha.exibir();
    cout << "\n";
    fila.exibir();

    // liberar() acontece automaticamente nos destrutores ao sair do escopo
    return 0;
}
