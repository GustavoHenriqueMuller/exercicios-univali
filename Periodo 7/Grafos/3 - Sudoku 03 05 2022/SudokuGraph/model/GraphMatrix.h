#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include "Graph.h"

using namespace std;

template<class T>
class GraphMatrix : public Graph<T> {

public:
    vector<vector<bool>> edges;

    GraphMatrix() { }

    void addVertex(Vertex<T>* newVertex) {
        if (this->getPositionOf(*newVertex->value) == -1) {
            this->vertexes.push_back(newVertex);

            vector<bool> newEdgeLine(this->edges.size(), false);
            this->edges.push_back(newEdgeLine);

            for (vector<bool> &line : this->edges) 
                line.push_back(false);
        }
    }

    void addVertex(T* newVertex) {
        this->addVertex(new Vertex<T>(newVertex));
    }

    void addVertex(const T &newVertex) {
        this->addVertex(new Vertex<T>(newVertex));
    }

    void addEdgeBetween(const T &firstVertex, const T &secondVertex) {
        int firstVertexIndex = this->getPositionOf(firstVertex);
        int secondVertexIndex = this->getPositionOf(secondVertex);

        if (this->indexIsValid(firstVertexIndex) && this->indexIsValid(secondVertexIndex)) {
            this->edges[firstVertexIndex][secondVertexIndex] = true;
            this->edges[secondVertexIndex][firstVertexIndex] = true;
        }
    }

    void removeVertex(const T &vertex) {
        int vertexIndex = this->getPositionOf(vertex);
        if (this->indexIsValid(vertexIndex)) {
            for (vector<bool> &line : this->edges)
                line.erase(line.begin() + vertexIndex);
            this->edges.erase(this->edges.begin() + vertexIndex);  
            delete this->vertexes[vertexIndex];
            this->vertexes.erase(this->vertexes.begin() + vertexIndex);
        }
    }

    void removeEdgeBetween(const T &firstVertex, const T &secondVertex) {
        int firstVertexIndex = this->getPositionOf(firstVertex);
        int secondVertexIndex = this->getPositionOf(secondVertex);

        if (this->indexIsValid(firstVertexIndex) && this->indexIsValid(secondVertexIndex)) {
            this->edges[firstVertexIndex][secondVertexIndex] = false;
            this->edges[secondVertexIndex][firstVertexIndex] = false;
        }
    }

    vector<Vertex<T>*> getEdgesOf(const T &value) {
        int index = this->getPositionOf(value);
        vector<Vertex<T>*> edgesReturn;
        if (this->indexIsValid(index)) {
            for (int i = 0; i < this->edges.size(); i++)
                if (this->edges[index][i])
                    edgesReturn.push_back(this->vertexes[i]);
        }
        return edgesReturn;
    }
    
    vector<Vertex<T>*> getVertexesConnectedWith(const T &value) {
        int index = this->getPositionOf(value);
        vector<Vertex<T>*> edgesReturn;
        if (this->indexIsValid(index)) {
            for (int i = 0; i < this->edges.size(); i++)
                if (this->edges[i][index])
                    edgesReturn.push_back(this->vertexes[i]);
        }
        return edgesReturn;
    }

    void destroy() {
        this->edges.clear();
    }

};

#endif
