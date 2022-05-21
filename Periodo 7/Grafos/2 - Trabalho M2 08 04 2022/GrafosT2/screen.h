#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>

#include "graph.h"

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
    BFS_BUSCA,
    CHECAR_CONEXIDADE,
    SUBGRAFOS_FORTEMENTE_CONEXOS
};

void printTelaInicial(const Grafo &grafo, ModoGrafo modo);
void printGrafo(const Grafo &grafo);

int getVertice(string mensagem, const Grafo &grafo);
ComandoGrafo getComando();

#endif // SCREEN_H
