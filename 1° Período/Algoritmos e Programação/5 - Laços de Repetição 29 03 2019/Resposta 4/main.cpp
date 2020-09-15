#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int val,menor=0,maior=0;
    cout << "Digite um valor indeterminado de numeros inteiros . Para encerrar o processo , digite 0 ou um numero negativo .\n";
    while(val>0){
        cin>>val;
        if (val>maior){
            maior=val;
            }
        if (val<menor){
            menor=val;
            }
    }
    cout <<"O menor valor e : "<< menor << ".\n";
    cout <<"O maior valor e : "<< maior << ".\n";
    return 0;
}
