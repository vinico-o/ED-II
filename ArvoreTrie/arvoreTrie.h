#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NBITS 8

typedef struct No
{
    unsigned int chave;  //valor armazenado
    bool folha;          //indicador se eh folha ou nao
    struct No* direita;  //ponteiro para direita
    struct No* esquerda; //ponteiro para direita
} No;

unsigned int getBit(unsigned chave, int k);
No* CriarNo(unsigned chave);
