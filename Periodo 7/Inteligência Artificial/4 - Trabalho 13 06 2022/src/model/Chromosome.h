#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <algorithm>
#include <random>

using namespace std;

class Chromosome {

public:
    vector<int> genes;
    int fitness;

    Chromosome(vector<int> representation) {
        this->genes = representation;
        random_shuffle(this->genes.begin(), this->genes.end());
    }

    Chromosome(vector<int> representation, const vector<vector<int>> &edges) {
        this->genes = representation;
        random_shuffle(this->genes.begin(), this->genes.end());
        this->updateFitness(edges);
    }

    void updateFitness(const vector<vector<int>> &edges) {
        this->fitness = 0;
        int lastGene = this->genes[0];
        for (int i = 1; i < this->genes.size(); i++) {
            int actualGene = this->genes[i];
            this->fitness += edges[lastGene - 1][actualGene - 1];
            lastGene = actualGene;
        }
        this->fitness += edges[lastGene - 1][this->genes[0] - 1];
        this->fitness *= -1;
    }

};

#endif
