#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue> // Para usar a fila (queue)
#include "ArvoreBinariaBusca.h"

using namespace std;

TipoCelula *Raiz;
int Contador;

void ArvoreBinariaBusca_Construtor() {
    Raiz = NULL;
    Contador = 0;
}

void ArvoreBinariaBusca_Destrutor() {
    ArvoreBinariaBusca_Destrutor(Raiz);
    Contador = 0;
}

void ArvoreBinariaBusca_Destrutor(TipoCelula *&Raiz) {
    if (Raiz != NULL) {
        ArvoreBinariaBusca_Destrutor(Raiz->Esq);
        ArvoreBinariaBusca_Destrutor(Raiz->Dir);
        delete(Raiz);
        Raiz = NULL;
    }
}

bool ArvoreBinariaBusca_Vazia() {
    return Raiz == NULL;
}

int ArvoreBinariaBusca_Tamanho() {
    return Contador;
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento) {
    return ArvoreBinariaBusca_Inserir(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento, TipoCelula *&Raiz) {
    if (Raiz == NULL) {
        if ((Raiz = new(TipoCelula)) == NULL)
            return false;
        else {
            Raiz->Item = Elemento;
            Raiz->Esq = Raiz->Dir = NULL;
            Contador++;
            return true;
        }
    } else {
        if (Elemento < Raiz->Item)
            return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Esq);
        else if (Elemento > Raiz->Item)
            return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Dir);
        else return false; // Elemento já existe
    }
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento) {
    return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento, TipoCelula *Raiz) {
    if (Raiz == NULL) return false;
    else if (Elemento < Raiz->Item)
        return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Esq);
    else if (Elemento > Raiz->Item)
        return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Dir);
    else return true;
}

void ArvoreBinariaBusca_Percurso(int modo) {
    switch (modo) {
        case 1: ArvoreBinariaBusca_PreOrdem(Raiz); break;
        case 2: ArvoreBinariaBusca_EmOrdem(Raiz); break;
        case 3: ArvoreBinariaBusca_PosOrdem(Raiz); break;
        default: cout << "Ordem desconhecida";
    }
    cout << endl << endl;
    system("pause");
}

void ArvoreBinariaBusca_EmOrdem(TipoCelula *Raiz) {
    if (Raiz != NULL) {
        ArvoreBinariaBusca_EmOrdem(Raiz->Esq);
        cout << Raiz->Item << " ";
        ArvoreBinariaBusca_EmOrdem(Raiz->Dir);
    }
}

void ArvoreBinariaBusca_PreOrdem(TipoCelula *Raiz) {
    if (Raiz != NULL) {
        cout << Raiz->Item << " ";
        ArvoreBinariaBusca_PreOrdem(Raiz->Esq);
        ArvoreBinariaBusca_PreOrdem(Raiz->Dir);
    }
}

void ArvoreBinariaBusca_PosOrdem(TipoCelula *Raiz) {
    if (Raiz != NULL) {
        ArvoreBinariaBusca_PosOrdem(Raiz->Esq);
        ArvoreBinariaBusca_PosOrdem(Raiz->Dir);
        cout << Raiz->Item << " ";
    }
}

// Função para imprimir todos os nodos de um mesmo nível
void ArvoreBinariaBusca_Imprimir_Por_Nivel(int nivel) {
    if (Raiz == NULL) {
        cout << "A árvore está vazia.\n";
        return;
    }

    queue<pair<TipoCelula*, int>> fila; // Fila que guarda pares (nodo, nível)
    fila.push(make_pair(Raiz, 0)); // Começamos com a raiz no nível 0

    bool encontrou = false; // Para verificar se encontramos nodos no nível solicitado
    while (!fila.empty()) {
        TipoCelula* atual = fila.front().first; // Nodo atual
        int nivelAtual = fila.front().second;   // Nível do nodo atual
        fila.pop();  // Remove da fila

        if (nivelAtual == nivel) {
            cout << atual->Item << " ";
            encontrou = true;
        }

        // Se estamos no nível maior do que o solicitado, podemos parar
        if (nivelAtual > nivel)
            break;

        // Adiciona os filhos à fila com seus respectivos níveis
        if (atual->Esq != NULL) {
            fila.push(make_pair(atual->Esq, nivelAtual + 1));
        }
        if (atual->Dir != NULL) {
            fila.push(make_pair(atual->Dir, nivelAtual + 1));
        }
    }

    if (!encontrou) {
        cout << "Nenhum nodo encontrado no nível " << nivel << ".\n";
    }
    cout << endl;
}
