#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Registrar.h"
#include "Remover.h"
#include "Atualizar.h"
#include "listar.h"

using namespace std;

main (){
    int opcao;

    do {
        cout << "--Menu Cripto--\n\n";
        cout << "1. Cadastrar\n";
        cout << "2. Ataulizae\n";
        cout << "3. Remover\n";
        cout << "4. Listar\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

         switch (opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                atualizar();
                break;
            case 3:
                remover();
                break;
            case 4:
                listar();
                break;
            case 5:
                cout << "Até mais.\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }


    } while (opcao != 5);
}
