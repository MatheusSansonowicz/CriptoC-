#include <iostream>
#include <vector>
#include <string>

using namespace std;

void listar(){
    if (listaMoedas.empty()) {
        cout << "Nenhuma criptomoeda encontrada.\n";
        system("pause");
        return;
    }

    cout << "Lista de Criptomoedas:\n";
    for (const Criptomoeda& criptomoeda : listaMoedas) {
        cout << "Nome: " << criptomoeda.nome << endl;
        cout << "Sigla: " << criptomoeda.sigla << endl;
        cout << "Valor: " << criptomoeda.valor << endl;
        cout << "-------------------------\n";
    }
    system("pause");
}