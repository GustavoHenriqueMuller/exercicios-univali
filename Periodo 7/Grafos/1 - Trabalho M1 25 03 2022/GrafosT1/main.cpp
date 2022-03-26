#include <conio.h>
#include <vector>
#include <iostream>

#include "dfs.h"
#include "bfs.h"
#include "screen.h"
#include "operations.h"

int main() {
    vector<vector<int>> grafo;
    vector<char> letrasVertices;

    ComandoGrafo comando;
    ModoGrafo modoGrafo = DIRIGIDO;

    while (true) {
        printTelaInicial(grafo, letrasVertices, modoGrafo);
        comando = getComando();

        switch (comando) {
            case SAIR: {
                return 0;
            }
            case ADICIONAR_VERTICE: {
                adicionarVertice(grafo, letrasVertices);
                break;
            }
            case REMOVER_VERTICE: {
                int vertice = getVertice("Digite o vertice a ser removido", letrasVertices);

                removerVertice(grafo, letrasVertices, vertice);
                break;
            }
            case ADICIONAR_CONEXAO: {
                int verticeOrigem = getVertice("Digite o vertice de origem", letrasVertices);
                int verticeDestino = getVertice("Digite o vertice de destino", letrasVertices);

                if (modoGrafo == DIRIGIDO) {
                    adicionarAresta(grafo, verticeOrigem, verticeDestino);
                } else {
                    adicionarArco(grafo, verticeOrigem, verticeDestino);
                }

                break;
            }
            case REMOVER_CONEXAO: {
                int verticeOrigem = getVertice("Digite o vertice de origem", letrasVertices);
                int verticeDestino = getVertice("Digite o vertice de destino", letrasVertices);

                if (modoGrafo == DIRIGIDO) {
                    removerAresta(grafo, verticeOrigem, verticeDestino);
                } else {
                    removerArco(grafo, verticeOrigem, verticeDestino);
                }

                break;
            }
            case MUDAR_MODO: {
                modoGrafo = modoGrafo == DIRIGIDO ? NAO_DIRIGIDO : DIRIGIDO;
                break;
            }
            case DFS: {
                int verticeOrigem = getVertice("Digite o vertice de inicio", letrasVertices);

                cout << endl;
                dfs(grafo, letrasVertices, verticeOrigem);

                getch();
                break;
            }
            case DFS_BUSCA: {
                int verticeOrigem = getVertice("Digite o vertice de inicio", letrasVertices);
                int verticeBusca = getVertice("Digite o vertice de busca", letrasVertices);

                cout << endl;
                dfs(grafo, letrasVertices, verticeOrigem, verticeBusca);

                getch();
                break;
            }
            case BFS: {
                int verticeOrigem = getVertice("Digite o vertice de inicio", letrasVertices);

                cout << endl;
                bfs(grafo, letrasVertices, verticeOrigem);

                getch();
                break;
            }
            case BFS_BUSCA: {
                int verticeOrigem = getVertice("Digite o vertice de inicio", letrasVertices);
                int verticeBusca = getVertice("Digite o vertice de busca", letrasVertices);

                cout << endl;
                bfs(grafo, letrasVertices, verticeOrigem, verticeBusca);

                getch();
                break;
            }
        }

        system("cls");
    };
}
