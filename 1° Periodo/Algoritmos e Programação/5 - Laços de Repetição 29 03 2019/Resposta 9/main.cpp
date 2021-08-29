#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
	//Lembre-se que 0 não é positivo , e sim não-negativo !
    float val;
    cout << "Digite um numero real positivo : \n";
    leitura:
    cin>>val;
    if (val>0){
        cout<<"Numero valido.\n";
    } else {
        cout<<"Numero invalido . Tente novamente .\n";
        goto leitura;
    }
    return 0;
}
