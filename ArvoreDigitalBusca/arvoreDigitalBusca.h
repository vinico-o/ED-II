#include <stdio.h>
#include <stdlib.h>

#define NBITS 8

typedef struct No
{
    unsigned chave; //chave sem sinal
    struct No* esquerda; //ponteiro para no da esquerda
    struct No* direita; //ponteiro para no da direita
} No;

unsigned int bit(unsigned numero, int k);
void ImprimirEmOrdem(No* arvore);
No* Busca(No* arvore, unsigned busca);
No* BuscaRecursiva(No* arvore, unsigned busca, int nivel);
No* Inserir(No* arvore, unsigned chave);
No* InserirRecursivo(No* arvore, unsigned chave, int nivel);
No* PredecessorMaisADireita(No* arvore);
No* Remover(No* arvore, unsigned chave);
No* RemoverRecursivo(No* arvore, unsigned chave, int nivel);
