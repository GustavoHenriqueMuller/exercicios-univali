#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

using namespace std;

class Grafo {
    public:
        vector<vector<int>> matriz;
        vector<char> letrasVertices;

        int size() const {
            return matriz.size();
        }
};

#endif // GRAFO_H
