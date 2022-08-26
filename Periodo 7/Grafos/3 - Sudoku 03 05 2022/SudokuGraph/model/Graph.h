#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include "Util.h"
#include "Vertex.h"

using namespace std;

template<class T>
class GraphMatrix;

template<class T>
class Graph {

protected:
    Graph() { }

public:
    vector<Vertex<T>*> vertexes;

    virtual void addVertex(Vertex<T>* newVertex) = 0;

    virtual void addVertex(T* newVertex) = 0;

    virtual void addVertex(const T &newVertex) = 0;

    virtual void addEdgeBetween(const T &firstVertex, const T &secondVertex) = 0;

    virtual void removeVertex(const T &vertexIndex) = 0;

    virtual void removeEdgeBetween(const T &firstVertex, const T &secondVertex) = 0;

    virtual vector<Vertex<T>*> getEdgesOf(const T &value) = 0;

    virtual vector<Vertex<T>*> getVertexesConnectedWith(const T &value) = 0;

    virtual void destroy() = 0;

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

    bool isMatrix() {
        return dynamic_cast<const GraphMatrix<T>*>(this) != nullptr;
    }
};

#endif
