#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "crc.h"

using namespace std;

void randomizeSeed() {
    srand(time(NULL));
}

void consoleClear() {
    system("cls");
}

void delay(int seconds) {
    clock_t start = clock() + (1000 * seconds);
    while(clock() < start);
}

int main() {
    randomizeSeed();
    consoleClear();

    string message = "Hello";

    cout << "Alice wants to send \"" << message << "\" to Bob..." << endl << endl << endl;

    for (int i = 0; i < message.size(); i++) {
        string remainder;

        do {
            char target = message.at(i);

            // ALICE SIDE
            string message = crc(target);

            cout << "ALICE SIDE" << endl;
            cout << "Target:\t\"" << target << "\"  -  " << binaryOf(target) << endl;
            cout << "CRC sufix:\t" << findSufixForMessage(target) << endl;
            cout << "Final message:\t" << message << endl << endl;

            // BOB SIDE
            string messageWithError = addErrorToMessage(message);
            remainder = findRemainderForMessage(messageWithError);

            cout << "BOB SIDE" << endl;
            cout << "Received:\t" << messageWithError << endl;
            cout << "Remainder:\t" << remainder << endl << endl;

            if (isRemainderValid(remainder)) {
                cout << "Success!" << endl;
            } else {
                cout << "Invalid remainder! Resending message..." << endl;
            }
            cout << endl << "___________________________" << endl << endl << endl;

            delay(1);
        } while (!isRemainderValid(remainder));
    }

    return 0;
}
