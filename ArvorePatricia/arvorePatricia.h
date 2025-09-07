#ifndef ARVORE_PATRICIA_H
#define ARVORE_PATRICIA_H

#define NBITS 8

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //Para UINT_MAX

typedef struct No
{
    unsigned chave;       //chave sem sinal
    int bit;              //bit de discriminacao, o que se diferencia dos outros
    struct No* esquerda;  //ponteiro para no da esquerda
    struct No* direita;   //ponteiro para no da direita
} No;

#endif // ARVORE_PATRICIA_H