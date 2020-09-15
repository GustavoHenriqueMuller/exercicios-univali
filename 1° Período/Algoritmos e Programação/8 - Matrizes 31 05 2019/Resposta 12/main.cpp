#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[5][5];
    int val=0,som=2;
    int i=0,j=0;
    ///gerando e printando a matriz
    while(i<5){
        cout<<"\n";
        j=0;
        ///linhas pares
        if(i==0){
            val=0;
        } else if (i==2){
            val=10;
        } else if (i==4){
            val=20;
        }
        ///linhas ímpares
        if(i==1){
            val=1;
        } else if (i==3){
            val=11;
        }
        while(j<5){
            mat[i][j]=val+som*j;
            cout<<"["<<mat[i][j]<<"]";
            j++;
        }
        i++;
    }
    cout<<"\n";
    return 0;
}
