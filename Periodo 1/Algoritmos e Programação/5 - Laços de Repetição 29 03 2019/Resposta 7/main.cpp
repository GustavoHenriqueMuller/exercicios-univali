#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int baseinic,base,expoente,cont=2,resultado;
    cout << "Escreva o valor de uma base e um expoente , respectivamente : \n";
    cin>>baseinic>>expoente;
    base=baseinic;
    while(cont<=expoente){
        base=base*baseinic;
        cont++;
    }
    resultado=base;
    cout <<baseinic<<" elevado a "<<expoente<<" e "<<resultado<<" .\n";
    return 0;
}
