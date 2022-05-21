#include <queue>
#include <algorithm>

#include "connection.h"
#include "utils.h"
#include "operations.h"
#include "screen.h"

bool isFortementeConexo(const Grafo &grafo) {
    vector<int> fechoTransitivoDireto = getFechoTransitivoDireto(grafo, 0);
    vector<int> fechoTransitivoInverso = getFechoTransitivoInverso(grafo, 0);
    vector<int> interseccao = getInterseccaoFechos(fechoTransitivoDireto, fechoTransitivoInverso);

    return interseccao.size() == grafo.size();
}

vector<int> getFechoTransitivoDireto(const Grafo &grafo, int vertice) {
    vector<int> fechoTransitivoDireto(grafo.size(), -1);
    queue<int> caminhoAtual;

    fechoTransitivoDireto[vertice] = 0;
    caminhoAtual.push(vertice);

    while (!caminhoAtual.empty()) {
        int verticeAtual = caminhoAtual.front();
        caminhoAtual.pop();

        vector<int> vizinhos = getVizinhos(grafo, verticeAtual);

        for (int i = 0; i < vizinhos.size(); i++) {
            int vizinho = vizinhos[i];

            if (fechoTransitivoDireto[vizinho] == -1) {
                caminhoAtual.push(vizinho);
                fechoTransitivoDireto[vizinho] = fechoTransitivoDireto[verticeAtual] + 1;
            }
        }
    }

    return fechoTransitivoDireto;
}

vector<int> getFechoTransitivoInverso(const Grafo &grafo, int vertice) {
    vector<int> fechoTransitivoInverso(grafo.size(), -1);
    queue<int> caminhoAtual;

    fechoTransitivoInverso[vertice] = 0;
    caminhoAtual.push(vertice);

    while (!caminhoAtual.empty()) {
        int verticeAtual = caminhoAtual.front();
        caminhoAtual.pop();

        vector<int> verticesComVizinho = getVerticesComVizinho(grafo, verticeAtual);

        for (int i = 0; i < verticesComVizinho.size(); i++) {
            int vertice = verticesComVizinho[i];

            if (fechoTransitivoInverso[vertice] == -1) {
                caminhoAtual.push(vertice);
                fechoTransitivoInverso[vertice] = fechoTransitivoInverso[verticeAtual] + 1;
            }
        }
    }

    return fechoTransitivoInverso;
}

vector<int> getInterseccaoFechos(const vector<int> &fecho1, const vector<int> &fecho2) {
    vector<int> interseccao;

    for (int i = 0; i < fecho1.size(); i++) {
        if (fecho1[i] != -1 && fecho2[i] != -1) {
            interseccao.push_back(i);
        }
    }

    return interseccao;
}

vector<Grafo> getSubgrafosFortementeConexos(const Grafo &grafo) {
    vector<Grafo> subgrafos;
    vector<bool> verticesVisitados(grafo.size(), false);

    while (getVerticesNaoVisitados(verticesVisitados).size() > 0) {
        int vertice = getVerticesNaoVisitados(verticesVisitados)[0];

        vector<int> fechoTransitivoDireto = getFechoTransitivoDireto(grafo, vertice);
        vector<int> fechoTransitivoInverso = getFechoTransitivoInverso(grafo, vertice);
        vector<int> interseccao = getInterseccaoFechos(fechoTransitivoDireto, fechoTransitivoInverso);

        for (int i = 0; i < interseccao.size(); i++) {
            verticesVisitados[interseccao[i]] = true;
        }

        Grafo subgrafo = grafo;
        vector<int> verticesNaoPresentes;

        for (int i = 0; i < subgrafo.size(); i++) {
            if (find(interseccao.begin(), interseccao.end(), i) == interseccao.end()) {
                verticesNaoPresentes.push_back(i);
            }
        }

        for (int i = verticesNaoPresentes.size() - 1; i >= 0; i--) {
            removerVertice(subgrafo, verticesNaoPresentes[i]);
        }

        subgrafos.push_back(subgrafo);
    }

    return subgrafos;
}
