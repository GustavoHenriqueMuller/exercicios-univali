#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetora[8],vetorb[8];
    int cont=0;
        while(cont<8){
            cout<<"Digite o valor "<<cont<<" do primeiro vetor .\n";
            cin>>vetora[cont];
            cont++;
        }
    cont=0;
    cout<<"\n";
        while(cont<8){
            cout<<"Digite o valor "<<cont<<" do segundo vetor .\n";
            cin>>vetorb[cont];
            cont++;
        }
    cont=0;
        while(cont<8){
            int olda;
            olda=vetora[cont];
            vetora[cont]=vetorb[cont];
            vetorb[cont]=olda;
            olda=0;
            cont++;
        }
    cont=0;
    cout<<"\n==============================================\nVetor A Invertido :\n";
        while(cont<8){
            cout<<"["<<vetora[cont]<<"] ";
            cont++;
        }
        cont=0;
    cout<<"\n==============================================\nVetor B Invertido :\n";
        while(cont<8){
            cout<<"["<<vetorb[cont]<<"] ";
            cont++;
        }
    cout<<"\n==============================================\n";
    return 0;
}
