#include <iostream>
#include <locale.h>
#include "dChainedList.h"
#include "HuffmanTree.h"
#include "Utils.h"

using namespace std;

int main() {
    HuffmanTree myTree;
    myTree.pureText = "estrutura de dados";

    // Codifica o texto 'estrutura de dados'.
    myTree.Encode();

    // Imprime as informações de codificação.
    myTree.PrintEncodeInfo();

    // Escreve todos as informações pedidas de codificação num .txt.
    myTree.WriteEncodeInfoToFile("coded.txt");

    // Decodifica o primeiro parâmetro com a tabela de símbolos do segundo parâmetro.
    myTree.Decode(CropWhiteSpaces("01011010 01011000 00100001 11001011 11010101 11110011 11100110 1"), "symbolTableEntry.txt");

    // Imprime as informações de decodificação.
    myTree.PrintDecodeInfo();

    // Escreve todos as informações pedidas de decodificação num .txt.
    myTree.WriteDecodeInfoToFile("decoded.txt");

    cout << endl;
    return 0;
}
