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
    int vetor1[10],vetor2[10],vetoru[20];
    int cont=0,repeat=0;
    ///Gera numeros aleatorios nos vetores de 1 a 100
    srand (time(NULL));
    ///Primeiro Vetor
    while(cont<10){
        vetor1[cont]=rand()%100+1;
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
    cont=0;
    ///Segundo Vetor
    while(cont<10){
        vetor2[cont]=rand()%100+1;
        //Checar por numero repetido no segundo vetor
        repeat=0;
            while(repeat<=cont){
                if(repeat==cont){
                    goto nextnumber2;
                }
                if(vetor2[cont]==vetor2[repeat]){
                    vetor2[cont]++;
                    repeat=-1;
                }
                repeat++;
            }
        nextnumber2:
        cont++;
    }
    ///Ordenando vetores
    sort(vetor1,vetor1+10);
    sort(vetor2,vetor2+10);
    ///Printa elementos do primeiro vetor na tela
    cont=0;
    while(cont<10){
        cout<<"["<<vetor1[cont]<<"] ";
        cont++;
    }
    cout<<"\n";
    ///Printa elementos do segundo vetor na tela
    cont=0;
    while(cont<10){
        cout<<"["<<vetor2[cont]<<"] ";
        cont++;
    }
    cout<<"\n";
    ///Fazendo vetor união
    cont=0;
    repeat=0;
    while(cont<10){//Checando por valores do primeiro vetor
        repeat=0;
        while(repeat<=cont){
            if(vetor1[cont]==vetoru[repeat]){
                goto nextnumber3;
            }
            if(repeat==cont){
                vetoru[cont]=vetor1[cont];
            }
            repeat++;
        }
        nextnumber3:
        cont++;
    }
    cont=0;
    repeat=0;
    while(cont<20){//Checando por valores do segundo vetor
        repeat=0;
        while(repeat<=cont){
            if(vetor2[cont]==vetoru[repeat]){
                goto nextnumber4;
            }
            if(repeat==cont){
                vetoru[cont]=vetor2[cont];
            }
            repeat++;
        }
        nextnumber4:
        cont++;
    }
    cout<<"\n";
    ///Ordena e printa elementos do vetor uniao na tela
    sort(vetoru,vetoru+20);
    cont=0;
    cout<<"====================================================================\nVetor uniao : \n\n";
    while((cont<20)&(vetoru[cont]<101)&(vetoru[cont]>0)){
        cout<<"["<<vetoru[cont]<<"] ";
        cont++;
    }
    cout<<"\n";
    return 0;
}
