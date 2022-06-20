#ifndef GENETIC_TSP_H
#define GENETIC_TSP_H

#include <algorithm>
#include <random>
#include <iostream>
#include "GraphMatrix.h"
#include "Chromosome.h"

using namespace std;

/**
 * Representação (cromossomo): [1], 2, 3, 4, 5, [1]
 * Função de aptidão: comprimento do caminho
 * Quantidade inicial de população: usuário (default: número de cidades)
 * 
 * Seleção: Tournament
 * Cruzamento: Pair Swap and Random (95%)
 * Mutação: Pair Swap and Random (5%)
 * 
 * Condição de parada: usuário número máximo de iterações
 */
class GeneticTSP {

public:
    GraphMatrix<int>* graph;
    vector<Chromosome> population;
    vector<int> defaultRepresentation;
    const int INDIVIDUALS_PER_BATTLE = 3;
    float percentageOfCrossover = 95.0;
    float percentageOfMutation = 10.0;

    GeneticTSP(GraphMatrix<int>* graph, int initialPopulationSize) {
        this->graph = graph;
        this->generateDefaultRepresentation();
        this->generateInitialPopulation(initialPopulationSize);
    }

    void generateNewPopulation() {
        // cout << "POPULATION:" << endl;
        // for (int i = 0; i < this->population.size(); i++) {
        //     cout << i << " - ";
        //     Util::printVector(this->population[i].genes);
        //     cout << " - FITNESS: " << this->population[i].fitness << endl;
        // }

        vector<Chromosome> winners = this->tournament();

        // cout << "WINNERS:" << endl;
        // for (int i = 0; i < winners.size(); i++) {
        //     cout << i << " - ";
        //     Util::printVector(winners[i].genes);
        //     cout << " - FITNESS: " << winners[i].fitness << endl;
        // }

        this->crossover(winners);

        // cout << "CROSSOVER:" << endl;
        // for (int i = 0; i < this->population.size(); i++) {
        //     cout << i << " - ";
        //     Util::printVector(this->population[i].genes);
        //     cout << " - FITNESS: " << this->population[i].fitness << endl;
        // }

        this->mutation();

        // cout << "MUTATION:" << endl;
        // for (int i = 0; i < this->population.size(); i++) {
        //     cout << i << " - ";
        //     Util::printVector(this->population[i].genes);
        //     cout << " - FITNESS: " << this->population[i].fitness << endl;
        // }
    }

    Chromosome getBestIndividual() {
        Chromosome target = *max_element(
            this->population.begin(), 
            this->population.end(),
            [&] (Chromosome a, Chromosome b) { return a.fitness < b.fitness; }
        );

        target.genes.push_back(target.genes[0]);
        return target;
    }

private:
    vector<Chromosome> tournament() {
        vector<Chromosome> winners;
        for (int i = 0; i < this->population.size(); i++) {
            vector<Chromosome> tempPopulation = this->population;
            random_shuffle(tempPopulation.begin(), tempPopulation.end());

            Chromosome winner = *max_element(
                tempPopulation.begin(), 
                tempPopulation.begin() + this->INDIVIDUALS_PER_BATTLE,
                [&] (Chromosome a, Chromosome b) { return a.fitness < b.fitness; }
            );

            winners.push_back(winner);
        }
        return winners;
    }

    void crossover(vector<Chromosome> chromosomes) {
        this->population.clear();

        for (int i = 0; i < chromosomes.size() - 1; i += 2) {
            if (Util::randomPercentage() <= this->percentageOfCrossover) {
                this->pairSwaps(chromosomes[i], chromosomes[i + 1]);
                chromosomes[i].updateFitness(this->graph->edges);
                chromosomes[i + 1].updateFitness(this->graph->edges);
            }
        }

        this->population = chromosomes;
    }

    void mutation() {
        for (int i = 0; i < this->population.size(); i++) {
            if (Util::randomPercentage() <= this->percentageOfMutation) {
                int targetIndexB, targetIndexA = rand() % this->population[i].genes.size();
                do {
                    targetIndexB = rand() % this->population[i].genes.size();
                } while (targetIndexA == targetIndexB);

                swap(this->population[i].genes[targetIndexA], this->population[i].genes[targetIndexB]);
                this->population[i].updateFitness(this->graph->edges);
            }
        }
    }

    void pairSwaps(Chromosome &a, Chromosome &b) {
        vector<int> usedGenes;
        for (int i = 0; i < a.genes.size() / 4; i++) {
            int targetIndexA = rand() % a.genes.size();
            int geneA = a.genes[targetIndexA];

            while (Util::contains(usedGenes, geneA)) {
                targetIndexA = rand() % a.genes.size();
                geneA = a.genes[targetIndexA];
            }

            int targetIndexB = Util::getPosition(b.genes, geneA);
            int geneB = b.genes[targetIndexB];

            swap(a.genes[targetIndexA], a.genes[targetIndexB]);
            swap(b.genes[targetIndexA], b.genes[targetIndexB]);

            usedGenes.push_back(geneA);
            usedGenes.push_back(geneB);
        }
    }

    void generateInitialPopulation(int size) {
        for (int i = 0; i < size; i++) {
            Chromosome newChromosome(defaultRepresentation, this->graph->edges);
            this->population.push_back(newChromosome);
        }
    }

    void generateDefaultRepresentation() {
        for (Vertex<int>* vertex : this->graph->vertexes)
            defaultRepresentation.push_back(*vertex->value);
    }
};

#endif
