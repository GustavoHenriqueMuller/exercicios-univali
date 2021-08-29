#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    float mat[20][20];
    float matre[20][20];
    float vet[20];
    int i=0,j=0;
    ///Gerando semente e matriz aleatórias
    srand(time(NULL));
    while(i<20){
        j=0;
        while(j<20){
            if(j<19){
                mat[i][j]=rand()%100+1;
            }
            if(j==19){
                mat[i][j]=rand()%100+1;
                i++;
            }
            j++;
        }
    }
    i=0;
    j=0;
    ///Printando mat
    while(i<20){
        j=0;
        while(j<20){
            if(j<19){
                cout<<"["<<mat[i][j]<<"]";
            }
            if(j==19){
                cout<<"["<<mat[i][j]<<"]\n";
                i++;
            }
            j++;
        }
    }
    i=0;
    j=0;
    ///Setando vetor através de soma de linhas da matriz
    while(i<20){
        j=0;
        vet[i]=0;
        while(j<20){
            if(j<19){
                vet[i]+=mat[i][j];
            }
            if(j==19){
                vet[i]+=mat[i][j];
                i++;
            }
            j++;
        }
    }
    i=0;
    ///Printando vetor
    cout<<"\n\n";
    while(i<20){
        cout<<"Soma da linha "<<i<<" = "<<vet[i]<<"\n";
        i++;
    }
    ///Fazendo matriz resultante
    i=0;
    j=0;
    while(i<20){
        j=0;
        while(j<20){
            if(j<19){
                matre[i][j]=mat[i][j]*vet[i];
            }
            if(j==19){
                matre[i][j]=mat[i][j]*vet[i];
                i++;
            }
            j++;
        }
    }
    ///Printando matriz resultante
    cout<<"\n\n";
    i=0;
    j=0;
    while(i<20){
        j=0;
        while(j<20){
            if(j<19){
                cout<<"["<<matre[i][j]<<"]";
            }
            if(j==19){
                cout<<"["<<matre[i][j]<<"]\n";
                i++;
            }
            j++;
        }
    }
    i=0;
    j=0;
    return 0;
}
