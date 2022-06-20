#ifndef GRAPH_BUILDER_H
#define GRAPH_BUILDER_H

#include "GraphMatrix.h"
#include "FileManager.h"

using namespace std;

class GraphBuilder {

public:
    GraphBuilder() {
        this->buildGraphsFromFile();
    }

    GraphMatrix<int>* getGraph(int index) {
        return this->graphs[index];
    }

    vector<GraphMatrix<int>*> getGraphs() {
        return this->graphs;
    }

private:
    vector<GraphMatrix<int>*> graphs;

    void buildGraphsFromFile() {
        vector<string> lines = getFileContent("inputs.txt");
        vector<vector<int>> data = extractData(lines);

        for (int i = 0; i < data.size(); i++) {
            vector<int> problem = data[i];
            this->initGraphAndAddVertexes(problem[0]);
            
            for (int j = 1; j < problem.size(); j++) {
                int weight = problem[j];
                for (Vertex<int>* vertex : this->graphs[i]->vertexes) {
                    Vertex<int>* targetVertex = this->findFirstVertexWithoutConnection(vertex, i);
                    if (targetVertex == nullptr) continue;
                    this->graphs[i]->addEdgeBetween(*targetVertex->value, *vertex->value, weight);
                    break;
                }
            }
        }
    }

    Vertex<int>* findFirstVertexWithoutConnection(Vertex<int>* targetVertex, int graphIndex) {
        vector<Vertex<int>*> edges = this->graphs[graphIndex]->getEdgesOf(targetVertex);
        for (Vertex<int>* vertex : this->graphs[graphIndex]->vertexes)
            if (*targetVertex->value != *vertex->value && !Util::contains(edges, vertex))
                return vertex;
        return nullptr;
    }

    void initGraphAndAddVertexes(int amount) {
        GraphMatrix<int>* graph = new GraphMatrix<int>();
        for (int i = 1; i <= amount; i++)
            graph->addVertex(i);
        this->graphs.push_back(graph);
    }
};

#endif
