#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int anos=0;
    float alturachico,alturaze;
    cout << "Chico tem 1,50 metros e cresce 2 centimetros por ano, enquanto Ze tem 1,10 metro e cresce 3 centimetros por ano. \n";
    while(alturaze<=alturachico){
        anos++;
        alturachico=1.5+0.02*anos;
        alturaze=1.1+0.03*anos;
    }
    cout << "Logo , demorara "<<anos<<" anos para Ze ser maior que Chico .\n";
    return 0;
}
