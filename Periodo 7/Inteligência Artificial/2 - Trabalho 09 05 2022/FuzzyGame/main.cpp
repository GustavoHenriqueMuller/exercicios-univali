#include "Console.h"
#include "Fuzzy.h"

using namespace std;

int main() {
        // Create function blocks
        FunctionBlock_game game;

        cleanScreen();
        printHeader();
        cout << "Insira o valor da variavel \"Preco\":" << endl;
        game.Preco = getDoubleInput();

        cleanScreen();
        printHeader();
        cout << "Insira o valor da variavel \"Quantidade_Analises_Positivas\":" << endl;
        game.Quantidade_Analises_Positivas = getDoubleInput();

        cleanScreen();
        printHeader();
        cout << "Insira o valor da variavel \"Quantidade_Espectadores\":" << endl;
        game.Quantidade_Espectadores = getDoubleInput();

        // Calculate
        cleanScreen();
        printHeader();
        game.calc();

        // Show results
        game.print();

        pause();
}