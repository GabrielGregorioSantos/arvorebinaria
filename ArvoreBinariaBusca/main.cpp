#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinariaBusca.h"

using namespace std;

int main() {
    int x; // Variável utilizada para receber o valor digitado do usuário e colocar na árvore
    int opcao; // Variável utilizada no Menu para testar a árvore
    int modo; // Variável utilizada na escolha do percurso na árvore
    int nivel; // Variável para escolher o nível de impressão

    ArvoreBinariaBusca_Construtor();  // Inicializa a árvore

    do {
        system("cls");
        cout << "Programa para uso da Arvore Binaria de Busca\n\n";
        cout << "Escolha uma das opcoes a seguir:\n\n";
        cout << "1 - Inserir\n";
        cout << "2 - Pesquisar\n";
        cout << "3 - Numero de elementos na arvore\n";
        cout << "4 - Verificar se vazia\n";
        cout << "5 - Percurso\n";
        cout << "6 - Imprimir nodos de um mesmo nivel\n";
        cout << "7 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        system("cls");

        switch (opcao) {
            case 1:
                cout << "\nDigite o dado: ";
                cin >> x;
                if (ArvoreBinariaBusca_Inserir(x))
                    cout << "Elemento inserido\n\n";
                else
                    cout << "Erro ao inserir elemento.\n\n";
                system("pause");
                break;

            case 2:
                cout << "\nDigite o elemento para pesquisa: ";
                cin >> x;
                if (ArvoreBinariaBusca_Pesquisar(x))
                    cout << "Elemento encontrado.\n\n";
                else
                    cout << "Elemento nao encontrado.\n\n";
                system("pause");
                break;

            case 3:
                cout << "\nNumero de elementos na arvore: " << ArvoreBinariaBusca_Tamanho() << "\n\n";
                system("pause");
                break;

            case 4:
                if (ArvoreBinariaBusca_Vazia())
                    cout << "Arvore esta vazia\n\n";
                else
                    cout << "Arvore contem elementos\n\n";
                system("pause");
                break;

            case 5:
                cout << "Escolha um dos percursos abaixo:\n\n";
                cout << "1 - Pre-Ordem\n";
                cout << "2 - Em-Ordem\n";
                cout << "3 - Pos-Ordem\n";
                cout << "Opcao: ";
                cin >> modo;
                ArvoreBinariaBusca_Percurso(modo);
                break;

            case 6:
                cout << "Digite o nivel para impressao: ";
                cin >> nivel;
                ArvoreBinariaBusca_Imprimir_Por_Nivel(nivel);
                system("pause");
                break;

            case 7:
                cout << "Saindo...\n";
                break;

            default:
                cout << "Opcao invalida!\n\n";
                system("pause");
        }
    } while (opcao != 7);

    ArvoreBinariaBusca_Destrutor();
    return 0;
}
