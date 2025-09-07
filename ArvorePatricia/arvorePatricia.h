#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //Para UINT_MAX

#define NBITS 8

typedef struct No
{
    unsigned int chave;       //chave sem sinal
    int bit;              //bit de discriminacao, o que se diferencia dos outros
    struct No* esquerda;  //ponteiro para no da esquerda
    struct No* direita;   //ponteiro para no da direita
} No;

void Inicializar(No** arvore);
unsigned int getBit(unsigned chave, int k);
No* Busca(No* arvore, unsigned chave);
No* BuscaRecursiva(No* arvore, unsigned chave, int bitAnt);
void Inserir(No* arvore, unsigned chave);
No* InserirRecursivo(No* arvore, unsigned chave, int bitDif, No* pai);
void ImprimirEmOrdem(No* arvore, No* dummy);