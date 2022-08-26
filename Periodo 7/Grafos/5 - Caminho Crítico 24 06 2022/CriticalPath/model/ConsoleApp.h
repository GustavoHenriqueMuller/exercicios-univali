#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

#include <iostream>
#include "CriticalPath.h"

using namespace std;

class ConsoleApp {

private:
    CriticalPath* criticalPath;
    GraphMatrix<char>* graph;

public:
    ConsoleApp() {
        this->graph = new GraphMatrix<char>(true);
        Vertex<char>* root = new Vertex<char>('@');
        root->weight = 0;
        this->graph->addVertex(root);
    }

    void init() {
        int option = -1;
        while (option != 0) {
            this->printMenu();
            option = this->getIntInput();

            switch(option) {
                case 1:
                    this->addNewActivity();
                    break;

                case 2:
                    this->deleteActivity();
                    break;

                case 3:
                    this->addConnection();
                    break;

                case 4:
                    this->deleteConnection();
                    break;

                case 5:
                    this->updateDuration();
                    break;

                case 6:
                    this->calculateCriticalPath(true);
                    break;

                case 7:
                    this->calculateCriticalPath(false);
                    break;

                case 8:
                    this->loadDefault();
                    break;

                case 9:
                    this->loadDefault2();
                    break;

                default:
                    break;
            }
        }
    }

private:
    // TODO: Validate entry
    void addNewActivity() {
        cout << endl << "Choose an one letter identifier for your activity" << endl;
        Vertex<char>* newActivity = new Vertex<char>(this->getCharInput());

        cout << endl << "Set the duration of the activity" << endl;
        newActivity->weight = this->getIntInput();

        this->graph->addVertex(newActivity);
    }

    void deleteActivity() {
        cout << endl << "Choose an activity to delete" << endl;
        this->graph->removeVertex(this->getCharInput());
    }

    // TODO: Show available entries and validate
    void addConnection() {
        cout << endl << "Choose an activity" << endl;
        char activity = this->getCharInput();

        cout << "Connect it with" << endl;
        this->graph->addEdgeBetween(activity, this->getCharInput());
    }

    void deleteConnection() {
        cout << endl << "Choose an activity" << endl;
        char activity = this->getCharInput();

        cout << "Delete connection with" << endl;
        this->graph->removeEdgeBetween(activity, this->getCharInput());
    }

    void updateDuration() {
        cout << endl << "Choose an activity" << endl;
        char activity = this->getCharInput();
        cout << endl << "Enter the new duration" << endl;

        int position = this->graph->getPositionOf(activity);
        if (this->graph->indexIsValid(position))
            this->graph->vertexes[position]->weight = this->getIntInput();
    }

    void loadDefault() {
        this->graph->destroy();
        this->graph = new GraphMatrix<char>(true);
        Vertex<char>* root = new Vertex<char>('@');
        root->weight = 0;
        this->graph->addVertex(root);

        Vertex<char>* a = new Vertex<char>('A');
        Vertex<char>* b = new Vertex<char>('B');
        Vertex<char>* c = new Vertex<char>('C');
        Vertex<char>* d = new Vertex<char>('D');
        Vertex<char>* e = new Vertex<char>('E');
        Vertex<char>* f = new Vertex<char>('F');

        a->weight = 10;
        b->weight = 4;
        c->weight = 7;
        d->weight = 5;
        e->weight = 5;
        f->weight = 2;

        this->graph->addVertex(a);
        this->graph->addVertex(b);
        this->graph->addVertex(c);
        this->graph->addVertex(d);
        this->graph->addVertex(e);
        this->graph->addVertex(f);

        this->graph->addEdgeBetween('@', 'A');
        this->graph->addEdgeBetween('A', 'B');
        this->graph->addEdgeBetween('A', 'C');
        this->graph->addEdgeBetween('C', 'D');
        this->graph->addEdgeBetween('B', 'E');
        this->graph->addEdgeBetween('D', 'E');
        this->graph->addEdgeBetween('C', 'F');
    }

    void loadDefault2() {
        this->graph->destroy();
        this->graph = new GraphMatrix<char>(true);
        Vertex<char>* root = new Vertex<char>('@');
        root->weight = 0;
        this->graph->addVertex(root);

        Vertex<char>* a = new Vertex<char>('A');
        Vertex<char>* b = new Vertex<char>('B');
        Vertex<char>* c = new Vertex<char>('C');
        Vertex<char>* d = new Vertex<char>('D');
        Vertex<char>* e = new Vertex<char>('E');
        Vertex<char>* f = new Vertex<char>('F');
        Vertex<char>* g = new Vertex<char>('G');
        Vertex<char>* h = new Vertex<char>('H');
        Vertex<char>* i = new Vertex<char>('I');
        Vertex<char>* j = new Vertex<char>('J');
        Vertex<char>* k = new Vertex<char>('K');
        Vertex<char>* l = new Vertex<char>('L');

        a->weight = 6;
        b->weight = 2;
        c->weight = 3;
        d->weight = 10;
        e->weight = 3;
        f->weight = 2;
        g->weight = 4;
        h->weight = 5;
        i->weight = 8;
        j->weight = 6;
        k->weight = 4;
        l->weight = 2;

        this->graph->addVertex(a);
        this->graph->addVertex(b);
        this->graph->addVertex(c);
        this->graph->addVertex(d);
        this->graph->addVertex(e);
        this->graph->addVertex(f);
        this->graph->addVertex(g);
        this->graph->addVertex(h);
        this->graph->addVertex(i);
        this->graph->addVertex(j);
        this->graph->addVertex(k);
        this->graph->addVertex(l);

        this->graph->addEdgeBetween('@', 'A');
        this->graph->addEdgeBetween('@', 'B');
        this->graph->addEdgeBetween('@', 'C');
        this->graph->addEdgeBetween('A', 'D');
        this->graph->addEdgeBetween('A', 'E');
        this->graph->addEdgeBetween('B', 'F');
        this->graph->addEdgeBetween('C', 'G');
        this->graph->addEdgeBetween('E', 'H');
        this->graph->addEdgeBetween('F', 'I');
        this->graph->addEdgeBetween('G', 'I');
        this->graph->addEdgeBetween('G', 'J');
        this->graph->addEdgeBetween('I', 'K');
        this->graph->addEdgeBetween('J', 'L');
    }

    void calculateCriticalPath(bool startOnZero) {
        if (this->graph->getSize() > 0) {
            this->criticalPath = new CriticalPath(this->graph, startOnZero);
            this->printGraphWithCriticalPath();
        }
    }



    void printMenu() {
        this->cleanScreen();
        this->printHeader();

        if (this->graph->getSize() > 1)
            this->printGraph();

        cout << "[1] - Add new activity" << endl;
        cout << "[2] - Delete activity" << endl;
        cout << "[3] - Add connection" << endl;
        cout << "[4] - Delete connection" << endl;
        cout << "[5] - Update duration" << endl;
        cout << "[6] - Find critical path (0)" << endl;
        cout << "[7] - Find critical path (1)" << endl;
        cout << "[8] - Load default 1" << endl;
        cout << "[9] - Load default 2" << endl;
        cout << "[0] - Sair" << endl << endl;
    }

    void printHeader() {
        cout << "############################################" << endl;
        cout << "                CRITICAL PATH" << endl;
        cout << "############################################" << endl << endl;
    }

    void printGraphWithCriticalPath() {
        this->cleanScreen();
        cout << "Activity\tEarly\t\tLate\t\tSlack time\tPrecedents" << endl;
        for (int i = 0; i < this->graph->vertexes.size(); i++) {
            Vertex<char>* targetVertex = this->graph->vertexes[i];
            if (*targetVertex->value != '@') {
                cout << *targetVertex->value << " (" << targetVertex->weight << ")\t\t";
                cout << targetVertex->earlyStart << " | " << targetVertex->earlyFinish << "\t\t";
                cout << targetVertex->lateStart << " | " << targetVertex->lateFinish << "\t\t";
                cout << targetVertex->slackTime << "\t\t";
                this->printVertexesConnectedWith(targetVertex);
            }
        }

        cout << endl << "Critical path: " << this->criticalPath->getCriticalPath() << endl << endl;
        this->pause();
    }

    void printGraph() {
        cout << "Activity\tDuration\tPrecedents" << endl;
        for (int i = 0; i < this->graph->vertexes.size(); i++) {
            Vertex<char>* targetVertex = this->graph->vertexes[i];
            if (*targetVertex->value != '@') {
                cout << *targetVertex->value << "\t\t" << targetVertex->weight << "\t\t";
                this->printVertexesConnectedWith(targetVertex);
            }
        }
            
        cout << endl << endl;
    }

    void printVertexesConnectedWith(Vertex<char>* vertex) {
        vector<Vertex<char>*> vertexesConnectedWith = this->graph->getVertexesConnectedWith(vertex);

        cout << "[";
        for(auto i = vertexesConnectedWith.begin(); i != vertexesConnectedWith.end(); i++) {
            if (i != vertexesConnectedWith.begin())
                cout << ", ";
            if (*((*i)->value) != '@')
                cout << *((*i)->value);
        }
        cout << "]" << endl;
    }

    int getIntInput() {
        int data;
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
