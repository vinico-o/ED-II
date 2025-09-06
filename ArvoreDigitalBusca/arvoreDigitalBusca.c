#include "arvoreDigitalBusca.h"

//Encontrando o kesimo bit da chave numero
unsigned int bit(unsigned numero, int k)
{
    //Para deixar o kesimo bit como o menos significativo precisamos de
    //NBITS - k - 1 rotacoes para direita, o "1" indica o bit menos significativo
    return (numero >> NBITS - k - 1) & 1;
}

No* Busca(No* arvore, unsigned busca)
{
    return BuscaRecursiva(arvore, busca, 0);
}

No* BuscaRecursiva(No* arvore, unsigned busca, int nivel)
{
    //Se chegar ao final da arvore, retorna null
    if(arvore == NULL)
    {
        return NULL;
    }
    //compara a chave com a chave buscada
    if(busca == arvore->chave)
    {
        return arvore;
    }
    //Se a chave nao for encontrada, verifica o caminho
    //bit 1 -> direita, bit 0 -> esquerda
    //O k-esimo bit eh o bit na posicao "nivel"
    if(bit(arvore->chave, nivel) == 1)
    {
        return BuscaRecursiva(arvore->direita, busca, nivel + 1);
    }
    else
    {
        return BuscaRecursiva(arvore->esquerda, busca, nivel + 1);
    }
}