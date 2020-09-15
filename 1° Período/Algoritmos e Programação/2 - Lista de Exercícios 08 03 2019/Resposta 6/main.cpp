#include <iostream>

using namespace std;

int main()
{
    int hamburguer;
    cout << "Informe a quantidade de hamburgueres desejada : \n";
    cin >> hamburguer;
    cout << "Sera necessario " << hamburguer*2.0 << " fatia(s) de queijo, " << hamburguer << " fatia(s) de presunto e " << hamburguer << " rodela(s) de carne.\n";
    cout << "Ou seja , " << ((hamburguer*2*50 + hamburguer*50 + hamburguer*100)/1000.0) << " kg de ingredientes.";
    return 0;
}
