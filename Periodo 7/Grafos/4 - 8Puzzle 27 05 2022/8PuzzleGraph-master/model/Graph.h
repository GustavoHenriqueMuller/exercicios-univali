#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include "Util.h"
#include "Vertex.h"

using namespace std;

template<class T>
class GraphList;

template<class T>
class GraphMatrix;

template<class T>
class Graph {

protected:
    bool directed;

    Graph() {
        this->directed = false;
    }

    Graph(bool directed) {
        this->directed = directed;
    }

public:
    vector<Vertex<T>*> vertexes;

    virtual void addVertex(Vertex<T>* newVertex) = 0;

    virtual void addVertex(T* newVertex) = 0;

    virtual void addVertex(const T &newVertex) = 0;

    virtual void addEdgeBetween(const T &firstVertex, const T &secondVertex) = 0;

    virtual void removeVertex(const T &vertexIndex) = 0;

    virtual void removeEdgeBetween(const T &firstVertex, const T &secondVertex) = 0;

    virtual vector<Vertex<T>*> getEdgesOf(Vertex<T>* vertex) = 0;

    virtual vector<Vertex<T>*> getVertexesConnectedWith(Vertex<T>* vertex) = 0;

    virtual void destroy() = 0;

    bool isDirected() {
        return this->directed;
    }

    int getSize() {
        return this->vertexes.size();
    }

    bool indexIsValid(const int &vertexIndex) {
        return vertexIndex >= 0 && vertexIndex < this->vertexes.size();
    }

    int getPositionOf(T* targetValue) {
        return Util::getPosition<T>(this->vertexes, targetValue);
    }

    int getPositionOf(const T &targetValue) {
        for (int i = 0; i < this->vertexes.size(); i++)
            if (*(this->vertexes[i]->value) == targetValue)
                return i;
        return -1;
    }

    bool isList() {
        return dynamic_cast<const GraphList<T>*>(this) != nullptr;
    }

    bool isMatrix() {
        return dynamic_cast<const GraphMatrix<T>*>(this) != nullptr;
    }
};

#endif
