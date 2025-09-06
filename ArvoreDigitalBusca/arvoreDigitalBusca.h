#include <stdio.h>

#define NBITS 8

typedef struct No
{
    unsigned chave; //chave sem sinal
    No* esquerda; //ponteiro para no da esquerda
    No* direita; //ponteiro para no da direita
} No;