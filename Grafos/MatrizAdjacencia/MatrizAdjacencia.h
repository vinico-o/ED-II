#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int **matrizAdj;   // Matriz de adjacência
    int numVertices;   // Número de vértices
} Grafo;

typedef Grafo* ptrGrafo; // Ponteiro para o grafo

ptrGrafo criarGrafo(int numVertices);
void destruirGrafo(ptrGrafo grafo);
void inserirAresta(ptrGrafo grafo, int u, int v);
void removerAresta(ptrGrafo grafo, int u, int v);
bool existeAresta(ptrGrafo grafo, int u, int v);
ptrGrafo lerGrafo();
void imprimirGrafo(ptrGrafo grafo);
int calcularGrauDoVertice(ptrGrafo grafo, int u);
int calcularVerticeComMaiorGrau(ptrGrafo grafo);
void imprimirRecomendacoes(ptrGrafo grafo, int u);
