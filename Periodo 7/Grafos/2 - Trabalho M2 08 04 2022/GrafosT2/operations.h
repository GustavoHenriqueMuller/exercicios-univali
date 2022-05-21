#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <vector>

#include "graph.h"

using namespace std;

void adicionarVertice(Grafo &grafo);
void removerVertice(Grafo &grafo, int vertice);

void adicionarAresta(Grafo &grafo, int verticeOrigem, int verticeDestino);
void adicionarArco(Grafo &grafo, int verticeOrigem, int verticeDestino);

void removerAresta(Grafo &grafo, int verticeOrigem, int verticeDestino);
void removerArco(Grafo &grafo, int verticeOrigem, int verticeDestino);

#endif // OPERATIONS_H
