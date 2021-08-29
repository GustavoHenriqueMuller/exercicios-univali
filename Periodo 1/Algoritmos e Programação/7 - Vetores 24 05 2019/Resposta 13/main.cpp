#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor1[10];
    int cont=0,repeat=0;
    ///Gera numeros aleatorios nos vetores de 1 a 100
    srand (time(NULL));
    while(cont<10){
        vetor1[cont]=rand()%19+1;
        //Checar por numero repetido no primeiro vetor
        repeat=0;
            while(repeat<=cont){
                if(repeat==cont){
                    goto nextnumber;
                }
                if(vetor1[cont]==vetor1[repeat]){
                    vetor1[cont]++;
                    repeat=-1;
                }
                repeat++;
            }
        nextnumber:
        cont++;
    }
    ///Ordena elementos do vetor
    sort(vetor1,vetor1+10);
    ///Printa elementos do vetor na tela
    cont=0;
    while(cont<10){
        cout<<"["<<vetor1[cont]<<"] ";
        cont++;
    }
    return 0;
}
