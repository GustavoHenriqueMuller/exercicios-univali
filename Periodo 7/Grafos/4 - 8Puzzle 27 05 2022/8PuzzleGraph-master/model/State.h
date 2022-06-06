#ifndef STATE_H
#define STATE_H

#include <string>

using namespace std;

class State {

public:
    string board;
    int f, g, h;

    State(string board, int f, int g, int h) {
        this->board = board;
        this->f = f;
        this->g = g;
        this->h = h;
    }

    State(string board) {
        this->board = board;
    }

    State() { }
};

#endif
