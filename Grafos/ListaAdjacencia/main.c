#include <stdio.h>
#include "ListaAdjacencia.h"

int main() {
    
    ptrGrafo grafo = criarGrafo(5);

    inserirAresta(grafo, 0, 1);
    inserirAresta(grafo, 0, 2);
    inserirAresta(grafo, 1, 3);
    inserirAresta(grafo, 3, 4);

    printf("Arestas inseridas:\n");
    imprimirAresta(grafo);

    printf("\nTestando existeAresta:\n");
    printf("Existe (0,1)? %d\n", existeAresta(grafo, 0, 1));
    printf("Existe (2,4)? %d\n", existeAresta(grafo, 2, 4));

    printf("\nRemovendo aresta (0,2)\n");
    removerAresta(grafo, 0, 2);

    printf("\nArestas após remoção:\n");
    imprimirAresta(grafo);

    destruirGrafo(grafo);
    printf("\nGrafo destruído.\n");

    return 0;
}