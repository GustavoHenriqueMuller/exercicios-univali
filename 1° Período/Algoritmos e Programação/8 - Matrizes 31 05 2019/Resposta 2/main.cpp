#include <iostream>

using namespace std;


void resetij(int &i, int &j){
    i=0;
    j=0;
}

int main()
{
    //Programado por Gustavo Muller
    int A[3][5],B[3][5],C[3][5];
    int i=0,j=0;
    int val;
    ///Setando valores da Matriz A
        while((i<=3)){
            if(j<4){
                cout<<"A ["<<i<< "]["<<j<<"]: ";
                cin>>val;
                A[i][j]=val;
            }
            if(j==4){
                cout<<"A ["<<i<< "]["<<j<<"]: ";
                cin>>val;
                A[i][j]=val;
                cout<<"\n";
                i++;
                j=-1;
            }
            j++;
        }
    cout<<"\n\n";
    resetij(i,j);
    ///Setando valores da Matriz B
        while((i<=3)){
            if(j<4){
                cout<<"B ["<<i<< "]["<<j<<"]: ";
                cin>>val;
                B[i][j]=val;
            }
            if(j==4){
                cout<<"B ["<<i<< "]["<<j<<"]: ";
                cin>>val;
                B[i][j]=val;
                cout<<"\n";
                i++;
                j=-1;
            }
            j++;
        }
    resetij(i,j);
    ///Setando valores da Matriz C
    while(i<=3){
       if(j<4){
          C[i][j]=A[i][j]+B[i][j];
       }
       if(j==4){
          C[i][j]=A[i][j]+B[i][j];
          i++;
          j=-1;
       }
       j++;
    }
    cout<<"\n\n";
    resetij(i,j);
    ///Mostrando todos os elementos da linha 2 e da coluna 3 da Matriz C
    cout<<"Elementos da segunda linha da Matriz C :\n";
    i=1;
    while(i==1){
        while(j<=4){
            cout<<"["<<i<<"] ["<<j<<"] : "<<C[i][j]<<" \n";
            j++;
        }
        i++;
    }
    resetij(i,j);
    cout<<"\nElementos da terceira coluna da Matriz C :\n";
    j=2;
    while(j==2){
        while(i<=3){
            cout<<"["<<i<<"] ["<<j<<"] : "<<C[i][j]<<" \n";
            i++;
        }
        j++;
    }
    return 0;
}
