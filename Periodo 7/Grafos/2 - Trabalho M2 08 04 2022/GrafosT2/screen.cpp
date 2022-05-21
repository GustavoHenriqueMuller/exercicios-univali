#include <conio.h>
#include <iostream>
#include <algorithm>

#include "screen.h"
#include "utils.h"
#include "graph.h"

void printTelaInicial(const Grafo &grafo, ModoGrafo modo) {
    cout << "TRABALHO M2 - GRAFOS" << endl << endl;
    printGrafo(grafo);

    cout << "Modo " << (modo == DIRIGIDO ? "dirigido" : "nao dirigido") << endl << endl;

    cout << "[0] - Sair" << endl;
    cout << "[1] - Adicionar vertice" << endl;
    cout << "[2] - Remover vertice" << endl;
    cout << "[3] - Adicionar conexao" << endl;
    cout << "[4] - Remover conexao" << endl;
    cout << "[5] - Mudar para " << (modo == DIRIGIDO ? "nao dirigido" : "dirigido") << endl;
    cout << "[6] - DFS" << endl;
    cout << "[7] - DFS (busca)" << endl;
    cout << "[8] - BFS" << endl;
    cout << "[9] - BFS (busca)" << endl;
    cout << "[10] - Checar conexidade (fechos transitivos)" << endl;
    cout << "[11] - Calcular sub-grafos fortemente conexos" << endl;
}

void printGrafo(const Grafo &grafo) {
    if (grafo.size() == 0) {
        return;
    }

    cout << "    ";

    for (int i = 0; i < grafo.letrasVertices.size(); i++) {
        cout << grafo.letrasVertices[i] << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < grafo.size(); i++) {
        cout << grafo.letrasVertices[i] << "   ";

        for (int j = 0; j < grafo.matriz[i].size(); j++) {
            cout << (grafo.matriz[i][j] == 1 ? "1" : "-") << " ";
        }

        cout << endl;
    }

    cout << endl;
}

int getVertice(string mensagem, const Grafo &grafo) {
    cout << mensagem << ":" << endl;

    while (true) {
        char letra = toupper(getch());
        cout << letra << endl << endl;

        auto itr = find(grafo.letrasVertices.begin(), grafo.letrasVertices.end(), letra);

        if (itr != grafo.letrasVertices.cend()) {
            return distance(grafo.letrasVertices.begin(), itr);
        } else {
            cout << endl << "Vertice invalido." << endl;
        }
    }
}

ComandoGrafo getComando() {
    int comando;

    while (true) {
        cin >> comando;

        if (comando < 0 || comando > 11) {
            cout << endl << "Comando invalido." << endl;
        } else {
            break;
        }
    }

    return static_cast<ComandoGrafo>(comando);
}
