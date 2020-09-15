#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int valores[5];
    int cont=0;
    int qnt=0;
    while(cont<5){
        cout<<"Digite o valor "<<cont<<".\n";
        cin>>valores[cont];
        if((cont>0)&&(valores[cont]>valores[0])){
            qnt++;
        }
        cont++;
    }
    cout<<"\nHa "<<qnt<<" valores maiores que o primeiro valor (" << valores[0]<<") .\n";
    return 0;
}
