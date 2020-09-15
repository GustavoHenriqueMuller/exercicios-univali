#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int idade,cont=1,cont18=0;
    cout << "Digite a idade de 10 pessoas : \n";
    while (cont<=10){
        cin>>idade;
        cont++;
        if (idade>=18){
            cont18++;
        }
    }
    cout<<"De todas as pessoas , "<<cont18<<" delas sao maiores de idade .\n";
    return 0;
}
