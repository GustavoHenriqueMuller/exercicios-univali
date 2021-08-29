#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int valinic,val,cont;
    cout << "Escreva um valor inteiro.\n";
    cin>>valinic;
    val=valinic;
    cont=valinic-1;
    while (cont>0){
        val = val*cont;
        cont=cont-1;
    }
    cout <<"O fatorial de "<<valinic<<" e "<<val<<".\n";
    return 0;
}
