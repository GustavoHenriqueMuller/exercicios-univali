#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[5][5];
    int vetlinha[5],vetcoluna[5];
    int i=0,j=0;
    ///Gerando semente pseudo-aleatoria
    srand(time(NULL));
    ///Gerando matriz com elementos aleatorios
    while(i<5){
        j=0;
        while(j<5){
            if(j<4){
                mat[i][j]=rand()%100+1;
            }
            if(j==4){
                mat[i][j]=rand()%100+1;
                i++;
            }
            j++;
        }
    }
    ///Printando a matriz
    i=0;
    j=0;
    while(i<5){
        j=0;
        while(j<5){
            if(j<4){
                cout<<"["<<mat[i][j]<<"]";
            }
            if(j==4){
                cout<<"["<<mat[i][j]<<"]\n";
                i++;
            }
            j++;
        }
    }
    cout<<"\n";
    ///Setando o vetor linha
    i=0;
    j=0;
    while(i<5){
        j=0;
        vetlinha[i]=0;
        while(j<5){
            if(j<4){
                vetlinha[i]+=mat[i][j];
            }
            if(j==4){
                vetlinha[i]+=mat[i][j];
                i++;
            }
            j++;
        }
    }
    ///Printando vetor linha
    cout<<"=======================\nVETOR LINHA\n\n";
    i=0;
    while(i<5){
        cout<<"Soma linha "<<i<<" = "<<vetlinha[i]<<"\n";
        i++;
    }
    cout<<"\n";
    ///Setando o vetor coluna
    i=0;
    j=0;
    while(j<5){
        vetcoluna[j]=0;
        i=0;
        while(i<5){
            if(i<4){
                vetcoluna[j]+=mat[i][j];
            }
            if(i==4){
                vetcoluna[j]+=mat[i][j];
                j++;
            }
            i++;
        }
    }
    ///Printando vetor coluna
    cout<<"=======================\nVETOR COLUNA\n\n";
    i=0;
    while(i<5){
        cout<<"Soma coluna "<<i<<" = "<<vetcoluna[i]<<"\n";
        i++;
    }
    return 0;
}
