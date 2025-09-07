#include "arvorePatricia.h"

//criacao do no dummy
void Inicializar(No** arvore)
{
    *arvore = malloc(sizeof(No));   
    (*arvore)->chave = UINT_MAX;     //Maior valor possivel para unsigned
    (*arvore)->esquerda = (*arvore); //aponta para o proprio dummy
    (*arvore)->direita = (*arvore);       //aponta para o proprio dummy
    (*arvore)->bit = -1;             //bit de discriminacao do dummy

}

unsigned int getBit(unsigned chave, int k)
{
    return (chave >> (NBITS - k - 1) & 1);
}

No* Busca(No* arvore, unsigned chave)
{
    No* encontrado =  BuscaRecursiva(arvore, chave, -1); //-1 eh o bit do no dummy

    if(encontrado->chave == chave)
    {
        return encontrado;
    }

    return NULL;
}

No* BuscaRecursiva(No* arvore, unsigned chave, int bitAnt)
{
    //Se, durante a busca, subimos um nivel da arvore, a busca termina
    //mas nao necessariamente encontramos o no
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

void Inserir(No* arvore, unsigned chave)
{
    int i;
    //Comecamos com arvore->esquerda pois "arvore eh o dummy"
    No* busca = BuscaRecursiva(arvore->esquerda, chave, -1);

    //Elemento ja presente na arvore, entao nao tem como inserir
    if(busca->chave == chave)
    {
        return;
    }

    //Verificando onde as chaves se diferenciam
    for(i = 0; getBit(busca->chave, i) == getBit(chave, i); i++);

    arvore->esquerda = InserirRecursivo(arvore->esquerda, chave, i, arvore);
}

No* InserirRecursivo(No* arvore, unsigned chave, int bitDif, No* pai)
{
    No* novo;

    //Encontra onde o no deve ser criado, pois ou subimos um nivel na arvore,
    //ou o nivel de profundidade ja passou do necessario
    if(arvore->bit >= bitDif || arvore->bit <= pai->bit)
    {
        novo = malloc(sizeof(No));
        novo->chave = chave;
        novo->bit = bitDif; //recebe o bit que diferencia do pai dele

        //se o bit na posicao "bitDif" da chave for 1,
        //o novo no aponta para a direita, pois indica ele mesmo
        if(getBit(chave, novo->bit) == 1)
        {
            novo->direita = novo;
            novo->esquerda = arvore;
        }
        else
        {
            novo->esquerda = novo;
            novo->direita = arvore;
        }

        return novo;
    }

    //Caminhamos pela arvore, verificando o bit do no atual
    if(getBit(chave, arvore->bit) == 0)
    {
        arvore->esquerda = InserirRecursivo(arvore->esquerda, chave, bitDif, arvore);
    }
    else
    {
        arvore->direita = InserirRecursivo(arvore->direita, chave, bitDif, arvore);
    }

    return arvore;
}

void Imprimir(No* noAtual, No* noAnt)
{
    if (noAtual->bit > noAnt->bit)
    {
        printf ("%u ", noAtual->chave);

        Imprimir(noAtual->esquerda, noAtual);
        
        Imprimir(noAtual->direita, noAtual);
    }
}