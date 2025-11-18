#include <stdio.h>
#include "MatrizAdjacencia.h"

int main()
{
    ptrGrafo grafo = lerGrafo();

    printf("Grafo lido:\n");
    imprimirGrafo(grafo);

    int vertice;
    printf("Digite o vértice para calcular o grau: ");
    scanf("%d", &vertice);
    int grau = calcularGrauDoVertice(grafo, vertice);
    printf("Grau do vértice %d: %d\n", vertice, grau);

    int verticeMaiorGrau = calcularVerticeComMaiorGrau(grafo);
    printf("Vértice com maior grau: %d\n", verticeMaiorGrau);

    printf("Recomendações para o vértice %d:\n", vertice);
    imprimirRecomendacoes(grafo, vertice);

    destruirGrafo(grafo);
    return 0;
}