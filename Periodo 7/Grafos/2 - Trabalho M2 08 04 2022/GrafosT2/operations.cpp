#include <algorithm>

#include "operations.h"
#include "screen.h"

void adicionarVertice(Grafo &grafo) {
    char letra = 'A';

    while (true) {
        if (find(grafo.letrasVertices.begin(), grafo.letrasVertices.end(), letra) == grafo.letrasVertices.end()) {
            grafo.letrasVertices.push_back(letra);
            break;
        }

        letra++;
    }

    vector<int> vertice(grafo.size(), 0);
    grafo.matriz.push_back(vertice);

    for (int i = 0; i < grafo.size(); i++) {
        grafo.matriz[i].push_back(0);
    }
}

void removerVertice(Grafo &grafo, int vertice) {
    grafo.letrasVertices.erase(grafo.letrasVertices.begin() + vertice);

    grafo.matriz.erase(grafo.matriz.begin() + vertice);

    for (int i = 0; i < grafo.size(); i++) {
        grafo.matriz[i].erase(grafo.matriz[i].begin() + vertice);
    }
}

void adicionarAresta(Grafo &grafo, int verticeOrigem, int verticeDestino) {
    adicionarArco(grafo, verticeOrigem, verticeDestino);
    adicionarArco(grafo, verticeDestino, verticeOrigem);
}

void adicionarArco(Grafo &grafo, int verticeOrigem, int verticeDestino) {
    grafo.matriz[verticeOrigem][verticeDestino] = 1;
}

void removerAresta(Grafo &grafo, int verticeOrigem, int verticeDestino) {
    removerArco(grafo, verticeOrigem, verticeDestino);
    removerArco(grafo, verticeDestino, verticeOrigem);
}

void removerArco(Grafo &grafo, int verticeOrigem, int verticeDestino) {
    grafo.matriz[verticeOrigem][verticeDestino] = 0;
}
