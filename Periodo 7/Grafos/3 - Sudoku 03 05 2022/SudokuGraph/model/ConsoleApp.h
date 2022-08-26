#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

#include <iostream>
#include "Sudoku.h"

using namespace std;

class ConsoleApp {

private:
    Sudoku* sudoku;
    int size;
    int start;

public:
    ConsoleApp() { }

    void init() {
        this->chooseSize();
        this->chooseStart();

        cout << this->size << "   " << this->start << endl << endl;
        this->sudoku = new Sudoku(this->size, this->start);

        this->cleanScreen();
        this->printHeader();
        this->sudoku->printColorGraph();
    }

private:
    void chooseSize() {
        int size;
        do {
            this->cleanScreen();
            this->printHeader();
            cout << "Enter the number of regions of your Sudoku" << endl;
            cout << "(Must have an exact square root and be greater than or equal to 4)" << endl << endl;
            size = this->getIntInput();
        } while (size < 4 || sqrt(size) * sqrt(size) != size);

        this->size = size;
    }

    void chooseStart() {
        int start;
        do {
            this->cleanScreen();
            this->printHeader();
            cout << "Select a starting point" << endl;
            this->printStartPositionOptions();
            start = this->getIntInput();
        } while (start < 1 || start > this->size * this->size);

        this->start = start;
    }

    void printHeader() {
        cout << "############################################" << endl;
        cout << "               SUDOKU SOLVER" << endl;
        cout << "############################################" << endl << endl;
    }

    void printStartPositionOptions() {
        for (int i = 0; i < this->size; i++) {
            for (int j = i * this->size; j < this->size * (i + 1); j++)
               cout << j + 1 << "\t";
            cout << endl;
        }
        cout << endl << endl;;
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
};

#endif
