#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

// Pega uma string binária e insere um espaço à cada 8 espaços.
string ParseBinaryString(string binaryText) {
    for(int i = binaryText.length() - 1; i >= 0; i--){
        if(i % 8 == 0 and i != 0){
            binaryText.insert(i, " ");
        }
    }

    return binaryText;
}

// Pega uma string que representa um binário e codifica ela em ASCII.
string BinaryStringToASCIIText(string binaryText) {
    string resultText = "";

    // Transforma o número em um múltiplo de 8 caso não seja.
    if(binaryText.length() % 8 != 0 and binaryText.length() > 0) {
        while(binaryText.length() % 8 != 0) {
            binaryText += "0";
        }
    }

    // Faz a codificação ASCII de cada caractere e adiciona na string resultado.
    int numBytes = binaryText.length()/8;

    for(unsigned int i = 0; i < numBytes; i++) {
        string byte = binaryText.substr(i * 8, (i * 8) + 8);

        // Converte a string para um binário e o binário para um decimal.
        bitset<8> toBinary = bitset<8>(byte.c_str());
        int decimalEquivalent = toBinary.to_ulong();
        char charToAdd = decimalEquivalent;

        // Finalmente, adiciona o caractere ASCII correspondente ao decimal.
        resultText += charToAdd;
    }

    return resultText;
}

// Pega um texto e retorna uma string que contem o texto dela codificado em ASCII.
string StringToASCIIBinaryText(string text) {
    string asciiEncoded = "";

    for(unsigned int i = 0; i < text.length(); i++) {
        // Converte o texto em um decimal ASCII, e depois converte esse decimal em binário.
        int asciiCode = int(text.at(i));
        string binaryCode = bitset<8>(asciiCode).to_string();

        asciiEncoded += binaryCode;
    }

    return asciiEncoded;
}

// Apaga os espaços em branco de uma string.
string CropWhiteSpaces(string text) {
    string resultText = "";

    for(unsigned int i = 0; i < text.length(); i++) {
        if(text.at(i) != ' '){
            resultText += text.at(i);
        }
    }

    return resultText;
}

// Imprime um divisor.
void PrintDivisor() {
    for(int i = 0; i < 50; i++) {
        cout << "_";
    }

    cout << endl;
}

#endif // UTILS_H
