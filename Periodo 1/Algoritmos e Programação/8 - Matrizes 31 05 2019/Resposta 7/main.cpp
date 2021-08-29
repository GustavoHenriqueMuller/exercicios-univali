#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int mat[10][10];
    int i=0,j=0;
    int vetlinha[10],vetcol[10];
    int val,maior=-999999,menor=999999;
    ///Lê valores da matriz
    while(i<10){
        j=0;
        while(j<10){
            if(j<9){
                cout<<"["<<i<<"]["<<j<<"] = ";
                cin>>val;
                mat[i][j]=val;
            }
            if(j==9){
                cout<<"["<<i<<"]["<<j<<"] = ";
                cin>>val;
                mat[i][j]=val;
                cout<<"\n\n";
                i++;
            }
            j++;
        }
    }
    ///Setando vetor linha e printando maiores valores
    i=0;
    j=0;
    while(i<10){
        j=0;
        while(j<10){
            if(j==0){
                maior=mat[i][j];
            }
            if((j<9)&&(j>0)){
                if(mat[i][j]>maior){
                    maior=mat[i][j];
                }
            }
            if(j==9){
                if(mat[i][j]>maior){
                    maior=mat[i][j];
                }
                cout<<"Maior elemento linha "<<i<<" = "<<maior<<".\n";
                i++;
            }
            j++;
        }
    }
    cout<<"\n\n";
    ///Setando vetor coluna e printando menores valores
    i=0;
    j=0;
    while(j<10){
        i=0;
        while(i<10){
            if(i==0){
                menor=mat[i][j];
            }
            if((i<9)&&(i>0)){
                if(mat[i][j]<menor){
                    menor=mat[i][j];
                }
            }
            if(i==9){
                if(mat[i][j]<menor){
                    menor=mat[i][j];
                }
                cout<<"Menor elemento coluna "<<j<<" = "<<menor<<".\n";
                j++;
            }
            i++;
        }
    }
    return 0;
}
