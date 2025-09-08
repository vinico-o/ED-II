#include "arvoreTrie.h"

//Funcao para retirnar o k-esimo bit
unsigned int getBit(unsigned chave, int k)
{
    return (chave >> (NBITS - k - 1)) & 1;
}

No* CriarNo(unsigned chave)
{
    No* novo = malloc(sizeof(No));
    novo->folha = false;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->chave = chave;

    return novo;
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

void Busca(No* arvore, unsigned chave)
{
    //Se o elemento for encontrado, retorna o no em que esta, senao retorna NULL;
    No* resultado = BuscaRecursiva(arvore, chave, 0);
    if(resultado == NULL)
    {
        printf("Elemento %u nao encontrado!\n", chave);
    }
    else
    {
        printf("Elemento %u encontrado!\n", chave);
    }
}

No* InserirRecursivo(No* arvore, unsigned chave, int nivel)
{
    //Se arovre for nula, cria o No (return), para gerar o caminho
    //Utilizamos UINT_MAX pois a informacao nao sera relevante
    if(arvore == NULL)
    {
        arvore = CriarNo(UINT_MAX);
    }

    //se percorremos toda a arvore, criamos o no com informacao relevante
    if(nivel == NBITS)
    {
        arvore->folha = true;
        arvore->chave = chave;
        return arvore;
    }

    //caminhamos pela arvore, a partir da chave 0->esquerda, 1->direita
    if(getBit(chave, nivel) == 0)
    {
        arvore->esquerda = InserirRecursivo(arvore->esquerda, chave, nivel + 1);
    }
    else
    {
        arvore->direita = InserirRecursivo(arvore->direita, chave, nivel + 1);
    }

    //retornamos arvore para manter as ligacoes dos ponteiros
    return arvore;
}

No* Inserir(No* arvore, unsigned int chave)
{
    return InserirRecursivo(arvore, chave, 0);
}

No* RemoverRecursivo(No* arvore, unsigned chave, int nivel)
{
    //Se a arvore for nula, a chave nao existe
    if(arvore == NULL)
    {
        return NULL;
    }

    //Se chamos em uma chave valida
    if(nivel == NBITS)
    {
        //se o no for folha, desmarcaremos ele, para depois remover
        if(arvore->folha == true)
        {
            arvore->folha = false;
        }
    }
    else //Senao, continuamos percorrendo a arvore
    {
        if(getBit(chave, nivel) == 0)
        {
            arvore->esquerda = RemoverRecursivo(arvore->esquerda, chave, nivel + 1);
        }
        else
        {
            arvore->direita = RemoverRecursivo(arvore->direita, chave, nivel + 1);
        }
    }

    //apos encontrar o local da chave, removemos os nos que nao possuem filhos
    //pois se tiver filho, pode haver um caminho para uma chave util
    if(arvore->folha == false && arvore->esquerda == NULL && arvore->direita == NULL)
    {
        free(arvore); //libera o no
        return NULL; //retrona nulo para indicar ao no pai, que esse filho sera nulo
    }

    //Se o no for util (ainda tiver um caminho com ele), retorna ele para manter os ponteiros
    return arvore;
}

No* Remover(No* arvore, unsigned int chave)
{
    return RemoverRecursivo(arvore, chave, 0);
}

void ImprimirRecursivo(No* arvore)
{
    if(arvore == NULL)
    {
        return;
    }
    
    ImprimirRecursivo(arvore->esquerda);

    if(arvore->folha == true)
    {
        printf("%u ", arvore->chave);
    }

    ImprimirRecursivo(arvore->direita);
}

void Imprimir(No* arvore)
{
    ImprimirRecursivo(arvore);
    printf("\n");
}