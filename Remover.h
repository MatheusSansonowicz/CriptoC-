#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool buscaSigla(string sigla) {
    for (const Criptomoeda& criptomoeda : listaMoedas) {
        if (criptomoeda.sigla == sigla) {
            return true;
        }
    }
    return false;
}

void remover() {

    if (listaMoedas.empty()) {
        cout << "Nenhuma criptomoeda para excluir.\n";
        system("pause");
        return;
    }

    Criptomoeda criptoExcluir;

    do {
        cout << "Digite a sigla da criptomoeda a ser excluida: ";
        cin >> criptoExcluir.sigla;

        if (!buscaSigla(criptoExcluir.sigla)) {
            cout << "Sigla invalida. Tente novamente.\n";
        }

    } while (!buscaSigla(criptoExcluir.sigla));

    // Mostrar informações antes de confirmar a exclusão
    for (const Criptomoeda& criptomoeda : listaMoedas) {
        if (criptomoeda.sigla == criptoExcluir.sigla) {
            cout << "Dados da Criptomoeda:\n";
            cout << "Nome: " << criptomoeda.nome << endl;
            cout << "Sigla: " << criptomoeda.sigla << endl;
            cout << "Valor: " << criptomoeda.valor << endl;
            break;
        }
    }

    // Confirmar exclusão
    char resposta;
    cout << "Deseja realmente excluir? (S/N): ";
    cin >> resposta;

    if (resposta == 'S' || resposta == 's') {
        // Remover a criptomoeda da lista
        auto it = remove_if(listaMoedas.begin(), listaMoedas.end(),
                            [criptoExcluir](const Criptomoeda& cripto) {
                                return cripto.sigla == criptoExcluir.sigla;
                            });

        listaMoedas.erase(it, listaMoedas.end());

        cout << "Criptomoeda excluída com sucesso!\n";
    } else {
        cout << "Exclusão cancelada.\n";
    }

    system("pause");
}