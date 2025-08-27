#include "arvoreB.h"

No* BuscaRecursiva(No* raiz, int busca)
{
    int i;
    //percorre a chave ate que o numero buscado seja menor ou igual a um numero dela
    for(i = 0; i < raiz->numero && busca > raiz->chave[i]; i++);

    //encontramos um valor de i para fazer a comparação
    //se i for dentro do numero maximo de valores e a chave for igual a busca
    if(i < raiz->numero && raiz->chave[i] == busca)
    {
        return raiz;
    }

    //verifica se chegamos ao fim da arvore, entao o numero nao foi encontrado
    if(raiz->folha == true)
    {
        return NULL;
    }
    else //chama a funcao recursivamente para o nó filho
    {
        return BuscaRecursiva(raiz->filho[i], busca);
    }
}