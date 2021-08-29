#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int val,media=0,soma=0,cont=0;
    cout << "Digite um valor indeterminado de numeros inteiros . Para encerrar o processo , digite 0.\n";
    while(val!=0){
        cin>>val;
        if (val%2==0){
            cont++;
            soma+=val;
        }
    }
    media = ((soma+val)/cont);
    cout <<"A media de todos os numeros pares digitados e "<<media<<" .\n";
    return 0;
}
