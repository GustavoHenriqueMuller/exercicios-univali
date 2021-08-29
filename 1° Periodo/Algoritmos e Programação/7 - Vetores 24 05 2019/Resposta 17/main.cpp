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
    int vetor1[10],vetor2[10],vetori[10];
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
    ///Fazendo vetor intersecção
    cont=0;
    int cont2=0;
    repeat=0;
    while(cont<10){//Checando por igualdade entre todos os valores dos dos vetores
        repeat=0;
        while(repeat<10){
            if(vetor1[cont]==vetor2[repeat]){
                vetori[cont2]=vetor1[cont];
                cont2++;
                cout<<"\nNumero ("<<vetor1[cont]<<") esta em comum";
                goto nextnumber3;
            }
            repeat++;
        }
        nextnumber3:
        cont++;
    }
    cout<<"\n";
    ///Ordena e printa elementos do vetor intersecção na tela
    sort(vetori,vetori+10);
    cont=0;
    cout<<"\n==========================================================\nVetor interseccao : \n\n";
    while(cont<10){
        if((vetori[cont]<101)&(vetori[cont]>0)){
                cout<<"["<<vetori[cont]<<"] ";
        }
        cont++;
    }
    cout<<"\n";
    return 0;
}
