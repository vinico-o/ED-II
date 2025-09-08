#include <stdio.h>
#include "arvoreTrie.c"

int main()
{
    No* raiz = NULL;

    printf("INSERINDO ELEMENTOS\n");
    raiz = Inserir(raiz, 5);
    Imprimir(raiz);
    raiz = Inserir(raiz, 10);
    Imprimir(raiz);
    raiz = Inserir(raiz, 15);
    Imprimir(raiz);
    raiz = Inserir(raiz, 7);
    Imprimir(raiz);

    printf("\nBUSCANDO ELEMENTOS\n");
    Busca(raiz, 5);  
    Busca(raiz, 7);
    Busca(raiz, 20);

    printf("\nREMOVENDO ELEMENTOS\n");
    raiz = Remover(raiz, 7);
    Imprimir(raiz);
    raiz = Remover(raiz, 15);
    Imprimir(raiz);

    printf("\nBUSCANDO APOS REMOCAO\n");
    Busca(raiz, 7);
    Busca(raiz, 15);
    Busca(raiz, 5);

    return 0;
}

