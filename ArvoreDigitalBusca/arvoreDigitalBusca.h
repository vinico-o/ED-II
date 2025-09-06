#include <stdio.h>

#define NBITS 8

typedef struct No
{
    unsigned chave; //chave sem sinal
    No* esquerda; //ponteiro para no da esquerda
    No* direita; //ponteiro para no da direita
} No;

unsigned int bit(unsigned numero, int k);
No* Busca(No* arvore, unsigned busca);
No* BuscaRecursiva(No* arvore, unsigned busca, int nivel);
