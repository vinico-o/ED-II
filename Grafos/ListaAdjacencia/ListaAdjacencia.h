#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
    int v; // Vertice
    struct No* prox; //Ponteiro para proximo vertice
} No;

typedef struct ListaAdjacencia
{
    No** listaAdj; // Ponteiro para o array de listas
    int numVertices; //Numero de vertices
} Grafo;

typedef Grafo* ptrGrafo; // Ponteiro para o grafo

ptrGrafo criarGrafo(int numVertices);
void destruirLista(No* lista);
void destruirGrafo(ptrGrafo grafo);
No* inserirNaLista(No* lista, int v);
void inserirAresta(ptrGrafo grafo, int u, int v);
No* removerDaLista(No* lista, int v);
void removerAresta(ptrGrafo grafo, int u, int v);
bool existeAresta(ptrGrafo grafo, int u, int v);
void imprimirAresta(ptrGrafo grafo);
