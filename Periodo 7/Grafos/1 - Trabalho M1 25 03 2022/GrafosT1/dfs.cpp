#include <vector>
#include <stack>
#include <iostream>

#include "utils.h"
#include "dfs.h"

void dfs(const vector<vector<int>> &grafo, const vector<char> &letrasVertices, int verticeInicial, int verticeBusca) {
    vector<bool> verticesVisitados(grafo.size(), false);
    stack<int> caminhoAtual;

    caminhoAtual.push(verticeInicial);

    while (getVerticesNaoVisitados(verticesVisitados).size() > 0) {
        int verticeAtual;

        if (caminhoAtual.empty()) {
            caminhoAtual.push(getVerticesNaoVisitados(verticesVisitados)[0]);
        }

        verticeAtual = caminhoAtual.top();
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

            for (int i = vizinhos.size() - 1; i >= 0; i--) {
                if (verticesVisitados[vizinhos[i]] == false) {
                    caminhoAtual.push(vizinhos[i]);
                }
            }
        }
    }
}

