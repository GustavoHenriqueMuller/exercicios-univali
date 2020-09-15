#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor[5];
    int cont=0;
        while(cont<5){
            cout<<"Digite o valor "<<cont<<" do vetor.\n";
            cin>>vetor[cont];
            cont++;
        }
    cont=0;
        while(cont<2.5){
            swap(vetor[cont],vetor[5-1-cont]);
            cont++;
        }
    cont=0;
    cout<<"\n=====================================\nO vetor invertido e :\n";
        while(cont<5){
            cout<<"["<<vetor[cont]<<"] ";
            cont++;
        }
    cout<<"\n=====================================\n";
    return 0;
}
