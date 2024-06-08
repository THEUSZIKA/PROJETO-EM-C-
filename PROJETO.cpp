#include <iostream>
#include <vector>
#include <string>
#include <limits> // Necessário para usar numeric_limits

using namespace std;

struct Pessoa {
    string nome;
    string rg;
};

void cadastrarPessoa(vector<Pessoa> &pessoas) {
    Pessoa novaPessoa;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer antes de ler a string
    cout << "Digite o seu nome completo: ";
    getline(cin, novaPessoa.nome);
    cout << "Digite o seu CPF : ";
    getline(cin, novaPessoa.rg);
    pessoas.push_back(novaPessoa);
    cout << "login realizado com sucesso!" << endl;
}

void exibirLista(const vector<Pessoa> &pessoas) {
    cout << "Lista de pessoas cadastradas:" << endl;
    for (const auto &pessoa : pessoas) {
        cout << "Nome: " << pessoa.nome << ", CPF: " << pessoa.rg << endl;
    }
}

int main() {
    vector<Pessoa> pessoas;
    int opcao;

    do {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Criar login" << endl;
        cout << "2. Exibir Lista de Pessoas" << endl;
        cout << "3. Sair do Sistema" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cadastrarPessoa(pessoas);
                break;
            case 2:
                exibirLista(pessoas);
                break;
            case 3:
                cout << "Saindo do sistema..." << endl;
                break;
            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
        }
    } while (opcao != 3);

    return 0;
}
