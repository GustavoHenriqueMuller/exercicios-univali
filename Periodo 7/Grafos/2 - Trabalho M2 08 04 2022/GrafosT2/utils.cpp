#include "utils.h"
#include "graph.h"

vector<int> getVerticesNaoVisitados(const vector<bool> &verticesVisitados) {
    vector<int> verticesNaoVisitados;

    for (int i = 0; i < verticesVisitados.size(); i++) {
        if (!verticesVisitados.at(i)) {
            verticesNaoVisitados.push_back(i);
        }
    }

    return verticesNaoVisitados;
}

vector<int> getVizinhos(const Grafo &grafo, int vertice) {
    vector<int> vizinhos;

    for (int i = 0; i < grafo.matriz[vertice].size(); i++) {
        if (grafo.matriz[vertice][i] == 1) {
            vizinhos.push_back(i);
        }
    }

    return vizinhos;
}

vector<int> getVerticesComVizinho(const Grafo &grafo, int vizinho) {
    vector<int> vertices;

    for (int i = 0; i < grafo.size(); i++) {
        if (grafo.matriz[i][vizinho] == 1) {
            vertices.push_back(i);
        }
    }

    return vertices;
}


