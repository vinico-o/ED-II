#include <arvoreTrie.h>

//Funcao para retirnar o k-esimo bit
unsigned int getBit(unsigned chave, int k)
{
    return (chave >> (NBITS - k - 1)) & 1;
}

No* CriarNo(unsigned chave)
{
    No* novo = malloc(sizeof(No));
    novo->folha = true;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->chave = chave;
}