#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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
No* BuscaRecursiva(No* arvore, unsigned chave, int nivel);
No* Busca(No* arvore, unsigned chave);
No* InserirRecursivo(No* arvore, unsigned chave, int nivel);
No* Inserir(No* arvore, unsigned int chave);
No* RemoverRecursivo(No* arvore, unsigned chave, int nivel);
No* Remover(No* arvore, unsigned int chave);
