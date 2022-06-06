#ifndef EIGHT_PUZZLE_H
#define EIGHT_PUZZLE_H

#include <string>
#include <iostream>
#include "GraphMatrix.h"
#include "State.h"

using namespace std;

class EightPuzzle {

public:
    GraphMatrix<int>* graph;
    vector<State> closedStates;
    State bestStateEver;
    string solution;

public:
    EightPuzzle(string puzzle) {
        this->solution = "123804765";
        this->buildGraph(puzzle);

        string board = this->getBoard();

        int wrongPositions = getAmountOfWrongPositions(board);
        this->bestStateEver = {board, wrongPositions, 0, wrongPositions};
        this->closedStates.push_back(this->bestStateEver);
    }

    void solve() {
        int h = this->closedStates[0].h;

        for (int g = 1; h > 0; g++) {
            vector<State> states = this->getAvailableStates();

            if (states.size() == 0) 
                throw "All states checked. Could not find a solution for ";

            State bestState = this->getBestState(states);
            h = bestState.h;
            bestState.g = g;
            bestState.f = g + h;

            if (h < this->bestStateEver.h) {
                this->bestStateEver = bestState;
            }

            this->closedStates.push_back(bestState);
            this->updateGraph(bestState.board);
        }
    }

private:
    State getBestState(vector<State> states) {
        State bestState = states[0];
        int bestH = this->getAmountOfWrongPositions(bestState.board);

        for (int i = 1; i < states.size(); i++) {
            int h = this->getAmountOfWrongPositions(states[i].board);

            if (h < bestH) {
                bestH = h;
                bestState = states[i];
            }
        }

        bestState.h = bestH;
        return bestState;
    }

    vector<State> getAvailableStates() {
        vector<State> availableStates;

        int emptyVertexIndex = this->getEmptyPosition();
        Vertex<int>* emptyVertex = this->graph->vertexes[emptyVertexIndex];
        vector<Vertex<int>*> edges = this->graph->getEdgesOf(emptyVertex);

        for (int i = 0; i < edges.size(); i++) {
            int position = this->graph->getPositionOf(*edges[i]->value);
            State state(this->getBoard());

            swap(state.board[position], state.board[emptyVertexIndex]);

            if (this->isNotClosedState(state.board)) {
                availableStates.push_back(state);
            }
        }

        return availableStates;
    }

    bool isNotClosedState(string board) {
        return find_if(this->closedStates.begin(), this->closedStates.end(), [&] (State const& s) { return s.board == board; }) == this->closedStates.end();
    }

    string getBoard() {
        string board = "";
        for (int i = 0; i < this->graph->vertexes.size(); i++)
            board.append(to_string(*this->graph->vertexes[i]->value));
        return board;
    }

    int getAmountOfWrongPositions(string board) {
        int quantidade = 0;
        for (int i = 0; i < this->solution.size(); i++)
            if (this->solution[i] != '0' && board[i] != this->solution[i])
                quantidade++;
        return quantidade;
    }

    int getEmptyPosition() {
        auto itr = find_if(this->graph->vertexes.begin(), this->graph->vertexes.end(), [&] (Vertex<int>* v) { return *v->value == 0; });
        return distance(this->graph->vertexes.begin(), itr);
    }

    void updateGraph(string board) {
        for (int i = 0; i < this->graph->vertexes.size(); i++)
           *this->graph->vertexes[i]->value = board.at(i) - '0';
    }

    void buildGraph(string board) {
        this->graph = new GraphMatrix<int>();
        for (int i = 0; i < board.size(); i++)
            this->graph->addVertex(board.at(i) - '0');

        for (int line = 0; line < 3; line++)
            for (int i = 3 * line; i < 3 * line + 2; i++)
                this->graph->addEdgeBetween(board.at(i) - '0', board.at(i + 1) - '0');

        for (int column = 0; column < 3; column++)
            for (int i = column; i <= column + 3; i += 3)
                this->graph->addEdgeBetween(board.at(i) - '0', board.at(i + 3) - '0');

        return;
    }
};

#endif
