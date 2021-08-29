#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    reset:
    int val,cont=1;
    int primo=0;
    cout<<"-----------------------------\n";
    cout<<"Digite um numero : \n";
    cin>>val;
    while (cont<=val){
        if ((val%cont==0)&&(cont!=1)&&(cont!=val)){
            primo=0;
            goto saida;
        }
        if ((cont==val)){
            primo=1;
            goto saida;
        }
        cont++;
    }
    saida:
    if ((primo==1)&&(val!=1)){
        cout<<"O numero "<<val<<" e primo .\n";
    } else if (primo==0) {
        cout<<"O numero "<<val<<" nao e primo .\n";
    } else if (val==1) {
        cout<<"O numero "<<val<<" nao e primo .\n";
    }
    goto reset;
    return 0;
}
