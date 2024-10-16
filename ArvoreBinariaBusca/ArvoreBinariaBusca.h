#ifndef ARVOREBINARIABUSCA_H_INCLUDED
#define ARVOREBINARIABUSCA_H_INCLUDED

typedef int TipoDado; // Define o tipo de dado que será armazenado na árvore binária de busca

struct TipoCelula {
   TipoDado Item;
   TipoCelula *Esq, *Dir;
};

void ArvoreBinariaBusca_Construtor();
void ArvoreBinariaBusca_Destrutor();
bool ArvoreBinariaBusca_Vazia();
int  ArvoreBinariaBusca_Tamanho();
bool ArvoreBinariaBusca_Inserir(TipoDado Elemento);
bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento);
void ArvoreBinariaBusca_Percurso(int modo = 1);
void ArvoreBinariaBusca_Destrutor(TipoCelula *&Raiz);
bool ArvoreBinariaBusca_Inserir(TipoDado Elemento, TipoCelula *&Raiz);
bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento, TipoCelula *Raiz);
void ArvoreBinariaBusca_EmOrdem(TipoCelula *Raiz);
void ArvoreBinariaBusca_PreOrdem(TipoCelula *Raiz);
void ArvoreBinariaBusca_PosOrdem(TipoCelula *Raiz);

// Função para imprimir todos os nodos de um mesmo nível
void ArvoreBinariaBusca_Imprimir_Por_Nivel(int nivel);

#endif // ARVOREBINARIABUSCA_H_INCLUDED
