#include <stdio.h>
#include <stdbool.h>

#define b 5
#define t (b + 1) / 2
#define MIN t - 1
#define MAX 2 * t - 1


typedef struct No
{
    int numero; //numero de chaves atual
    bool folha; //indicador de folha ou nao
    int chave[b + 1]; //MAX + 1 para guardar temporariamente a chave
    struct No* filho[b + 1]; //ponteiros par filhos
} No, *Arvore;

No* BuscaRecursiva(No* raiz, int busca);
