#include <algorithm>

#include "operations.h"
#include "screen.h"

void adicionarVertice(vector<vector<int>> &grafo, vector<char> &letrasVertices) {
    char letra = 'A';

    while (true) {
        if (find(letrasVertices.begin(), letrasVertices.end(), letra) == letrasVertices.end()) {
            letrasVertices.push_back(letra);
            break;
        }

        letra++;
    }

    vector<int> vertice(grafo.size(), 0);
    grafo.push_back(vertice);

    for (int i = 0; i < grafo.size(); i++) {
        grafo[i].push_back(0);
    }
}

void removerVertice(vector<vector<int>> &grafo, vector<char> &letrasVertices, int vertice) {
    letrasVertices.erase(letrasVertices.begin() + vertice);

    grafo.erase(grafo.begin() + vertice);

    for (int i = 0; i < grafo.size(); i++) {
        grafo[i].erase(grafo[i].begin() + vertice);
    }
}

void adicionarAresta(vector<vector<int>> &grafo, int verticeOrigem, int verticeDestino) {
    adicionarArco(grafo, verticeOrigem, verticeDestino);
    adicionarArco(grafo, verticeDestino, verticeOrigem);
}

void adicionarArco(vector<vector<int>> &grafo, int verticeOrigem, int verticeDestino) {
    grafo[verticeOrigem][verticeDestino] = 1;
}

void removerAresta(vector<vector<int>> &grafo, int verticeOrigem, int verticeDestino) {
    removerArco(grafo, verticeOrigem, verticeDestino);
    removerArco(grafo, verticeDestino, verticeOrigem);
}

void removerArco(vector<vector<int>> &grafo, int verticeOrigem, int verticeDestino) {
    grafo[verticeOrigem][verticeDestino] = 0;
}
