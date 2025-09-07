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

unsigned int getBit(unsigned chave, int k)
{
    return (chave >> (NBITS - k - 1) & 1);
}

No* Busca(No* arvore, unsigned chave)
{
    return BuscaRecursiva(arvore, chave, -1); //-1 eh o bit do no dummy
}

No* BuscaRecursiva(No* arvore, unsigned chave, int bitAnt)
{
    //Se, durante a busca, subimos um nivel da arvore, encontramos a chave
    if(arvore->bit <= bitAnt)
    {
        return arvore;
    }

    //Verificamos qual caminho a ser seguido, baseado no indicador "bit" do no
    if(getBit(chave, arvore->bit) == 0)
    {
        //Caminhamos para a esquerda, com o bitAnt sendo o atual (dessa chamada)
        return BuscaRecursiva(arvore->esquerda, chave, arvore->bit);
    }
    else
    {
        //Caminhamos para a direita, com o bitAnt sendo o atual (dessa chamada)
        return BuscaRecursiva(arvore->direita, chave, arvore->bit);
    }
}
