#include <stdio.h>
#include "arvorePatricia.c"

int main()
{
    No* arvore;
    Inicializar(&arvore);

    Inserir(arvore, 5);
    Imprimir(arvore->esquerda, arvore);
    printf("\n");
    Inserir(arvore, 10);
    Imprimir(arvore->esquerda, arvore);
    printf("\n");
    Inserir(arvore, 3);
    Imprimir(arvore->esquerda, arvore);
    printf("\n");

    No* resultado = Busca(arvore, 10);
    if (resultado)
    {
        printf("Elemento encontrado: %u\n", resultado->chave);
    }
    else
    {
        printf("Elemento nao encontrado.\n");
    }

    return 0;
}