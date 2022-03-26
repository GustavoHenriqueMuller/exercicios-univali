#include <conio.h>
#include <iostream>
#include <algorithm>

#include "screen.h"
#include "utils.h"

void printTelaInicial(const vector<vector<int>> &grafo, const vector<char> &letrasVertices, ModoGrafo modo) {
    cout << "TRABALHO M1 - GRAFOS" << endl << endl;
    printGrafo(grafo, letrasVertices);

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
}

void printGrafo(const vector<vector<int>> &grafo, const vector<char> &letrasVertices) {
    if (grafo.size() == 0) {
        return;
    }

    cout << "    ";

    for (int i = 0; i < letrasVertices.size(); i++) {
        cout << letrasVertices[i] << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < grafo.size(); i++) {
        cout << letrasVertices[i] << "   ";

        for (int j = 0; j < grafo[i].size(); j++) {
            cout << (grafo[i][j] == 1 ? "1" : "-") << " ";
        }

        cout << endl;
    }

    cout << endl;
}

int getVertice(string mensagem, const vector<char> &letrasVertices) {
    cout << endl << mensagem << ":" << endl;

    while (true) {
        char letra = toupper(getch());
        cout << letra << endl;

        auto itr = find(letrasVertices.begin(), letrasVertices.end(), letra);

        if (itr != letrasVertices.cend()) {
            return distance(letrasVertices.begin(), itr);
        } else {
            cout << endl << "Vertice invalido." << endl;
        }
    }
}

ComandoGrafo getComando() {
    int comando;

    while (true) {
        comando = (getch() - 48);

        if (comando < 0 || comando > 8) {
            cout << endl << "Comando invalido." << endl;
        } else {
            break;
        }
    }

    return static_cast<ComandoGrafo>(comando);
}
