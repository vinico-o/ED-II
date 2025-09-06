#include <stdio.h>
#include <stdlib.h>
#include "arvoreDigitalBusca.c"

int main()
{
    No* raiz = NULL;

    unsigned valores[] = {23, 5, 15, 42, 8};
    int n = sizeof(valores)/sizeof(valores[0]);
    for(int i = 0; i < n; i++)
        raiz = Inserir(raiz, valores[i]);

    printf("Arvore em ordem apos insercao:\n");
    ImprimirEmOrdem(raiz);
    printf("\n");

    unsigned busca = 15;
    No* resultado = Busca(raiz, busca);
    if(resultado != NULL)
        printf("Valor %u encontrado na arvore.\n", busca);
    else
        printf("Valor %u nao encontrado.\n", busca);

    busca = 99;
    resultado = Busca(raiz, busca);
    if(resultado != NULL)
        printf("Valor %u encontrado na arvore.\n", busca);
    else
        printf("Valor %u nao encontrado.\n", busca);

    printf("\nRemovendo 15 e 23...\n");
    raiz = Remover(raiz, 15);
    raiz = Remover(raiz, 23);

    printf("Arvore final em ordem:\n");
    ImprimirEmOrdem(raiz);
    printf("\n");

    return 0;
}
