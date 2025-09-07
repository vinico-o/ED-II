#include "arvorePatricia.h"

//criacao do no dummy
void Inicializar(No** arvore)
{
    *arvore = malloc(sizeof(No));   
    (*arvore)->chave = UINT_MAX;     //Maior valor possivel para unsigned
    (*arvore)->esquerda = (*arvore); //aponta para o proprio dummy
    (*arvore)->direita = NULL;       //aponta para o proprio dummy
    (*arvore)->bit = -1;             //bit de discriminacao do dummy

}

unsigned int bit(unsigned chave, int k)
{
    return (chave >> (NBITS - k - 1) & 1);
}

