#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[3][3];
    int res[3][3];
    int i=0,j=0;
    ///gerando semente pseudo aleatoria
    srand(time(NULL));
    ///gerando e printando primeira matriz
    cout<<"\nMATRIZ ORIGINAL :\n";
    while(i<3){
        j=0;
        cout<<"\n";
        while(j<3){
            mat[i][j]=rand()%100+1;
            cout<<"["<<mat[i][j]<<"]";
            j++;
        }
        i++;
    }
    ///gerando e printando matriz rotacionada
    cout<<"\n\nMATRIZ ROTACIONADA :\n";
    i=0;
    j=0;
    while(i<3){
        j=0;
        cout<<"\n";
        while(j<3){
            if(j==0){
                if(i==0){
                    res[i][j]=mat[2][0];
                    cout<<"["<<res[i][j]<<"]";
                }
                if(i==1){
                    res[i][j]=mat[2][1];
                    cout<<"["<<res[i][j]<<"]";
                }
                if(i==2){
                    res[i][j]=mat[2][2];
                    cout<<"["<<res[i][j]<<"]";
                }
            }
            if(j==1){
                if(i==0){
                    res[i][j]=mat[1][0];
                    cout<<"["<<res[i][j]<<"]";
                }
                if(i==1){
                    res[i][j]=mat[1][1];
                    cout<<"["<<res[i][j]<<"]";
                }
                if(i==2){
                    res[i][j]=mat[1][2];
                    cout<<"["<<res[i][j]<<"]";
                }
            }
            if(j==2){
                if(i==0){
                    res[i][j]=mat[0][0];
                    cout<<"["<<res[i][j]<<"]";
                }
                if(i==1){
                    res[i][j]=mat[0][1];
                    cout<<"["<<res[i][j]<<"]";
                }
                if(i==2){
                    res[i][j]=mat[0][2];
                    cout<<"["<<res[i][j]<<"]";
                }
            }
            j++;
        }
        i++;
    }
    cout<<"\n";
    return 0;
}
