#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

using namespace std;

void printHeader() {
    cout << "#####################################" << endl;
    cout << "   POPULARIDADE DE JOGOS COM FUZZY   " << endl;
    cout << "#####################################" << endl << endl;
}

double getDoubleInput() {
    double input = 0.0;
    cout << "--> ";
    cin >> input;
    return input;
}

void cleanScreen() {
    system("cls");
}

void pause() {
    system("pause");
}

#endif