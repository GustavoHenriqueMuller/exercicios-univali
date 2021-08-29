#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[5][5];
    int var,i=0,j=0;
    int sum=0;
    ///Declarando as colunas
    while((i<5)&&(j<5)){
        if(i<4){
            cout<<"var i"<<i<<" j"<<j<<" = ";
            cin>>var;
            sum+=var;
            mat[i][j]=var;
            i++;
        }
        if(i==4){
            cout<<"var i"<<i<<" j"<<j<<" = ";
            cin>>var;
            sum+=var;
            mat[i][j]=var;
            i=0;
            j++;
        }
    }
    cout<<"\nA soma de todos os valores da matriz e "<<sum<<".\n";
    return 0;
}
