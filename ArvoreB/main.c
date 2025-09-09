#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.c"

int main() {
    
    Arvore raiz = CriarNo();
    raiz->folha = true;

    printf("\nInserindo 10...\n");
    raiz = InsercaoCLRS(raiz, 10);
    ImprimirArvore(raiz, 0);

    printf("\nInserindo 20...\n");
    raiz = InsercaoCLRS(raiz, 20);
    ImprimirArvore(raiz, 0);

    printf("\nInserindo 5...\n");
    raiz = InsercaoCLRS(raiz, 5);
    ImprimirArvore(raiz, 0);

    printf("\nInserindo 6...\n");
    raiz = InsercaoCLRS(raiz, 6);
    ImprimirArvore(raiz, 0);

    printf("\nInserindo 12...\n");
    raiz = InsercaoCLRS(raiz, 12);
    ImprimirArvore(raiz, 0);

    printf("\nInserindo 30...\n");
    raiz = InsercaoCLRS(raiz, 30);
    ImprimirArvore(raiz, 0);

    printf("\nInserindo 7...\n");
    raiz = InsercaoCLRS(raiz, 7);
    ImprimirArvore(raiz, 0);

    printf("\nInserindo 17...\n");
    raiz = InsercaoCLRS(raiz, 17);
    ImprimirArvore(raiz, 0);

    // Teste de busca
    int busca = 6;
    No* encontrado = BuscaRecursiva(raiz, busca);
    if (encontrado != NULL)
        printf("Valor %d encontrado!\n", busca);
    else
        printf("Valor %d NAO encontrado.\n", busca);

    // Teste de remoção
    printf("\nRemovendo 6...\n");
    RemocaoCLRS(raiz, 6);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 13 (nao existe)...\n");
    RemocaoCLRS(raiz, 13);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 7...\n");
    RemocaoCLRS(raiz, 7);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 4 (nao existe)...\n");
    RemocaoCLRS(raiz, 4);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 12...\n");
    RemocaoCLRS(raiz, 12);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 5...\n");
    RemocaoCLRS(raiz, 5);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 10...\n");
    RemocaoCLRS(raiz, 10);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 20...\n");
    RemocaoCLRS(raiz, 20);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 30...\n");
    RemocaoCLRS(raiz, 30);
    ImprimirArvore(raiz, 0);

    printf("\nRemovendo 17...\n");
    RemocaoCLRS(raiz, 17);
    ImprimirArvore(raiz, 0);

    return 0;
}
