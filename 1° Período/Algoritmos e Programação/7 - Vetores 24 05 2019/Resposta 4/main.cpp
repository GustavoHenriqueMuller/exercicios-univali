#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor1[10],vetor2[10],soma=0;
    int cont=0;
    while(cont<10){
        cout<<"Digite o valor "<<cont<<" do primeiro vetor.\n";
        cin>>vetor1[cont];
        cont++;
    }
    cont=0;
    while(cont<10){
        cout<<"Digite o valor "<<cont<<" do segundo vetor.\n";
        cin>>vetor2[cont];
        cont++;
    }
    cont=0;
    while(cont<10){
        soma+=(vetor2[10-cont]-vetor1[cont]);
        cont++;
    }
    cout<<"A soma requerida e : "<<soma<<"\n";
    return 0;
}
