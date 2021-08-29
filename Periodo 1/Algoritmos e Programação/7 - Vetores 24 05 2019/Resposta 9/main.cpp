#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetorpar[30],vetorimpar[30];
    int cont=0,val;
    int somapar=0,somaimpar=0;
    while(cont<30){
        cout<<"Digite o valor "<<cont<<".\n";
        cin>>val;
            if((val%2)==0){
                vetorpar[cont]=val;
                somapar+=val;
            } else {
                vetorimpar[cont]=val;
                somaimpar+=val;
            }
        cont++;
    }
    if(somapar>=somaimpar){
        cout<<"\nA soma dos pares digitados e maior que a soma dos impares .\n";
    } else {
        cout<<"\nA soma dos impares digitados e maior que a soma dos pares .\n";
    }
    return 0;
}
