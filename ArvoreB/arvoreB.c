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
    novo->folha = true;
    for (int i = 0; i <= b; i++)
    {
        novo->filho[i] = NULL;
    }

    return novo;
}

void InsercaoCLRS(Arvore raiz, int chave)
{
    //se o vetor estiver cheio (2t - 1)
    if(raiz->numero == MAX)
    {
        No* novo = CriarNo();
        novo->folha = false;
        novo->filho[0] = raiz;
        
        SplitChildren(novo, 0);
        InsercaoNaoCheio(novo, chave);
        raiz = novo;
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
        raiz->numero ++;
    }
    else
    {
        //encontrando o ponteiro para prosseguir corretamnete pelo valor da chave
        for(i = raiz->numero - 1; i >= 0 && chave < raiz->chave[i]; i--);
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
    //a chave esta em um no interno (poderia ter usado eslse mesmo), termos os casos 2 e 3
    if(raiz->folha == false)
    {
        //Caso 2: a chave aparece em um no interno (nao folha)
        if(i < raiz->numero && raiz->chave[i] == chave)
        {
            No* noAnt = raiz->filho[i];
            No* noSuc = raiz->filho[i + 1];

            //Caso 2a: Se o filho y de x que precede k tem ao menos t chaves
            if(noAnt->numero >= t) //(se retirarmos um, fica t - 1, ainda valido)
            {
                raiz->chave[i] = noAnt->chave[noAnt->numero - 1]; //utilizamos noAnt->numero - 1 pois eh o ultimo valor das chaves
                RemocaoCLRS(noAnt, noAnt->chave[noAnt->numero - 1]); //TODO: verificar se nao ha erro nos parametros
            }

            //Caso 2b: Se o filho z de x que sucede k tem ao menos t chaves
            else if(noSuc->numero >= t) //(se retirarmos um, fica t - 1, ainda valido)
            {
                raiz->chave[i] = noSuc->chave[0]; //utilizamos 0 pois eh o primeiro valor das chaves
                RemocaoCLRS(noAnt, noSuc->chave[0]); //TODO: verificar se nao ha erro nos parametros
            }
            //Caso 2c: se ambos os filhos possuem t - 1 chaves (nao eh possivel remover de nenhuma delas)
            else
            {
                MergeChildren(raiz, i);
                RemocaoCLRS(noAnt, chave); //TODO: verificar se nao ha erro nos parametros
            }
        }
        //Caso 3: a chave nao esta no no e ele eh interno, pode estar em um no filho
        if(i >= raiz->numero || raiz->chave[i] != chave)
        {
            No* filho = raiz->filho[i];

            //Caso 3a: se o filho tem exatamente (t - 1) chaves
            if(filho->numero == MIN)
            {
                //TODO: rever o i > 0
                //Se o irmao a esquerda ou direita tiver ao menos t chaves
                if(i > 0 && raiz->filho[i - 1]->numero >= t)
                {
                    No* irmao = raiz->filho[i - 1];
                    //Movemos chave do pai para o filho, e a chave do irmao para o pai
                    for(int j = filho->numero; j > 0; j--) //desloca as chaves para direita, deixando [0] livre
                    {
                        filho->chave[j] = filho->chave[j - 1];
                    }
                    filho->chave[0] = raiz->chave[i - 1]; 
                    raiz->chave[i - 1] = irmao->chave[irmao->numero - 1];
                    filho->numero++;
                    irmao->numero--;
                }
                //utilizamos i < raiz->numero para verificar se o irmao da direita existe
                else if(i < raiz->numero && raiz->filho[i + 1]->numero >= t)
                {
                    No* irmao = raiz->filho[i + 1];
                    //Movemos chave do pai para o filho, e a chave do irmao para o pai
                    filho->chave[filho->numero] = raiz->chave[i]; 
                    raiz->chave[i] = irmao->chave[0];
                    for(int j = 0; j < irmao->numero; j++) //deslocando as chaves para esqyerda
                    {
                        irmao->chave[j] = irmao->chave[j + 1];
                    }
                    filho->numero++;
                    irmao->numero--;
                }
                //Caso 3b: caso os irmaos tenham t - 1 chaves
                else
                {
                    if(i < raiz->numero) //existe um irmao a direita
                    {
                        MergeChildren(raiz, i); //merge entre filho[i] e filho[i + 1]
                    }
                    else
                    {
                        MergeChildren(raiz, (i - 1));
                    }
                }
            }

            RemocaoCLRS(filho, chave);
        }
    }
}

void MergeChildren(Arvore raiz, int index)
{
    No* esquerda = raiz->filho[index];
    No* direita = raiz->filho[index + 1];

    //Move a chave atual do no raiz para o ultima chave do filho da esquerda
    esquerda->chave[t - 1] = raiz->chave[index];

    //Copiando as chaves do no direita parta o no da esquerda
    for(int i = 0; i < direita->numero; i++)
    {
        esquerda->chave[t + i] = direita->chave[i];
        esquerda->numero++;
    }

    //Se esquerda for no interno, sera necessario ajustar os ponteiros
    if(esquerda->folha == false)
    {
        //Copiando os ponteiros do no direita parta o no da esquerda
        for(int i = 0; i <= direita->numero; i++)
        {
            esquerda->filho[t + i] = direita->filho[i];
        }
    }

    //Remove a chave do No atual, deslocando das chaves
    for(int i = index; i < raiz->numero - 1; i++)
    {
        raiz->chave[i] = raiz->chave[i + 1];
    }
    //Ajusta os ponteiros para os filhos, deslocando-os
    for(int i = index + 1; i < raiz->numero; i++)
    {
        raiz->filho[i] = raiz->filho[i + 1];
    }

    //Ajusta o numero de chaves, ja que removemos uma delas
    raiz->numero--;

    //Librea o no da memoria
    free(direita);

}

void ImprimirArvore(Arvore raiz, int nivel)
{
    if(raiz == NULL)
    {
        return;
    }

    for (int i = 0; i < nivel; i++)
    {
        printf("   ");
    }
    printf("[ ");
    for (int i = 0; i < raiz->numero; i++)
    {
        printf("%d ", raiz->chave[i]);
    }
    printf("]\n");

    if(raiz->folha == false)
    {
        for(int i = 0; i < raiz->numero + 1; i++)
        {
            ImprimirArvore(raiz->filho[i], nivel + 1);
        }
    }
}