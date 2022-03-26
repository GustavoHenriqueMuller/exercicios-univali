#include <iostream>

#include "utils.h"

vector<int> getVerticesNaoVisitados(const vector<bool> &verticesVisitados) {
    vector<int> verticesNaoVisitados;

    for (int i = 0; i < verticesVisitados.size(); i++) {
        if (!verticesVisitados.at(i)) {
            verticesNaoVisitados.push_back(i);
        }
    }

    return verticesNaoVisitados;
}

vector<int> getVizinhos(int vertice, const vector<vector<int>> &grafo) {
    vector<int> vizinhos;

    for (int i = 0; i < grafo[vertice].size(); i++) {
        if (grafo[vertice][i] == 1) {
            vizinhos.push_back(i);
        }
    }

    return vizinhos;
}
