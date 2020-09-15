#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    double int n,cont=1;
    double float soma=0;
    cout<<"Digite o valor de N para a seguinte equacao : \n";
    cout << "S = 1/1 + 1/2 + 1/3 + ... + 1/N \n";
    cin>>n;
    while(cont<=n){
        soma+= 1.0/cont;
        cont++;
    }
    cout <<"Resultado : "<<soma<<" .\n";
    return 0;
}
