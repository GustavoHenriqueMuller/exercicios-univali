#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor1[10],vetor2[10],vetorfinal[10];
    int cont=0;
    while(cont<10){
        cout<<"Digite o valor "<<cont<<" do primeiro vetor .\n";
        cin>>vetor1[cont];
        cont++;
    }
    cont=0;
    while(cont<10){
        cout<<"Digite o valor "<<cont<<" do segundo vetor .\n";
        cin>>vetor2[cont];
        cont++;
    }
    cont=0;
    cout<<"============================================\nO vetor resultante da multiplicacao entre os dois vetores digitados e :\n";
    while(cont<10){
        vetorfinal[cont]=(vetor1[cont]*vetor2[cont]);
        cout<<"["<<vetorfinal[cont]<<"] ";
        cont++;
    }
    return 0;
}
