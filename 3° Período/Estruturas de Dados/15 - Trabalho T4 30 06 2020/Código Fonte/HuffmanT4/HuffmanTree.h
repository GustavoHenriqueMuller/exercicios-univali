#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <fstream>
#include <string>
#include "dChainedList.h"
#include "Utils.h"

using namespace std;

struct HuffmanTreeNode {
    char character = '_';
    int freq = 1;

    HuffmanTreeNode* left = nullptr;
    HuffmanTreeNode* right = nullptr;

    // Checa se o node é leaf.
    bool isLeaf(){
        return this->left == nullptr and this->right == nullptr;
    }
};

struct HuffmanTreeSymbol {
    char character = '_';
    int freq = 1;
    string binaryPath = "";
};

struct HuffmanTree {
    string pureText;
    HuffmanTreeNode* root = nullptr;

    private:
    dChainedList<HuffmanTreeNode> nodeList;
    dChainedList<HuffmanTreeSymbol> symbolList;

    // Insere ordenadamente na lista de nodes.
    void OrderedInsert(HuffmanTreeNode node) {
        // Desloca todos os valores para a direita quando chegar em um valor
        // que tem frequência maior que o valor desejado.
        for(int i = 0; i < nodeList.Length(); i++){
            if(nodeList.GetValue(i).freq >= node.freq) {
                nodeList.Insert(node, i);
                return;
            }
        }

        // Se é o maior elemento da lista, será adicionado no final.
        nodeList.Append(node);
    }

    // Adiciona um caractere à lista, aumentando a frequência caso já exista.
    void AddCharToList(char character) {
        HuffmanTreeNode* newNode = new HuffmanTreeNode;
        newNode->character = character;

        // Se a lista está vazia.
        if(nodeList.Empty()){
            nodeList.Append(*newNode);
        } else {
            // Se a lista já possui o caractere, adicionar 1 à frequencia.
            for(int i = 0; i < nodeList.Length(); i++){
                if(nodeList.GetValue(i).character == character){
                    nodeList.GetElement(i)->freq++;

                    HuffmanTreeNode nodeToChangePosition = nodeList.GetValue(i);
                    nodeList.Delete(i);

                    OrderedInsert(nodeToChangePosition);
                    return;
                }
            }

            // Se a lista não possui o caractere, adicionar ele ordenadamente.
            OrderedInsert(*newNode);
        }
    }   

    // Gera a tabela de símbolos, analizando o caminho até chegar em cada leaf.
    void GenerateSymbol(HuffmanTreeNode node, string binaryPath = "") {
        if(node.isLeaf()) {
            // Encontramos um nodo leaf; Adicionamos ele na tabela de símbolos.
            HuffmanTreeSymbol* newSymbol = new HuffmanTreeSymbol;
            newSymbol->character = node.character;
            newSymbol->freq = node.freq;

            newSymbol->binaryPath = binaryPath;
            symbolList.Append(*newSymbol);
            binaryPath = "";
            return;
        }

        // Percorremos o caminho da esquerda.
        if(node.left != nullptr){
            GenerateSymbol(*node.left, binaryPath + "0");
        }

        // Percorremos o caminho da direita.
        if(node.right != nullptr){
            GenerateSymbol(*node.right, binaryPath + "1");
        }
    }

    // Pega o binaryPath de um símbolo.
    string GetBinaryPathOfSymbol(char character) {
        string binaryPath = "";

        for(int i = 0; i < symbolList.Length(); i++) {
            HuffmanTreeSymbol currentSymbol = symbolList.GetValue(i);

            if(currentSymbol.character == character){
                binaryPath = currentSymbol.binaryPath;
                break;
            }
        }

        return binaryPath;
    }

    // Pega o texto legível binário através da tabela de símbolos e do texto.
    string GetHuffmanBinaryText() {
        string binaryText = "";

        for(unsigned int i = 0; i < pureText.length(); i++) {
            binaryText += GetBinaryPathOfSymbol(pureText.at(i));
        }

        return binaryText;
    }

    // Cria caminhos na árvore baseado em símbolos.
    void AddNodeBasedOnSymbol(HuffmanTreeNode* node, string binaryPath, char character) {
        // Cria uma raíz caso esteja vazia.
        if(node == nullptr and root == nullptr) {
            node = new HuffmanTreeNode;
            node->freq = 0;
            root = node;
        }

        // Se o caminho binário está vazio, então chegamos no lugar onde devemos inserir o símbolo.
        if(binaryPath == "") {
            node->character = character;
            return;
        }

        // Pega o caminho da esquerda.
        if(binaryPath[0] == '0'){
            binaryPath.erase(0, 1);

            // Checa se a esquerda existe. Se não existe, cria uma.
            if(node->left == nullptr) {
                node->left = new HuffmanTreeNode;
                node->left->freq = 0;
            }

            AddNodeBasedOnSymbol(node->left, binaryPath, character);
            return;
        }

        // Pega o caminho da direita.
        if(binaryPath[0] == '1'){
            binaryPath.erase(0, 1);

            // Checa se a direita existe. Se não existe, cria uma.
            if(node->right == nullptr) {
                node->right = new HuffmanTreeNode;
                node->right->freq = 0;
            }

            AddNodeBasedOnSymbol(node->right, binaryPath, character);
            return;
        }
    }

    // Gera a árvore a partir da tabela de símbolos. Isso é útil quando ocorre Decode.
    void GenerateTreeFromSymbolList() {
        for(int i = 0; i < symbolList.Length(); i++) {
            HuffmanTreeSymbol currentSymbol = symbolList.GetValue(i);
            AddNodeBasedOnSymbol(root, currentSymbol.binaryPath, currentSymbol.character);
        }
    }

    // Checa se existe um símbolo com um certo binaryPath. Se sim, devolve seu índice.
    int GetIndexOfSymbolByBinaryPath(string binaryPath) {
        for(int i = 0; i < symbolList.Length(); i++) {
            if(symbolList.GetValue(i).binaryPath == binaryPath) {
                return i;
            }
        }

        return -1;
    }

    // Adiciona um à frequência de um nodo de um certo caractere.
    void AddFrequencyToNode(HuffmanTreeNode* node, char nodeCharacter) {
        if(node == nullptr) {
            return;
        }

        if(node->character == nodeCharacter) {
            node->freq++;
            return;
        }

        if(node->left != nullptr) {
            AddFrequencyToNode(node->left, nodeCharacter);
        }

        if(node->right != nullptr) {
            AddFrequencyToNode(node->right, nodeCharacter);
        }
    }

    // Rebalanceia a frequência da árvore inteira.
    void RebalanceFrequency(HuffmanTreeNode* node) {
        if(node == nullptr) {
            return;
        }

        if(node->left != nullptr) {
            RebalanceFrequency(node->left);
        }

        if(node->right != nullptr) {
            RebalanceFrequency(node->right);
        }

        // Só rebalancea se o node não é uma leaf, pois se é uma leaf o seu valor já
        // foi setado pela função "AddFrequencyToNode()".
        if(!node->isLeaf()) {
            int freqRight = node->right == nullptr ? 0 : node->right->freq;
            int freqLeft = node->left == nullptr ? 0 : node->left->freq;
            node->freq = freqLeft + freqRight;
        }
    }

    // Decodifica uma string binária em texto legível.
    string DecodeHuffmanBinaryText(string binaryText) {
        string result = "";

        while(binaryText != "") {
            unsigned int cont = 0;

            // Vai aumentando os índices até achar um símbolo que possui o caminho.
            while(GetIndexOfSymbolByBinaryPath(binaryText.substr(0, cont)) == -1) {
                cont++;
            }

            // Achou um símbolo que tem o binaryPath; Vamos pegar ele, pegar seu caractere e adicionar
            // o caractere no texto.
            char charToAdd = symbolList.GetValue(GetIndexOfSymbolByBinaryPath(binaryText.substr(0, cont))).character;

            // Adiciona o caractere e deleta o caminho que já foi percorrido.
            result += charToAdd;
            binaryText.erase(0, cont);
        }

        return result;
    }

    // Deleta a árvore inteira.
    void Delete(HuffmanTreeNode* node) {
        if(node == nullptr) {
            return;
        }

        Delete(node->left);
        Delete(node->right);
        delete node;
    }

    // Reseta tudo da estrutura.
    void ResetAll() {
        Delete(root);
        root = nullptr;

        nodeList.Clear();
        symbolList.Clear();
    }

    public:
    // Recebe o texto legível binário de uma string.
    string Encode() {
        ResetAll();

        // Adiciona cada caractere do texto ao vetor.
        for(unsigned int i = 0; i < pureText.length(); i++){
            AddCharToList(pureText.at(i));
        }

        // Agora que temos a lista cheia, vamos criar uma Árvore de Huffman com base na lista:
        while(nodeList.Length() > 1) {
            // Agrupa os dois primeiros elementos e junta eles num só.
            HuffmanTreeNode* newNode = new HuffmanTreeNode;
            HuffmanTreeNode* newLeft = new HuffmanTreeNode;
            HuffmanTreeNode* newRight = new HuffmanTreeNode;

            // Cria duas cópias, uma do valor antigo da esquerda e outro da direita.
            HuffmanTreeNode* oldLeft = nodeList.GetElement(0);
            HuffmanTreeNode* oldRight = nodeList.GetElement(1);

            // Copia os valores para os novos ponteiros de esquerda e direita.
            newLeft->character = oldLeft->character;
            newLeft->freq = oldLeft->freq;
            newLeft->left = oldLeft->left;
            newLeft->right = oldLeft->right;

            newRight->character = oldRight->character;
            newRight->freq = oldRight->freq;
            newRight->left = oldRight->left;
            newRight->right = oldRight->right;

            // Inicializa o novo node agrupador.
            newNode->left = newLeft;
            newNode->right = newRight;
            newNode->freq = newLeft->freq + newRight->freq;

            // Deletamos os dois elementos que pegamos.
            nodeList.Delete(0);
            nodeList.Delete(0);

            // Reinserir a nova junção dos dois nodes na árvore:
            OrderedInsert(*newNode);
        }

        // Gera a raíz.
        root = nodeList.GetElement(0);

        // Gera a tabela de símbolos.
        GenerateSymbol(*root);

        // Pega o texto legível binário a partir dos símbolos.
        return GetHuffmanBinaryText();
    }

    // Recebe um arquivo com uma tabela de símbolos e remonta a árvore a partir dele.
    string Decode(string binaryText, string symbolTableFileName) {
        ResetAll();

        // Abre o arquivo.
        ifstream symbolTableFile;
        symbolTableFile.open(symbolTableFileName);

        // Pega os símbolos e adiciona eles na lista de símbolos.
        string line;
        while(getline(symbolTableFile, line)) {
            // Para cada linha, cria um símbolo correspondente e adiciona ele.
            HuffmanTreeSymbol* newSymbol = new HuffmanTreeSymbol;

            // Tira os espaços em branco da linha para facilitar o parsing. É feita uma checagem
            // para saber se o primeiro caractere é um espaço vazio para não deletá-lo na função.
            line[0] != ' ' ? line = CropWhiteSpaces(line) : line = " " + CropWhiteSpaces(line);

            // Pega o caractere.
            newSymbol->character = line[0];
            line.erase(0, line.find(":") + 1);

            // Pega o caminho binário.
            newSymbol->binaryPath = line.substr(0, line.find(":"));
            line.erase(0, line.find(":") + 1);

            // Adiciona nos símbolos.
            symbolList.Append(*newSymbol);
        }

        // Gera a árvore baseado na tabela de símbolos. Essa árvore não possui frequências definidas.
        GenerateTreeFromSymbolList();

        // Gera o texto puro baseado no binário recebido e da árvore recém criada.
        pureText = DecodeHuffmanBinaryText(binaryText);

        // Agora que temos o texto puro, podemos alterar as frequências da árvore com base nele.
        for(unsigned int i = 0; i < pureText.length(); i++) {
            AddFrequencyToNode(root, pureText.at(i));
        }

        // Rebalanceamos a frequência de cada nodo.
        RebalanceFrequency(root);

        // Retorna o texto decodificado.
        return pureText;
    }

    // Arquiva as informações de encode num arquivo .txt.
    void WriteEncodeInfoToFile(string fileName) {
        ofstream file;
        file.open(fileName);

        // Escreve o texto em si.
        file << "'" << pureText << "'" << endl << endl;

        // Escreve os símbolos.
        file << "Tabela de Simbolos" << endl << endl;

        for(int i = 0; i < symbolList.Length(); i++) {
            HuffmanTreeSymbol currentSymbol = symbolList.GetValue(i);
            file << currentSymbol.character << ": " << currentSymbol.binaryPath << " : " << currentSymbol.freq << endl;
        }

        // Escreve o binário de Huffman.
        string huffmanText = ParseBinaryString(GetHuffmanBinaryText());
        file << endl << "Binario gerado: " << huffmanText << endl;

        // Escreve o binário de Huffman codificado em ASCII (Bônus).
        string huffmanInAsciiText = BinaryStringToASCIIText(GetHuffmanBinaryText());
        file << endl << "Binario de Huffman em ASCII (Bonus): " << huffmanInAsciiText << endl;

        file.close();
    }

    // Arquiva as informações de decode num arquivo .txt.
    void WriteDecodeInfoToFile(string fileName) {
        ofstream resultFile;
        resultFile.open(fileName);

        // Escreve o texto original em ASCII.
        resultFile << "'" << pureText << "'" << endl << endl;

        // Escreve a relação de tamanho.
        string huffmanText = ParseBinaryString(GetHuffmanBinaryText());
        string asciiText = ParseBinaryString(StringToASCIIBinaryText(pureText));

        resultFile << "Relacao de tamanho (Huffman/ASCII): " << ((float)huffmanText.length()/(float)asciiText.length()) * 100 << "%" << endl;

        resultFile.close();
    }

    // Escreve a interface de codificação.
    void PrintEncodeInfo() {
        // Mostra as informações da codificação.
        PrintDivisor();
        cout << endl << "TABELA DE SIMBOLOS" << endl << endl;
        PrintSymbolList();

        PrintDivisor();
        cout << endl << "ARVORE CRIADA POR CODIFICACAO" << endl << endl;
        PrintHuffmanTreeNode(root);

        PrintDivisor();
        cout << endl << "BINARIO GERADO POR CODIFICACAO" << endl << endl;
        cout << ParseBinaryString(GetHuffmanBinaryText()) << endl;

        PrintDivisor();
        string huffmanText = ParseBinaryString(GetHuffmanBinaryText());
        string asciiText = ParseBinaryString(StringToASCIIBinaryText(pureText));
        cout << endl << "Relacao de tamanho (ASCII/Huffman): " << ((float)asciiText.length()/(float)huffmanText.length()) * 100 << "%" << endl;
        PrintDivisor();
    }

    // Escreve a interface de decodificação.
    void PrintDecodeInfo() {
        // Mostra as informações da decodificação.
        PrintDivisor();
        cout << endl << "TEXTO GERADO" << endl << endl << pureText << endl;

        PrintDivisor();
        cout << endl << "ARVORE CRIADA POR DECODIFICACAO" << endl << endl;
        PrintHuffmanTreeNode(root);        

        PrintDivisor();
        string huffmanText = ParseBinaryString(GetHuffmanBinaryText());
        string asciiText = ParseBinaryString(StringToASCIIBinaryText(pureText));
        cout << endl << "Relacao de tamanho (Huffman/ASCII): " << ((float)huffmanText.length()/(float)asciiText.length()) * 100 << "%" << endl;
        PrintDivisor();
    }

    // Imprime a lista.
    void PrintNodeList(){
        for(int i = 0; i < nodeList.Length(); i++){
            cout << "CHAR: " << nodeList.GetValue(i).character << " | FREQ: " << nodeList.GetValue(i).freq << endl;
        }
    }

    // Imprime a lista de símbolos.
    void PrintSymbolList(){
        for(int i = 0; i < symbolList.Length(); i++){
            HuffmanTreeSymbol currentSymbol = symbolList.GetValue(i);
            cout << "CHAR: " << currentSymbol.character << " | BINARY PATH: " << currentSymbol.binaryPath << " | FREQ: " << currentSymbol.freq << endl;
        }
    }

    // Imprime a Árvore de Huffman por visitação pré-fixa.
    void PrintHuffmanTreeNode(HuffmanTreeNode* node){
        if(node == nullptr) {
            return;
        }

        cout << "CHAR: " << node->character << " | FREQ: " << node->freq << endl;

        if(node->left != nullptr) {
            PrintHuffmanTreeNode(node->left);
        }

        if(node->right != nullptr) {
            PrintHuffmanTreeNode(node->right);
        }
    }
};

#endif // HUFFMANTREE_H
