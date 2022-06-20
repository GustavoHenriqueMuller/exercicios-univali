#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

#include <iostream>
#include "GeneticTSP.h"
#include "GraphBuilder.h"

using namespace std;

class ConsoleApp {

private:
    GraphBuilder* graphs;

public:
    ConsoleApp() {
        this->graphs = new GraphBuilder();
    }

    void init() {
        while (true) {
            this->printMenu();
            int problem = this->getIntInput() - 1;

            while (problem < 0 || problem > this->graphs->getGraphs().size() - 1) {
                this->printMenu();
                problem = this->getIntInput() - 1;
            }
            
            this->printMenu(false);
            this->printGraph(this->graphs->getGraph(problem));
            
            cout << "Enter the size of the initial population" << endl;
            int population = this->getIntInput();
            
            cout << endl << "Enter the maximum number of iterations" << endl;
            int iterations = this->getIntInput();

            this->solveProblem(problem, population, iterations);
            this->pause();
        }
    }

private:
    void solveProblem(int problem, int populationSize, int iterations) {
        GeneticTSP* genetic = new GeneticTSP(this->graphs->getGraph(problem), populationSize);

        cout << endl << "Enter the crossover rate (0 - 100)" << endl;
        genetic->percentageOfCrossover = this->getFloatInput();

        cout << endl << "Enter the mutation rate (0 - 100)" << endl;
        genetic->percentageOfMutation = this->getFloatInput();

        for (int i = 0; i < iterations; i++) {

            genetic->generateNewPopulation();
            
            if (i == iterations - 1) {
                Chromosome bestIndividual = genetic->getBestIndividual();
                cout << endl << "BEST INDIVIDUAL FOUND: ";
                Util::printVector(bestIndividual.genes);
                cout << endl << "Fitness: " << bestIndividual.fitness << endl;

                cout << endl << "Continue for " << iterations << " more iterations?\t";
                cout << "[1] Yes\t[2] No" << endl;
                if (this->getIntInput() == 1) i = -1;
            }
        }
    }

    void printMenu(bool printGraph = true) {
        this->cleanScreen();
        this->printHeader();

        if (printGraph) {
            this->printGraphs();
            cout << "Enter the number of a problem to solve it" << endl;
        }
    }

    void printHeader() {
        cout << "############################################" << endl;
        cout << "         TRAVELLING SALESMAN PROBLEM" << endl;
        cout << "############################################" << endl << endl;
    }

    void printGraphs() {
        for (int i = 0; i < this->graphs->getGraphs().size(); i++) {
            cout << "PROBLEM N. " << i + 1 << endl;
            this->printGraph(this->graphs->getGraph(i));
        }
    }

    void printGraph(GraphMatrix<int>* graph) {
        if (graph->getSize() > 0) {
            cout << "\t";
            for(int i = 0; i < graph->edges.size(); i++)
                cout << "(" << *graph->vertexes[i]->value << ")\t";
            cout << endl;

            for(int i = 0; i < graph->edges.size(); i++) {
                cout << "(" << *graph->vertexes[i]->value << ")\t";
                for(int j = 0; j < graph->edges[i].size(); j++)
                    cout << graph->edges[i][j] << "\t";
                cout << endl;
            }
            cout << endl << endl;
        }
    }

    int getIntInput() {
        int data;
        cout << "--> ";
        cin >> data;
        return data;
    }   

    float getFloatInput() {
        float data;
        cout << "--> ";
        cin >> data;
        return data;
    }    

    char getCharInput() {
        char data;
        cout << "--> ";
        cin >> data;
        return data;
    }    

    void cleanScreen() {
        system("cls");
    }
    
    void pause() {
        system("pause");
    }
};

#endif
