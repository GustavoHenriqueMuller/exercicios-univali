#include <iostream>
#define TAMANHO 30
using namespace std;

//Programado por Gustavo Muller
int main()
{
    int valores[TAMANHO];
    int cont=0;
    int qnt2=0,qnt3=0;
    while(cont<TAMANHO){
        valores[cont]=cont;
        cont++;
    }
    cont=0;
    while(cont<TAMANHO){
        if(((valores[cont])%2)==0){
            qnt2++;
        }
        if(((valores[cont])%3)==0){
            qnt3++;
        }
        cont++;
    }
    cont=0;
    while(cont<TAMANHO){
        cout<<valores[cont]<<" ";
        cont++;
    }
    cout << "\n\nNo vetor acima , ha " << qnt2 << " valores multiplos de 2 e " << qnt3 << " valores multiplos de 3 .\n";
    return 0;
}
