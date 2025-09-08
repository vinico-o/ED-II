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

//A busca eh proxima ao da ArvoreDigitaldeBusca, mas com uma verificacao se o no eh folha
No* BuscaRecursiva(No* arvore, unsigned chave, int nivel)
{
    //elemento nao encontrado, chegou ao fim da arvore
    if(arvore == NULL)
    {
        return NULL;
    }

    //as informacoes relevantes estao somente na folha, por isso a verificacao
    if(arvore->chave == chave && arvore->folha == true)
    {
        return arvore;
    }

    //Caminhan do pela arvore atraves dos bits da chave
    if(getBit(chave, nivel) == 1)
    {
        return BuscaRecursiva(arvore->direita, chave, nivel + 1);
    }
    else
    {
        return BuscaRecursiva(arvore->esquerda, chave, nivel + 1);
    }
}