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

No* CriarNo(int chave)
{
    No* novo = malloc(sizeof(No));
    novo->numero = 0;
    novo->folha = false;
}

No* InsercaoCLRS(No* raiz, int chave)
{
    //se o vetor estiver cheio (2t - 1)
    if(raiz->numero == MAX)
    {
        No* novo = CriarNo(chave);
        novo->filho[0] = raiz;
        //TODO: SPLITCHILD
        //TODO: INSERENAOCHEIO
    }
    else
    {
        //TODO: INSERENAOCHEIO
    }
}

No* InsercaoNaoCheio(No* raiz, int chave)
{
    int i;
    if(raiz->folha == true)
    {
        //percorre o vetor ao contrario, passando as chaves uma posicao para frente
        //desse modo, quando for o local correto para inserir a chave, havera um espaco vazio
        for(i = raiz->numero; i >= 0 && chave < raiz->chave[i]; i--)
        {
            raiz->chave[i + 1] = raiz->chave[i];
        }

        //inserimos a chave e atualizamos o valor de chaves atual
        raiz->chave[i + 1] = chave;
        raiz->numero += 1;
    }
    else
    {
        //encontrando o ponteiro para prosseguir corretamnete pelo valor da cheve
        for(i = raiz->numero; i >= 0 && chave < raiz->chave[i]; i--);
        i++;
        //OBS: REVER FUNCIONAMENTO DESSE IF
        if(raiz->filho[i]->numero == MAX)
        {
            //TODO:SPLITCHILDREN
            if(chave > raiz->chave[i])
            {
                i++;
            }
        }
        InsercaoNaoCheio(raiz->filho[i], chave);
    }
}