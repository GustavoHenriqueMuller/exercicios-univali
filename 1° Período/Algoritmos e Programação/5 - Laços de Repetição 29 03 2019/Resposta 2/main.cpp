#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int val,soma=0;
    int cont=1;
    cout << "Digite 10 valores inteiros : \n";
    while (cont<=10){
        cin>>val;
        soma+=val;
        cont++;
    }
    cout<<"A soma dos 10 numeros e : "<<soma<<"\n";
    return 0;
}
