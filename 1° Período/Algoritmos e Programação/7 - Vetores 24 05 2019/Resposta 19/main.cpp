#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor1[5],vetor2[5],vetori[10];
    int cont=0,repeat=0;
    ///Gerando semente aleatoria
    srand(time(NULL));
    ///Preenchendo vetores e ordenando
        ///Primeiro vetor
        while(cont<5){
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
        while(cont<5){
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
        while(cont<5){
            cout<<"["<<vetor1[cont]<<"] ";
            cont++;
        }
    cout<<"\n\n";
    ///Printa elementos do segundo vetor na tela
    cont=0;
        while(cont<5){
            cout<<"["<<vetor2[cont]<<"] ";
            cont++;
        }
    cout<<"\n";
    ///Faz e printa vetor intercalação
    cout<<"\n===========================================\nVetor intercalacao :\n\n";
    cont=0;
    int contv1=0,contv2=0;
        while(cont<10){
            if((cont%2)==0){
                vetori[cont]=vetor1[contv1];
                contv1++;
            }
            if((cont%2)!=0){
                vetori[cont]=vetor2[contv2];
                contv2++;
            }
            cont++;
        }
    cont=0;
        while(cont<10){
            cout<<"["<<vetori[cont]<<"] ";
            cont++;
        }
    return 0;
}
