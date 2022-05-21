#ifndef UTILS_H
#define UTILS_H

#include <vector>

#include "graph.h"

using namespace std;

vector<int> getVerticesNaoVisitados(const vector<bool> &verticesVisitados);
vector<int> getVizinhos(const Grafo &grafo, int vertice);
vector<int> getVerticesComVizinho(const Grafo &grafo, int vizinho);

#endif // UTILS_H
