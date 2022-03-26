#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>

using namespace std;

enum ModoGrafo {
    DIRIGIDO,
    NAO_DIRIGIDO
};

enum ComandoGrafo {
    SAIR,
    ADICIONAR_VERTICE,
    REMOVER_VERTICE,
    ADICIONAR_CONEXAO,
    REMOVER_CONEXAO,
    MUDAR_MODO,
    DFS,
    DFS_BUSCA,
    BFS,
    BFS_BUSCA
};

void printTelaInicial(const vector<vector<int>> &grafo, const vector<char> &letrasVertices, ModoGrafo modo);
void printGrafo(const vector<vector<int>> &grafo, const vector<char> &letrasVertices);

int getVertice(string mensagem, const vector<char> &letrasVertices);
ComandoGrafo getComando();

#endif // SCREEN_H
