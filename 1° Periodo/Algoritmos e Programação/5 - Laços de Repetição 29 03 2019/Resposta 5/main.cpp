#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int val,cont=1;
    cout << "Digite um numero inteiro qualquer .\n";
    cin>>val;
    cout << "A tabuada do numero "<<val<<" , de um a 10 e :\n";
        while(cont<=10){
        cout<<val*cont<<"\n";
        cont++;
    }
    return 0;
}
