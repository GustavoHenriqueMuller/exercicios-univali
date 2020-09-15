#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int n,var1=1,var2=1,cont=0;
    cout << "Indique um numero da Sequencia de Fibonacci :\n";
    cin>>n;
    cout<<"\n";
    while(cont<=n-2){
        cout<<var1<<"\n";
        cout<<var2<<"\n";
        var1 = var1+var2;
        var2 = var2+var1;
        cont++;
    }
    return 0;
}
