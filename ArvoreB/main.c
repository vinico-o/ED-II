#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

int main() {
    
    Arvore raiz = CriarNo();
    raiz->folha = true;

    
    int valores[8] = {10, 20, 5, 6, 12, 30, 7, 17};

    printf("Inserindo valores:\n");
    for (int i = 0; i < 8; i++) {
        printf("Inserindo %d...\n", valores[i]);
        InsercaoCLRS(raiz, valores[i]);
        ImprimirArvore(raiz, 0);
        printf("\n");
    }

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
