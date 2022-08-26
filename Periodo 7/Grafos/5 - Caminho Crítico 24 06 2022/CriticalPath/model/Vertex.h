#ifndef VERTEX_H
#define VERTEX_H

#include "Util.h"

using namespace std;

template<class T>
class Vertex {

public:
    T* value;
    int weight;
    int earlyStart;
    int earlyFinish;
    int lateStart;
    int lateFinish;
    int slackTime;
    vector<Vertex<T>*> edges;

    Vertex() {
        this->value = nullptr;
        this->weight = -1;
        this->earlyStart = -1;
        this->earlyFinish = -1;
        this->lateStart = -1;
        this->lateFinish = -1;
        this->slackTime = -1;
    }

    Vertex(T* value) {
        this->value = value;
        this->weight = -1;
        this->earlyStart = -1;
        this->earlyFinish = -1;
        this->lateStart = -1;
        this->lateFinish = -1;
        this->slackTime = -1;
    }
    
    Vertex(const T &value) {
        this->value = new T(value);
        this->weight = -1;
        this->earlyStart = -1;
        this->earlyFinish = -1;
        this->lateStart = -1;
        this->lateFinish = -1;
        this->slackTime = -1;
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
