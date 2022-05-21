#ifndef CONNECTION_H
#define CONNECTION_H

#include <vector>

#include "graph.h"

using namespace std;

bool isFortementeConexo(const Grafo &grafo);

vector<int> getFechoTransitivoDireto(const Grafo &grafo, int vertice);
vector<int> getFechoTransitivoInverso(const Grafo &grafo, int vertice);
vector<int> getInterseccaoFechos(const vector<int> &fecho1, const vector<int> &fecho2);

vector<Grafo> getSubgrafosFortementeConexos(const Grafo &grafo);

#endif // CONNECTION_H
