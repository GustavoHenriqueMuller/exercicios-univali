#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <vector>

using namespace std;

void adicionarVertice(vector<vector<int>> &grafo, vector<char> &letrasVertices);
void removerVertice(vector<vector<int>> &grafo, vector<char> &letrasVertices, int vertice);

void adicionarAresta(vector<vector<int>> &grafo, int verticeOrigem, int verticeDestino);
void adicionarArco(vector<vector<int>> &grafo, int verticeOrigem, int verticeDestino);

void removerAresta(vector<vector<int>> &grafo, int verticeOrigem, int verticeDestino);
void removerArco(vector<vector<int>> &grafo, int verticeOrigem, int verticeDestino);

#endif // OPERATIONS_H
