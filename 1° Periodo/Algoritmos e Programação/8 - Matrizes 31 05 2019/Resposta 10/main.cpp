#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[5][5];
    int i=0,j=0;
    int sum=0;
    ///gerando seed pseudo aleatoria
    srand(time(NULL));
    ///gerando e printando matriz aleatória
    while(i<5){
        j=0;
        cout<<"\n";
        while(j<5){
            mat[i][j]=rand()%100+1;
            cout<<"["<<mat[i][j]<<"]";
            j++;
        }
        i++;
    }
    ///fazendo a soma dos elementos da área
    i=0;
    j=0;
    while(j<5){
        i=0;
        while(i<5){
            if((j==0)||(j==4)){
                if((i==0)||(i==4)){
                    sum+=mat[i][j];
                }
            } else if ((j==1)||(j==3)){
                if((i==0)||(i==1)||(i==3)||(i==4)){
                    sum+=mat[i][j];
                }
            } else {
                sum+=mat[i][j];
            }
            i++;
        }
        j++;
    }
    cout<<"\n\nA soma dos elementos da area e : "<<sum<<".\n";
    return 0;
}
