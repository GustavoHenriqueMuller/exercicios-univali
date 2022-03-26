#ifndef UTILS_H
#define UTILS_H

#include <vector>

using namespace std;

vector<int> getVerticesNaoVisitados(const vector<bool> &verticesVisitados);
vector<int> getVizinhos(int vertice, const vector<vector<int>> &grafo);

#endif // UTILS_H
