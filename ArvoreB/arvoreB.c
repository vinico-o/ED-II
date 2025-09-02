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

No* CriarNo()
{
    No* novo = malloc(sizeof(No));
    novo->numero = 0;
    novo->folha = false;
}

void InsercaoCLRS(Arvore raiz, int chave)
{
    //se o vetor estiver cheio (2t - 1)
    if(raiz->numero == MAX)
    {
        No* novo = CriarNo();
        novo->filho[0] = raiz;
        
        SplitChildren(novo, 0);
        InsercaoNaoCheio(novo, chave);
    }
    else
    {
        InsercaoNaoCheio(raiz, chave);
    }
}

void InsercaoNaoCheio(Arvore raiz, int chave)
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
        //encontrando o ponteiro para prosseguir corretamnete pelo valor da chave
        for(i = raiz->numero; i >= 0 && chave < raiz->chave[i]; i--);
        i++;
        
        //Se o numero de chaves for igual ao maximo (2t - 1)
        if(raiz->filho[i]->numero == MAX)
        {
            SplitChildren(raiz, i);
            //Se a chave for maior que a chave do no pai
            if(chave > raiz->chave[i])
            {
                i++; //o ponteiro eh ajustado para o filho correto
            }
        }
        InsercaoNaoCheio(raiz->filho[i], chave);
    }
}

void SplitChildren(Arvore raiz, int index)
{
    No* novo = CriarNo(); //Aloca o novo no na memoria
    No* filho = raiz->filho[index];
    novo->folha = filho->folha;
    novo->numero = MIN;

    //copia as t - 1 ultimas chaves para o novo no, ainda em order crescente
    for(int i = 0; i < MIN; i++)
    {
        novo->chave[i] = filho->chave[i + t];
    }

    //Se o no filho de x for um no interno
    if(filho->folha == false)
    {
        //copiamos os filhos dele para o novo no
        for(int i = 0; i < t; i++)
        {
            novo->filho[i] = filho->filho[i + t];
        }
    }

    //como a copia da segunda parte do no filho ja foi copiada,
    //ajustamos o numero de chaves
    filho->numero = MIN;

    //Ajusta os ponteiros da raiz para adicionar o novo no
    for(int i = (raiz->numero + 1); i >= index + 1; i--)
    {
        raiz->filho[i + 1] = raiz->filho[i];
    }

    //como no novo foi copiado os ultimos elementos, ele eh o ultimo filho
    raiz->filho[index + 1] = novo;

    //Faz o deslocamento das chaves para incluir a mediana no no pai (raiz)
    for(int i = raiz->numero; i >= index; i--)
    {
        raiz->chave[i + 1] = raiz->chave[i];
    }

    //passamos a mediana para o no pai e ajustamos seu numero de chaves
    raiz->chave[index] = filho->chave[t]; //utilizamos t pois eh justamente a mediana
    raiz->numero ++;

}

void RemocaoCLRS(Arvore raiz, int chave)
{
    int i;
    //Encontrando o indice da chave no no
    for(i = 0; i < raiz->numero && raiz->chave[i] < chave; i++);

    //Caso 1: a chave aparece em um no folha.
    if(raiz->folha == true)
    {
        //verificamos se a chave foi encontrada e se ela eh acessivel
        if(i < raiz->numero && chave == raiz->chave[i])
        {
            //percorremos o vetor a partir do indice, trazendo todas as cheves posteriores uma casa pare tras,
            //sobrescrevendo (eliminando) a chave desejada
            for(int j = i; j < raiz->numero - 1; j++) //utilizamos numero - 1 para nao acessar fora do vetor (no ultimo elemento)
            {
                raiz->chave[j] = raiz->chave[j + 1]; //desloca a chave
            }
            raiz->numero --; //ajustamos o numero de chaves
        }
    }
}