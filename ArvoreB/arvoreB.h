#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define b 5
#define t ((b + 1) / 2)
#define MIN (t - 1)
#define MAX (2 * t - 1)

typedef struct No
{
    int numero; //numero de chaves atual
    bool folha; //indicador de folha ou nao
    int chave[b]; //MAX + 1 para guardar temporariamente a chave
    struct No* filho[b + 1]; //ponteiros par filhos
} No, *Arvore;

No* BuscaRecursiva(No* raiz, int busca);
No* CriarNo();
No* InsercaoCLRS(Arvore raiz, int chave);
void InsercaoNaoCheio(Arvore raiz, int chave);
void SplitChildren(Arvore raiz, int index);
void RemocaoCLRS(Arvore raiz, int chave);
void MergeChildren(Arvore raiz, int index);
void ImprimirArvore(Arvore raiz, int nivel);