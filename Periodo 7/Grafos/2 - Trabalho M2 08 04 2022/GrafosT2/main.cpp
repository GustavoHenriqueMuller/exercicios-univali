#include <conio.h>
#include <vector>
#include <iostream>

#include "dfs.h"
#include "bfs.h"
#include "connection.h"
#include "screen.h"
#include "operations.h"

int main() {
    Grafo grafo;

    ComandoGrafo comando;
    ModoGrafo modoGrafo = DIRIGIDO;

    while (true) {
        printTelaInicial(grafo, modoGrafo);

        cout << endl;
        comando = getComando();
        cout << endl;

        switch (comando) {
            case SAIR: {
                return 0;
            }
            case ADICIONAR_VERTICE: {
                adicionarVertice(grafo);
                break;
            }
            case REMOVER_VERTICE: {
                int vertice = getVertice("Digite o vertice a ser removido", grafo);

                removerVertice(grafo,  vertice);
                break;
            }
            case ADICIONAR_CONEXAO: {
                int verticeOrigem = getVertice("Digite o vertice de origem", grafo);
                int verticeDestino = getVertice("Digite o vertice de destino", grafo);

                if (modoGrafo == DIRIGIDO) {
                    adicionarAresta(grafo, verticeOrigem, verticeDestino);
                } else {
                    adicionarArco(grafo, verticeOrigem, verticeDestino);
                }

                break;
            }
            case REMOVER_CONEXAO: {
                int verticeOrigem = getVertice("Digite o vertice de origem", grafo);
                int verticeDestino = getVertice("Digite o vertice de destino", grafo);

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
                int verticeOrigem = getVertice("Digite o vertice de inicio", grafo);

                dfs(grafo, verticeOrigem);

                getch();
                break;
            }
            case DFS_BUSCA: {
                int verticeOrigem = getVertice("Digite o vertice de inicio", grafo);
                int verticeBusca = getVertice("Digite o vertice de busca", grafo);

                dfs(grafo, verticeOrigem, verticeBusca);

                getch();
                break;
            }
            case BFS: {
                int verticeOrigem = getVertice("Digite o vertice de inicio", grafo);

                bfs(grafo, verticeOrigem);

                getch();
                break;
            }
            case BFS_BUSCA: {
                int verticeOrigem = getVertice("Digite o vertice de inicio", grafo);
                int verticeBusca = getVertice("Digite o vertice de busca", grafo);

                bfs(grafo, verticeOrigem, verticeBusca);

                getch();
                break;
            }
            case CHECAR_CONEXIDADE: {
                bool isConexo = isFortementeConexo(grafo);

                if (isConexo) {
                    cout << "O grafo e fortemente conexo." << endl;
                } else {
                    cout << "O grafo nao e fortemente conexo." << endl;
                }

                getch();
                break;
            }
            case SUBGRAFOS_FORTEMENTE_CONEXOS: {
                vector<Grafo> subgrafos = getSubgrafosFortementeConexos(grafo);

                for (int i = 0; i < subgrafos.size(); i++) {
                    cout << "SUBGRAFO FORTEMENTE CONEXO [" << i << "]" << endl << endl;
                    printGrafo(subgrafos[i]);
                    cout << endl;
                }

                getch();
                break;
            }
        }

        system("cls");
    };
}

