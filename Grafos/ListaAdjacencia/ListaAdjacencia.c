#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaAdjacencia.h"

ptrGrafo criarGrafo(int numVertices)
{
    // Alocando memoria para o grafo
    ptrGrafo grafo = malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;

    // Alocando memoria para as listas
    grafo->listaAdj = malloc(numVertices * sizeof(No*));

    // Inicializando as listas com valor NULL
    for(int i = 0; i < numVertices; i++)
    {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

void destruirLista(No* lista)
{
    if(lista != NULL)
    {
        // Percorre ate o ultimo no, depois volta liberando
        destruirLista(lista->prox);
        free(lista);
    }
}

void destruirGrafo(ptrGrafo grafo)
{
    for(int i = 0; i < grafo->numVertices; i++)
    {
        destruirLista(grafo->listaAdj[i]);
    }
    free(grafo->listaAdj);
    free(grafo);
}

No* inserirNaLista(No* lista, int v)
{
    // Criando novo no da lista
    No* novo = malloc(sizeof(No));
    novo->v = v;

    // Inserindo no inicio
    novo->prox = lista;

    // Retornando o no para ajustar o ponteiro da lista
    return novo;
}

void inserirAresta(ptrGrafo grafo, int u, int v)
{
    // Adicionando vertice v nma lista de u
    grafo->listaAdj[u] = inserirNaLista(grafo->listaAdj[u], v);
    // Adicionando vertice u nma lista de v
    grafo->listaAdj[v] = inserirNaLista(grafo->listaAdj[v], u);
    // // Caso seja um digrafo, não é necessário atualizar v na lista de u
}

No* removerDaLista(No* lista, int v)
{
    No* proximo;
    if(lista == NULL)
    {
        return NULL;
    }
    // Se o no for encontrado
    else if(lista->v == v)
    {
        // proximo recebe o proximo no do no atual
        proximo = lista->prox;
        free(lista); // Libera o no atual
        return proximo;
    }
    else
    {
        lista->prox = removerDaLista(lista->prox, v);
        return lista;
    }
}

void removerAresta(ptrGrafo grafo, int u, int v)
{
    // Removendo vertice v nma lista de u
    grafo->listaAdj[u] = removerDaLista(grafo->listaAdj[u], v);
    // Removendo vertice u nma lista de v
    grafo->listaAdj[v] = removerDaLista(grafo->listaAdj[v], u);
    // // Caso seja um digrafo, não é necessário atualizar v na lista de u
}

bool existeAresta(ptrGrafo grafo, int u, int v)
{
    No* atual;
    for(atual = grafo->listaAdj[u]; atual != NULL; atual = atual->prox)
    {
        if(atual->v == v)
        {
            return true;
        }
    }

    return false;
}

void imprimirAresta(ptrGrafo grafo)
{
    No* atual;
    for(int i = 0; i < grafo->numVertices; i++)
    {
        for(atual = grafo->listaAdj[i]; atual != NULL; atual = atual->prox)
        {
            printf("%d ",atual->v);
        }

        printf("\n");
    }
}

