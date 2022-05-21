#include <vector>
#include <queue>
#include <iostream>

#include "utils.h"
#include "bfs.h"
#include "screen.h"

void bfs(const Grafo &grafo, int verticeInicial, int verticeBusca) {
    vector<bool> verticesVisitados(grafo.size(), false);
    queue<int> caminhoAtual;

    caminhoAtual.push(verticeInicial);

    while (getVerticesNaoVisitados(verticesVisitados).size() > 0) {
        if (caminhoAtual.empty()) {
            caminhoAtual.push(getVerticesNaoVisitados(verticesVisitados)[0]);
        }

        int verticeAtual = caminhoAtual.front();
        caminhoAtual.pop();

        if (verticesVisitados[verticeAtual] == false) {
            verticesVisitados[verticeAtual] = true;

            if (verticeAtual == verticeBusca) {
                cout << "Vertice [" << grafo.letrasVertices[verticeAtual] << "] encontrado." << endl;
                return;
            } else {
                cout << "Vertice [" << grafo.letrasVertices[verticeAtual] << "] visitado." << endl;
            }

            vector<int> vizinhos = getVizinhos(grafo, verticeAtual);

            for (int i = 0; i < vizinhos.size(); i++) {
                if (verticesVisitados[vizinhos[i]] == false) {
                    caminhoAtual.push(vizinhos[i]);
                }
            }
        }
    }
}
