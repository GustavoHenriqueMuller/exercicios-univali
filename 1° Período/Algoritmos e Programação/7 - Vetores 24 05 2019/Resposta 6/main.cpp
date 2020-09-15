#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor1[5],vetor2[5];
    int cont=0;
        while(cont<5){
            cout<<"Digite o valor "<<cont<<" do vetor.\n";
            cin>>vetor1[cont];
            cont++;
        }
    cont=0;
        while(cont<5){
            vetor2[cont]=vetor1[5-1-cont];
            cont++;
        }
    cont=0;
    cout<<"=====================================\nO vetor invertido e :\n";
        while(cont<5){
            cout<<"["<<vetor2[cont]<<"] ";
            cont++;
        }
    cout<<"\n=====================================\n";
    return 0;
}
