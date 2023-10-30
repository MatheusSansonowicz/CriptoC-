#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool buscasigla(string sigla) {
    for (const Criptomoeda& criptomoeda : listaMoedas) {
        if (criptomoeda.sigla == sigla) {

            return true;
        }
    }
    return false;
}

void atualizar() {

    if (listaMoedas.empty()) {
        cout << "Nenhuma criptomoeda para atualizar.\n";
        system("pause");
        return;
    }

    Criptomoeda ProcuraSigla;

    do {
        cout << "Digite a sigla da moeda: ";
        cin >> ProcuraSigla.sigla;

        if (!buscasigla(ProcuraSigla.sigla)) {
            cout << "Sigla não encontrada. Tente novamente.\n";
        }
    } while (!buscasigla(ProcuraSigla.sigla));

    // Agora ProcuraSigla contém a criptomoeda que você deseja atualizar

    // Exibir informações da criptomoeda
    cout << "Dados da Criptomoeda:\n";
    cout << "Nome: " << ProcuraSigla.nome << "\n";
    cout << "Sigla: " << ProcuraSigla.sigla << "\n";
    cout << "Valor Atual: " << ProcuraSigla.valor << "\n";

    // Pedir confirmação de atualização
    char resposta;
    cout << "Deseja atualizar o valor? (S/N): ";
    cin >> resposta;

    if (resposta == 'S' || resposta == 's') {
        // Pedir o novo valor
        cout << "Digite o novo valor da moeda: ";
        cin >> ProcuraSigla.valor;

        // Atualizar valor na lista
        for (Criptomoeda& cripto : listaMoedas) {
            if (cripto.sigla == ProcuraSigla.sigla) {
                cripto.valor = ProcuraSigla.valor;
                break;
            }
        }

        cout << "Valor atualizado com sucesso!\n";
    } else {
        cout << "Atualização cancelada. Retornando ao menu.\n";
    }

    system("pause");
}
