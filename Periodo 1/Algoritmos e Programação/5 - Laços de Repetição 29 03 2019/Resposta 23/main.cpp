#include <iostream>

using namespace std;

int main()
{
    // Programado por Gustavo Muller
    int ainic,binic;
    int resultado=0;
    int cont=1;
    cout << "Digite dois numeros inteiros .\n";
    cin>>ainic>>binic;
    while (cont<=binic){
        resultado+=ainic;
        cont++;
    }
    cout<<"A multiplicacao de "<<ainic<<" por "<<binic<<" e igual a : "<<resultado<<" .\n";
    return 0;
}
