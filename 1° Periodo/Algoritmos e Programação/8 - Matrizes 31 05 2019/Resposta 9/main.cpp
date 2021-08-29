#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int matX[5][5],matY[5][5],matW[5][5],vetorp[5];
    int i=0,j=0;
    int menorcol=-1,sum=0,aux=9999999999;
    ///setando valores das matrizes x e y pelo usuário
    cout<<"\nMATRIZ X :\n";
    while(i<5){
        cout<<"\n";
        j=0;
        while(j<5){
            cout<<"["<<i<<"]["<<j<<"] : ";
            cin>>matX[i][j];
            j++;
        }
        i++;
    }
    i=0;
    j=0;
    cout<<"\nMATRIZ Y :\n";
    while(i<5){
        cout<<"\n";
        j=0;
        while(j<5){
            cout<<"["<<i<<"]["<<j<<"] : ";
            cin>>matY[i][j];
            j++;
        }
        i++;
    }
    ///setando valores e printando matriz w pelo usuário
    i=0;
    j=0;
    while(i<5){
        j=0;
        while(j<5){
            if(matX[i][j]<matY[i][j]){
                matW[i][j]=matX[i][j];
            } else if (matX[i][j]==matY[i][j]){
                matW[i][j]=matX[i][j];
            } else {
                matW[i][j]=matY[i][j];
            }
            j++;
        }
        i++;
    }
    cout<<"\nMATRIZ W :\n";
    i=0;
    j=0;
    while(i<5){
        j=0;
        cout<<"\n";
        while(j<5){
            cout<<"["<<matW[i][j]<<"] ";
            j++;
        }
        i++;
    }
    ///gerando e printando vetor c/ valores da diagonal principal da matriz x
    i=0;
    while(i<5){
        vetorp[i]=matX[i][i];
        i++;
    }
    cout<<"\n\nVETOR DIAGONAL PRINCIPAL :\n\n";
    i=0;
    while(i<5){
        cout<<"["<<vetorp[i]<<"] ";
        i++;
    }
    ////ERORASOKASIJASDIOJASDIOJSADUIOJDSAJIODSAJIOUDSAIJOSDAJIADSJIOADSJOIADSJOASDJO
    ///encontrando e printando coluna da matriz y com menor soma de valores
    i=0;
    j=0;
    while(j<5){
        i=0;
        sum=0;
        while(i<5){
            sum+=matY[i][j];
            i++;
        }
        if(sum<aux){
            aux=sum;
            menorcol=j;
        }
        j++;
    }
    cout<<"\n\nO indice da coluna da matriz Y com a menor soma de elementos e : "<<menorcol<<".\n";
    return 0;
}
