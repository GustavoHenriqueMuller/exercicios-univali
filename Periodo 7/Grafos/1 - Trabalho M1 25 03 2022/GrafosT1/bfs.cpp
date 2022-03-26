#include <vector>
#include <queue>
#include <iostream>

#include "utils.h"
#include "bfs.h"

void bfs(const vector<vector<int>> &grafo, const vector<char> &letrasVertices, int verticeInicial, int verticeBusca) {
    vector<bool> verticesVisitados(grafo.size(), false);
    queue<int> caminhoAtual;

    caminhoAtual.push(verticeInicial);

    while (getVerticesNaoVisitados(verticesVisitados).size() > 0) {
        int verticeAtual;

        if (caminhoAtual.empty()) {
            caminhoAtual.push(getVerticesNaoVisitados(verticesVisitados)[0]);
        }

        verticeAtual = caminhoAtual.front();
        caminhoAtual.pop();

        if (verticesVisitados[verticeAtual] == false) {
            verticesVisitados[verticeAtual] = true;

            if (verticeAtual == verticeBusca) {
                cout << "Vertice [" << letrasVertices[verticeAtual] << "] encontrado." << endl;
                return;
            } else {
                cout << "Vertice [" << letrasVertices[verticeAtual] << "] visitado." << endl;
            }

            vector<int> vizinhos = getVizinhos(verticeAtual, grafo);

            for (int i = 0; i < vizinhos.size(); i++) {
                if (verticesVisitados[vizinhos[i]] == false) {
                    caminhoAtual.push(vizinhos[i]);
                }
            }
        }
    }
}
