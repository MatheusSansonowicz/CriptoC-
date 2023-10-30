#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Criptomoeda {
    string nome;
    string sigla;
    float valor;
};

vector <Criptomoeda> listaMoedas;

bool nomeExistente (string nome){
    for ( const Criptomoeda& criptomoeda : listaMoedas){
        if (criptomoeda.nome == nome){
            return true;
        }
    }
    return false;
}

bool siglaExistente(string sigla) {
    for (const Criptomoeda& criptomoeda : listaMoedas) {
        if (criptomoeda.sigla == sigla) {
            return true;
        }
    }
    return false;
}

void cadastrar() {
    Criptomoeda novaCripto;
    
    do {
        cout << "Digite o nome da nova criptomoeda: ";
        cin >> novaCripto.nome;

        if (nomeExistente(novaCripto.nome)) {
            cout << "Nome de criptomoeda já existe. Tente novamente.\n";
        }

    } while (nomeExistente(novaCripto.nome));

    do {
        cout << "Digite a sigla da nova criptomoeda: ";
        cin >> novaCripto.sigla;

        if (siglaExistente(novaCripto.sigla)) {
            cout << "Sigla de criptomoeda já existe. Tente novamente.\n";
        }

    } while (siglaExistente(novaCripto.sigla));

    bool ValorValido=false;

   do {
    cout << "Digite o valor da nova criptomoeda: ";
    cin >> novaCripto.valor;

    if (novaCripto.valor <= 0) {
        cout << "O valor da moeda deve ser positivo\n";
    } else {
        ValorValido=true;
    }

    } while (ValorValido==false);

    listaMoedas.push_back(novaCripto);

    cout << "Criptomoeda registrada com sucesso!\n";

    system("pause");
}