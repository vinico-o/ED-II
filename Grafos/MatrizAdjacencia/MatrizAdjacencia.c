#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MatrizAdjacencia.h"

ptrGrafo criarGrafo(int numVertices)
{
    // Aloca memória para o grafo
    ptrGrafo grafo = malloc(sizeof(Grafo)); // Aloca memória para o grafo
    grafo->numVertices = numVertices;       // Define o número de vértices

    // Aloca memória para a matriz de adjacência
    grafo->matrizAdj = malloc(numVertices * sizeof(int *)); //Aloca as linhas da matriz
    for(int i = 0; i < numVertices; i++)
    {
        grafo->matrizAdj[i] = malloc(numVertices *sizeof(int)); // Aloca as colunas da matriz

    }

    // Inicializa a matriz de adjacência com zeros
    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < numVertices; j++)
        {
            grafo->matrizAdj[i][j] = 0;
        }
    }

    return grafo;
}

void destruirGrafo(ptrGrafo grafo)
{
    for(int i = 0; i < grafo->numVertices; i++)
    {
        free(grafo->matrizAdj[i]); // Libera cada linha da matriz
    }
    free(grafo->matrizAdj); // Libera a matriz de adjacência
    free(grafo); // Libera o grafo
}

void inserirAresta(ptrGrafo grafo, int u, int v)
{
    // Como o grafo é não direcionado, a matriz é simétrica
    // Então atualizamos os dois lados
    grafo->matrizAdj[u][v] = 1;
    grafo->matrizAdj[v][u] = 1;
}

void removerAresta(ptrGrafo grafo, int u, int v)
{
    // Como o grafo é não direcionado, a matriz é simétrica
    // Então atualizamos os dois lados
    grafo->matrizAdj[u][v] = 0;
    grafo->matrizAdj[v][u] = 0;
}

bool existeAresta(ptrGrafo grafo, int u, int v)
{
    // Verifica se a matriz na posição [u][v] é 1
    if(grafo->matrizAdj[u][v] == 1)
    {
        return true;
    }

    return false;
}

void imprimirGrafo(ptrGrafo grafo)
{
    printf("MATRIZ DE ADJACENCIA:\n");
    for(int i = 0; i < grafo->numVertices; i++)
    {
        for(int j = 0; j < grafo->numVertices; j++)
        {
            printf("%d ", grafo->matrizAdj[i][j]);
        }
        printf("\n");
    }
}

ptrGrafo lerGrafo()
{
    int u, v, numVertices, numArestas;
    
    printf("Digite o número de vértices: ");
    scanf("%d", &numVertices);

    ptrGrafo grafo = criarGrafo(numVertices);

    printf("Digite o número de arestas: ");
    scanf("%d", numArestas);

    for(int i = 0; i < numArestas; i++)
    {
        printf("Digite a aresta (u v): ");
        scanf("%d %d", &u, &v);
        inserirAresta(grafo, u, v);
    }

    return grafo;
}

int calcularGrauDoVertice(ptrGrafo grafo, int u)
{
    int grau = 0;
    for(int v = 0; v < grafo->numVertices; v++)
    {
        if(grafo->matrizAdj[u][v] == 1)
        {
            grau++;
        }
    }
    return grau;
}

int calcularVerticeComMaiorGrau(ptrGrafo grafo)
{
    int verticeAtual, verticeMax;
    int grauAtual, grauMax;

    // Inicializa com o primeiro vértice
    verticeMax = 0;
    grauMax = calcularGrauDoVertice(grafo, 0);

    for(verticeAtual = 1; verticeAtual < grafo->numVertices; verticeAtual++)
    {
        grauAtual = calcularGrauDoVertice(grafo, verticeAtual);
        if(grauAtual > grauMax)
        {
            grauMax = grauAtual;
            verticeMax = verticeAtual;
        }
    }

    // Retorna o vértice com maior grau
    return verticeMax;
}

void imprimirRecomendacoes(ptrGrafo grafo, int u)
{
    int v; // Vertice que possui aresta com u
    int w; // Vertice que possui aresta com amigo de u

    printf("Recomendações de amigos para o vértice %d:\n", u);
    // Percorre todos os vertices relacionados a u
    for(v = 0; v < grafo->numVertices; v++)
    {
        // Verifica se existe aresta entre u e v
        if(existeAresta(grafo, u, v))
        {
            // Percorre todos os vertices relacionados a v
            for(w = 0; w < grafo->numVertices; w++)
            {
                // verifica se existe aresta entre v e w, 
                // se w é diferente de u e
                // se não existe aresta entre u e w, já que é uma recomendação
                if(existeAresta(grafo, v, w) && (w != u) && !existeAresta(grafo, u, w))
                {
                    printf("Vertice %d\n", w);
                }
            }
        }
    }
}
