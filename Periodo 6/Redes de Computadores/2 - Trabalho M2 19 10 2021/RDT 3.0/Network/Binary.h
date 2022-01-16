#ifndef RDT_BINARY_H
#define RDT_BINARY_H

string decimalToBinary(int n) {
    string number = "";
    int i = 0;
    while (n > 0) {
        number.insert(0, to_string(n % 2));
        n = n / 2;
        i++;
    }
    while(number.size() < 8)
        number.insert(0, "0");
    return number;
}

int binaryToDecimal(string bin) {
    int decimal = 0;
    int base = 1;
    for(int i = 1; i <= 8; i++) {
        if(bin.at(8-i) == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}

string charToBinary(char c) {
    return decimalToBinary(int(c));
}

char binaryToChar(string binary) {
    return char(binaryToDecimal(binary));
}

string binaryAddition(string a, string b) {
    string result;
    int carryOut = 0;
    for(int i = 7; i >= 0; i--) {
        int temp = (a.at(i) - '0') + (b.at(i) - '0') + carryOut;
        if (temp > 1) {
            temp = (temp == 2) ? 0 : 1;
            carryOut = 1;
        } else {
            carryOut = 0;
        }
        result = to_string(temp) + result;
    }

    if (carryOut == 1) {
        return binaryAddition(result, "00000001");
    }

    return result;
}

string complement(string binary) {
    string result;
    for (char i : binary)
        result.append((i == '1') ? "0" : "1");
    return result;
}

#endif //RDT_BINARY_H
