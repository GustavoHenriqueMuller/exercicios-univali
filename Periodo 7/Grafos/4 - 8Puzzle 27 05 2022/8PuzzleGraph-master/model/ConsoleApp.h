#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <time.h>
#include "EightPuzzle.h"

using namespace std;

enum InsertionMode {
    USER = 1,
    RANDOM = 2,
};

class ConsoleApp {

private:
    EightPuzzle* puzzle;

public:
    ConsoleApp() { }

    void init() {
        srand(time(nullptr));
        string puzzleInput;
        if (this->choosePuzzleInsertionMode() == USER) {
            puzzleInput = this->getPuzzleInput();
        } else {
            puzzleInput = this->getRandomPuzzle();
        }

        this->puzzle = new EightPuzzle(puzzleInput);

        string message = "A solution has been found for ";
        try {
            this->puzzle->solve();
        } catch(const char* error) {
            message = error;
        }

        this->printSolution();
        cout << endl << endl << message << puzzleInput << "." << endl;
        cout << "Total states: " << this->puzzle->closedStates.size() << endl;
        cout << "Best state founded:" << endl;
        this->printState(this->puzzle->bestStateEver);
        this->pause();
    }

private:
    void printSolution() {
        this->cleanScreen();
        this->printHeader();

        for (int i = 0; i < this->puzzle->closedStates.size(); i++)
            this->printState(this->puzzle->closedStates[i]);
    }

    void printState(State state) {
        for (int i = 0; i < 3; i++) {
            for (int j = i * 3; j < i * 3 + 3; j++)
                cout << state.board.at(j) << "\t";
            cout << endl;
        }
        cout << "F: " << state.f << "\t";
        cout << "G: " << state.g << "\t";
        cout << "H: " << state.h << endl << endl;
        cout << "--------------------------------" << endl << endl;
    }

    int choosePuzzleInsertionMode() {
        this->cleanScreen();
        this->printHeader();
        cout << "[1] Insert a puzzle by my self" << endl;
        cout << "[2] Generate a random puzzle" << endl << endl;
        return getIntInput();
    }

    string getPuzzleInput() {
        this->cleanScreen();
        this->printHeader();

        cout << "(1)\t(2)\t(3)" << endl;
        cout << "(4)\t(5)\t(6)" << endl;
        cout << "(7)\t(8)\t(0)" << endl << endl;

        cout << "Enter the puzzle to solve:" << endl;
        cout << "(Example above is 123456780, where 0 is the blank space)" << endl << endl;
        return this->getStringInput();
    }

    string getRandomPuzzle() {
        string random = "123456780";
        random_shuffle(random.begin(), random.end());
        return random;
    }

    void printHeader() {
        cout << "############################################" << endl;
        cout << "            EIGHT PUZZLE SOLVER" << endl;
        cout << "############################################" << endl << endl;
    }

    string getStringInput() {
        string data;
        cout << "--> ";
        cin.ignore();
        getline(std::cin, data);
        return data;
    }    

    int getIntInput() {
        int data;
        cout << "--> ";
        cin >> data;
        return data;
    }    

    void cleanScreen() {
        system("cls");
    }

    void pause() {
        system("pause");
    }

    void printGraph(GraphMatrix<int>* graph) {
        if (graph->getSize() > 0) {
            cout << "\t";
            for(int i = 0; i < graph->edges.size(); i++)
                cout << "(" << *graph->vertexes[i]->value << ")\t";
            cout << endl;

            for(int i = 0; i < graph->edges.size(); i++) {
                cout << "(" << *graph->vertexes[i]->value << ")\t";
                for(int j = 0; j < graph->edges[i].size(); j++)
                    cout << graph->edges[i][j] << "\t";
                cout << endl;
            }
            cout << endl << endl;
        }
    }
};

#endif
