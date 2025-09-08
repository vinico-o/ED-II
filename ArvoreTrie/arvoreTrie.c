#include <arvoreTrie.h>

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

No* Busca(No* arvore, unsigned chave)
{
    //Se o elemento for encontrado, retorna o no em que esta, senao retorna NULL;
    No* resultado = BuscaRecursiva(arvore, chave, 0);
    return resultado;
}

No* InserirRecursivo(No* arvore, unsigned chave, int nivel)
{
    //Se arovre for nula, cria o No (return), para gerar o caminho
    //Utilizamos UINT_MAX pois a informacao nao sera relevante
    if(arvore == NULL)
    {
        No* novo = CriarNo(UINT_MAX);
    }

    //se percorremos toda a arvore, criamos o no com informacao relevante
    if(nivel == NBITS)
    {
        No* novo = CriarNo(chave);
        novo->folha = true;
        return novo;
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

void Inserir(No** raiz, unsigned int chave) {
    *raiz = inserir_recursivo(*raiz, chave, 0);
}