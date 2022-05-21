#ifndef CRC_H
#define CRC_H

#include <stdlib.h>
#include <bitset>
#include <string>

using namespace std;

// Polynomial = x³ + x + 1
const int POLYNOMIAL_DEGREE = 3;
const string POLYNOMIAL = "1011";
const int MESSAGE_SIZE = 8;
const int FINAL_MESSAGE_SIZE = MESSAGE_SIZE + POLYNOMIAL_DEGREE;

string binaryOf(char letter) {
    return bitset<MESSAGE_SIZE>(letter).to_string();
}

string xorBetween(string a, string b) {
    string result = "";
    for (int i = 0; i < min(a.size(), b.size()); i++)
        result.append(to_string(a.at(i) ^ b.at(i)));
    return result;
}

string fitWithZeros(string message) {
    for (int i = 0; i < POLYNOMIAL_DEGREE; i++)
        message.append("0");
    return message;
}

string findRemainderForMessage(string message) {
    size_t startPosition = message.find('1');
    if (startPosition != string::npos) {
        string usefulPart = message.substr(startPosition, message.size() - startPosition);
        string polynomial = POLYNOMIAL;

        bool addedExtraBits = false;
        for (int i = polynomial.size(); i < usefulPart.size(); i++) {
            polynomial.append("0");
            addedExtraBits = true;
        }

        if (usefulPart.size() < POLYNOMIAL.size()) {
            while (usefulPart.size() < POLYNOMIAL.size())
                usefulPart.insert(0, "0");
            return usefulPart;
        }

        string xorResult = xorBetween(usefulPart, polynomial);
        return (addedExtraBits) ? findRemainderForMessage(xorResult) : xorResult;
    }

    message = "";
    return fitWithZeros(message);
}

string findSufixForMessage(string message) {
    string remainder = findRemainderForMessage(message);
    return remainder.substr(remainder.size() - POLYNOMIAL_DEGREE, POLYNOMIAL_DEGREE);
}

string findSufixForMessage(char message) {
    return findSufixForMessage(fitWithZeros(binaryOf(message)));
}

string crc(string message) {
    return message + findSufixForMessage(fitWithZeros(message));
}

string crc(char message) {
    return crc(binaryOf(message));
}

string addErrorToMessage(string message) {
    bool addError = rand() % 2;

    if (addError) {
        int randomIndex = rand() % message.size();
        message[randomIndex] = message[randomIndex] == '0' ? '1' : '0';
    }

    return message;
}

bool isRemainderValid(string remainder) {
    for (int i = 0; i < remainder.size(); i++)
        if (remainder.at(i) != '0')
            return false;
    return true;
}

#endif
