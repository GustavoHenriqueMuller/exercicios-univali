#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> getFileContent(string filepath) {
    ifstream file;
    string line;
    vector<string> content;

    file.open(filepath.c_str());

    while(getline(file, line))
        if (line != "") content.push_back(line);

    file.close();
    return content;
}

vector<vector<int>> extractData(vector<string> lines) {
    vector<vector<int>> data;

    for (string line : lines) {
        vector<int> problem;
        
        while (line.size() != 0) {
            size_t position = line.find(';');
            if (position == string::npos) position = line.size();

            string token = line.substr(0, position);
            problem.push_back(stoi(token));
            line.erase(0, position + 1);
        }

        data.push_back(problem);
    }

    return data;
}

#endif
