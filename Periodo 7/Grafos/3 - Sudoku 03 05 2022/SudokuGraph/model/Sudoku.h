#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <math.h>
#include <windows.h>
#include "GraphMatrix.h"

using namespace std;

class Sudoku {

private:
    GraphMatrix<int>* graph;
    int regions;
    int regionSize;
    int vertexAmount;

public: 
    Sudoku(int regions, int initialVertex) {
        this->regions = regions;
        this->regionSize = sqrt(regions);
        this->vertexAmount = regions * regions;
        this->graph = new GraphMatrix<int>();
        this->buildGraphForSudoku();
        this->graph->vertexes[initialVertex - 1]->color = 1;
        this->solve();
    }

    void printGraph() {
        if (this->graph->getSize() > 0) {
            cout << "\t";
            for(int i = 0; i < this->graph->edges.size(); i++)
                cout << "(" << *this->graph->vertexes[i]->value << ")\t";
            cout << endl;

            for(int i = 0; i < this->graph->edges.size(); i++) {
                cout << "(" << *this->graph->vertexes[i]->value << ")\t";
                for(int j = 0; j < this->graph->edges[i].size(); j++)
                    cout << this->graph->edges[i][j] << "\t";
                cout << endl;
            }
            cout << endl << endl;
        }
    }

    void printColorGraph() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        if (this->graph->getSize() > 0) {
            for (int i = 0; i < regions; i++) {
                for (int j = i * regions; j < regions * (i + 1); j++) {
                    SetConsoleTextAttribute(hConsole, 16 * this->graph->vertexes[j]->color + 7);
                    cout << this->graph->vertexes[j]->color << "\t";
                    SetConsoleTextAttribute(hConsole, 7);
                }
                cout << endl;
            }
            cout << endl << endl;
        }
    }

private:
    void solve() {
        // ((regions - 1) * 2) + (regions - (2 * (regionSize - 1) + 1))
        // (3 * regions) - 1 - (2 * regionSize);

        vector<int> colors(1, 1);

        for (int k = 0; k < vertexAmount - 1; k++) {
            Vertex<int>* targetVertex = this->graph->vertexes[0];
            vector<Vertex<int>*> targetConnectedVertexes;
            vector<int> targetColoredAdjancents;

            for (int i = 1; i <= vertexAmount; i++) {
                Vertex<int>* actualVertex = this->graph->vertexes[i - 1];

                if (actualVertex->color == 0) {
                    vector<Vertex<int>*> connectedVertexes = this->graph->getVertexesConnectedWith(i);

                    vector<int> coloredAdjancents;
                    for (int j = 0; j < connectedVertexes.size(); j++)
                        if (connectedVertexes[j]->color != 0 && !Util::contains(coloredAdjancents, connectedVertexes[j]->color)) 
                            coloredAdjancents.push_back(connectedVertexes[j]->color);

                    if (coloredAdjancents.size() > targetColoredAdjancents.size()) {
                        targetVertex = actualVertex;
                        targetConnectedVertexes = connectedVertexes;
                        targetColoredAdjancents = coloredAdjancents;
                    }
                }
            }

            if (targetColoredAdjancents.size() == colors.size()) {
                colors.push_back(colors.size() + 1);
                targetVertex->color = colors[colors.size() - 1];
            } else {
                for (int i = 0; i < colors.size(); i++)
                    if (Util::getPosition(targetColoredAdjancents, colors[i]) == -1) {
                        targetVertex->color = colors[i];
                        break;
                    }
            }
        }
            
    }

    void buildGraphForSudoku() {
        this->generateVertexes();
        this->connectLinesAndColumns();
        this->connectRegions();
    }

    void generateVertexes() {
        for (int i = 1; i <= this->vertexAmount; i++)
            this->graph->addVertex(i);
    }

    void connectLinesAndColumns() {
        for (int line = 0; line < this->regions; line++) {
            for (int i = 0; i < this->regions; i++) {
                for (int j = i + 1; j < this->regions; j++) {
                    int firstVertexOfLine = (line * this->regions) + 1;
                    
                    // Adding line edge
                    this->graph->addEdgeBetween(firstVertexOfLine + i, firstVertexOfLine + j);

                    // Adding column edge
                    this->graph->addEdgeBetween(
                        firstVertexOfLine + (this->regions * i),
                        firstVertexOfLine + (this->regions * j)
                    );
                }
            }
        }
    }
    
    void connectRegions() {
        vector<vector<int>> regionsVertexes = this->getRegionsVertexes();
        for (int i = 0; i < regionsVertexes.size(); i++)
            for (int j = 0; j < regionsVertexes[i].size(); j++)
                for (int k = 0; k < regionsVertexes[j].size(); k++)
                    if (regionsVertexes[i][j] != regionsVertexes[i][k])
                        this->graph->addEdgeBetween(regionsVertexes[i][j], regionsVertexes[i][k]);
    }

    vector<vector<int>> getRegionsVertexes() {
        vector<vector<int>> regionsVertexes;

        for (int region = 0; region < this->regions; region++) {
            vector<int> regionVector;
            int counter = region / this->regionSize;
            int step = this->regions * (this->regionSize - 1);
            int begin = region * this->regionSize + 1 + counter * step;
            for (int i = begin; i <= begin + step; i += this->regions)
                for (int j = i; j <= i + this->regionSize - 1; j++)
                    regionVector.push_back(j);
            regionsVertexes.push_back(regionVector);
        }

        return regionsVertexes;
    }
};

#endif
