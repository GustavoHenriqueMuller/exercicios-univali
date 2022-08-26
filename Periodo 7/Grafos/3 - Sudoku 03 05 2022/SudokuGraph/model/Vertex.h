#ifndef VERTEX_H
#define VERTEX_H

#include "Util.h"

using namespace std;

template<class T>
class Vertex {

public:
    T* value;
    int color;
    vector<Vertex<T>*> edges;

    Vertex() {
        this->value = nullptr;
        this->color = 0;
    }

    Vertex(T* value) {
        this->value = value;
        this->color = 0;
    }
    
    Vertex(const T &value) {
        this->value = new T(value);
        this->color = 0;
    }

    void addEdge(Vertex<T>* newEdge) {
        if (!Util::contains<Vertex<T>*>(this->edges, newEdge))
            this->edges.push_back(newEdge);
    }

    void removeEdgeAt(const int &edgeIndex) {
        if (this->indexIsValid(edgeIndex)) {
            Vertex<T>* targetEdge = this->edges[edgeIndex];
            for (int i = 0; i < this->edges.size(); i++)
                if (this->edges[i] == targetEdge)
                    this->edges.erase(this->edges.begin() + i);
        }
    }

    void removeEdge(Vertex<T>* targetEdge) {
        for (int i = 0; i < this->edges.size(); i++)
            if (this->edges[i] == targetEdge)
                this->edges.erase(this->edges.begin() + i);
    }
    
    void removeEdge(const T &targetEdge) {
        for (int i = 0; i < this->edges.size(); i++)
            if (*this->edges[i]->value == targetEdge)
                this->edges.erase(this->edges.begin() + i);
    }

private:
    bool indexIsValid(const int &edgeIndex) {
        return edgeIndex >= 0 && edgeIndex < this->edges.size();
    }
};

#endif
