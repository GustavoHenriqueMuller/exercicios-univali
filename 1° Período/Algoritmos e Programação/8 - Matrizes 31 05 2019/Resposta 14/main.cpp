#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[5][5];
    int i=0,j=0;
    ///gerando e printando a matriz
    while(i<5){
        cout<<"\n";
        j=0;
        while(j<5){
            if((i+j)%2==0){
                mat[i][j]=0;
                cout<<"["<<mat[i][j]<<"]";
            } else {
                mat[i][j]=1;
                cout<<"["<<mat[i][j]<<"]";
            }
            j++;
        }
        i++;
    }
    return 0;
}
