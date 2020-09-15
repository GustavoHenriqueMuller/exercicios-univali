#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void DeleteBlankSpaces(string &line) {
    while(line.at(line.size()-1) == ' ')
        line.erase(line.size()-1);
    while(line.at(0) == ' ')
        line.erase(line.begin());
}

string GetTextFromFile(string fileName) {
    fstream file;
    file.open(fileName.c_str());

    string line;
    while(getline(file, line))
        if(line != "") {
            file.close();
            DeleteBlankSpaces(line);
            return line;
        }
    file.close();
    throw "Error on GetTextFromFile";
}

int GetAmountOfWords(string line) {
    int words = 0;
    for(unsigned int i = 0; i < line.size(); i++)
        if(line.at(i) == ' ')
            words++;
    words++;
    return words;
}

#endif // FILEMANAGER_H
