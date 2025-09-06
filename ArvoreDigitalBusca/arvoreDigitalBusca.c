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

No* InserirRecursivo(No* arvore, unsigned chave, int nivel)
{
    No* novo;
    if(arvore == NULL)
    {
        novo = malloc(sizeof(No));
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->chave = chave;
        return novo;
    }
    //Caso a chave ja esteja na arvore
    if(arvore->chave == chave)
    {
        return arvore;
    }
    //Navegando pela arvore
    if(bit(chave, nivel) == 1)
    {
        //se o bit for 1, seguiremos a arvore para a direita
        arvore->direita = InserirRecursivo(arvore->direita, chave, nivel + 1);
    }
    else
    {   
        //se o bit for 0, seguiremos a arvore para a esquerda
        arvore->esquerda = InserirRecursivo(arvore->esquerda, chave, nivel + 1);
    }

    //apos a insercao, retornamos a arvore
    return arvore;
}