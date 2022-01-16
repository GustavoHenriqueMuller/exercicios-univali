#ifndef RDP_LOG_H
#define RDP_LOG_H

#include <iostream>

using namespace std;

void logAlice(string text) {
    cout << "ALICE\t" << text << endl;
}

void logBob(string text) {
    cout << "BOB\t" << text << endl;
}

void logSystem(string text) {
    cout << "SYSTEM\t" << text << endl;
}

void logMenu() {
    cout << "######################################" << endl;
    cout << "         INICIO DA SIMULACAO" << endl;
    cout << "######################################" << endl << endl;
}

#endif //RDP_LOG_H
