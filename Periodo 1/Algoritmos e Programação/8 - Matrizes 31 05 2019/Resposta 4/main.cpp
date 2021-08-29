#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[4][4];
    int i=0,j=0;
    int val;
    int sum=0;
    ///Setando valores da matriz
    while(i<4){
        j=0;
        while(j<4){
            if(j<3){
                cout<<"["<<i<<"]["<<j<<"] : ";
                cin>>val;
                mat[i][j]=val;
            }
            if(j==3){
                cout<<"["<<i<<"]["<<j<<"] : ";
                cin>>val;
                mat[i][j]=val;
                i++;
                cout<<"\n";
            }
            j++;
        }
    }
    ///Calculando soma da diagonal principal e dizendo resultado
    i=0;
    while(i<4){
        sum+=mat[i][i];
        i++;
    }
    cout<<"\nA soma dos elementos da diagonal principal da matriz digitada e : "<<sum<<".\n";
    return 0;
}
