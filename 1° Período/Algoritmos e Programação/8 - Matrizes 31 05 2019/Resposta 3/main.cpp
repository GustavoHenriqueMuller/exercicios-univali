#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[5][5];
    int maior=-1;
    int i=0,j=0;
    ///Gerando seed para valores pseudo-aleatórios
    srand(time(NULL));
    ///Preencher matriz com valores aleatórios
    while((i<5)&&(j<5)){
        if(j<4){
            mat[i][j]=rand()%100+1;
            if(mat[i][j]>maior){
                maior=mat[i][j];
            }
        }
        if(j==4){
            mat[i][j]=rand()%100+1;
            if(mat[i][j]>maior){
                maior=mat[i][j];
            }
            j=-1;
            i++;
        }
        j++;
    }
    ///Mostrando matriz
    i=0;
    j=0;
    while(i<5){
        j=0;
        while(j<5){
            if(j<4){
                cout<<"["<<i<<"]["<<j<<"] : "<<mat[i][j]<<"\n";
            }
            if(j==4){
                cout<<"["<<i<<"]["<<j<<"] : "<<mat[i][j]<<"\n";
                i++;
                cout<<"\n";
            }
            j++;
        }
    }
    cout<<"\nO maior elemento da matriz acima e "<<maior<<" .\n";
    return 0;
}
