#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[5][5];
    int i=0,j=0;
    int val=0;
    ///gerando e printando matriz
    while(i<5){
        cout<<"\n";
        j=0;
        while(j<5){
            if(i>j){
                mat[i][j]=0;
                cout<<"["<<mat[i][j]<<"]";
            } else {
                val++;
                mat[i][j]=val;
                cout<<"["<<mat[i][j]<<"]";
            }
            j++;
        }
        i++;
    }
    cout<<"\n";
    return 0;
}
