#ifndef CRITICAL_PATH_H
#define CRITICAL_PATH_H

#include <stack>
#include <sstream>
#include "GraphMatrix.h"

using namespace std;

class CriticalPath {

protected:
    GraphMatrix<char>* graph;
    stack<Vertex<char>*> unvisitedVertexes;
    bool startOnZero;

public:
    CriticalPath(GraphMatrix<char>* graph, bool startOnZero) {
        this->graph = graph;
        this->startOnZero = startOnZero;
        this->findCriticalPath();
    }

    string getCriticalPath() {
        stringstream stream;
        Vertex<char>* targetVertex = this->graph->vertexes[0];

        while (true) {
            stream << *targetVertex->value << " -> ";
            vector<Vertex<char>*> edges = this->graph->getEdgesOf(targetVertex);
            int position = Util::getPositionIf(edges, 
                [&] (Vertex<char>* edge) { return edge->slackTime == 0; }
            );

            if (position == -1) break;

            targetVertex = edges[position];
        }

        stream << "END";
        return stream.str();
    }

private:
    void findCriticalPath() {
        this->pushEdgesToStack(this->graph->vertexes[0]);
        this->findEarlyValues();
        this->setFirstLateValues();
        this->findLateValues();
    }

    void findEarlyValues() {
        while (this->unvisitedVertexes.size() > 0) {
            Vertex<char>* actualVertex = Util::popFrom(this->unvisitedVertexes);
            vector<Vertex<char>*> vertexesConnectedWithActual = this->graph->getVertexesConnectedWith(actualVertex);
            Vertex<char>* parentVertex = Util::getMaxOf(vertexesConnectedWithActual, 
                [&] (Vertex<char>* a, Vertex<char>* b) { return a->earlyFinish < b->earlyFinish; }
            );

            int cost = (parentVertex->earlyFinish == -1) ? 0 : parentVertex->earlyFinish;
            actualVertex->earlyStart = cost + this->getSelector();
            actualVertex->earlyFinish = cost + actualVertex->weight;

            this->pushEdgesToStack(actualVertex);
        }
    }

    void findLateValues() {
        while (this->unvisitedVertexes.size() > 0) {
            Vertex<char>* actualVertex = Util::popFrom(this->unvisitedVertexes);
            vector<Vertex<char>*> vertexEdges = this->graph->getEdgesOf(actualVertex);
            Vertex<char>* childVertex = Util::getMinOf(vertexEdges, 
                [&] (Vertex<char>* a, Vertex<char>* b) { return a->lateStart < b->lateStart; }
            );

            int cost = childVertex->lateStart;
            actualVertex->lateFinish = cost - this->getSelector();
            actualVertex->lateStart = cost - actualVertex->weight;
            actualVertex->slackTime = actualVertex->lateFinish - actualVertex->earlyFinish;

            this->pushConnectedVertexesToStack(actualVertex);
        }
    }

    void setFirstLateValues() {
        vector<Vertex<char>*> leaves = this->getLeafVertexes();
        Vertex<char>* vertexWitMaxEarlyFinish = Util::getMaxOf(leaves, 
            [&] (Vertex<char>* a, Vertex<char>* b) { return a->earlyFinish < b->earlyFinish; }
        );

        for (Vertex<char>* leaf : leaves) {
            leaf->lateFinish = vertexWitMaxEarlyFinish->earlyFinish;
            leaf->lateStart = leaf->lateFinish - leaf->weight  + this->getSelector();
            leaf->slackTime = leaf->lateFinish - leaf->earlyFinish;
            this->pushConnectedVertexesToStack(leaf);
        }
    }

    int getSelector() {
        return (this->startOnZero ? 0 : 1);
    }

    vector<Vertex<char>*> getLeafVertexes() {
        vector<Vertex<char>*> leaves;
        for (Vertex<char>* vertex : this->graph->vertexes)
            if (this->graph->getEdgesOf(vertex).size() == 0)
                leaves.push_back(vertex);
        return leaves;
    }

    void pushEdgesToStack(Vertex<char>* targetVertex) {
        vector<Vertex<char>*> edges = this->graph->getEdgesOf(targetVertex);
        for (Vertex<char>* edge : edges)
            this->unvisitedVertexes.push(edge);
    }

    void pushConnectedVertexesToStack(Vertex<char>* targetVertex) {
        vector<Vertex<char>*> edges = this->graph->getVertexesConnectedWith(targetVertex);
        for (Vertex<char>* edge : edges)
            this->unvisitedVertexes.push(edge);
    }

};

#endif