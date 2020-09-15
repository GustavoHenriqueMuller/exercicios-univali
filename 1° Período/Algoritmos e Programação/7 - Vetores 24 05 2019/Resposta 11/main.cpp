#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    //Programado por Gustavo Muller
    srand(time(NULL)); ///semente randomica
    int vetor[10],cont=0,qnt=0;
    while(cont<10){
        vetor[cont]=rand()%20+10;
        cout<<vetor[cont]<<" ";
        cont++;
    }
    cont=0;
    cout<<"\n";
    while(cont<10){
        if(((vetor[cont])%5)==0){
            cout<<"O numero de indice "<<cont<<" e multiplo de 5.\n";
            qnt++;
        }
        cont++;
    }
    cout<<qnt<<" numero(s) sao multiplos de 5.\n";
    return 0;
}
