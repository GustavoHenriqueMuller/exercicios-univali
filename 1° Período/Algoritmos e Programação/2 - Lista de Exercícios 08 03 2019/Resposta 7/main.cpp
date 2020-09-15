#include <iostream>

using namespace std;

int main()
{
    float km;
    float kmpl;
    float ppl;
    float custototal;
    cout << "Indique quantos Km o carro ira percorrer : \n";
    cin >> km;
    cout << "Indique o consumo em Km por litro do carro : \n";
    cin >> kmpl;
    cout << "Indique o preco do litro da gasolina : \n";
    cin >> ppl;
    custototal = (kmpl*km)*ppl;
    cout << "O custo total sera de : " << custototal << "R$ .";
    return 0;
}
