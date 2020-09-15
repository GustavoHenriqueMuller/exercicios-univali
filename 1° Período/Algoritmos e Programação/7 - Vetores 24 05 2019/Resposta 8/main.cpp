#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor[10];
    int cont=0;
    while(cont<10){
        cout<<"Digite o valor "<<cont<<" do vetor.\n";
        cin>>vetor[cont];
        cont++;
    }
    cont=0;
    cout<<"\n";
    while(cont<10){
        if(((vetor[cont])%5)==0){
            cout<<"O valor de indice "<<cont<<" ("<<vetor[cont]<<") e multiplo de 5.\n";
        }
        cont++;
    }
    return 0;
}
