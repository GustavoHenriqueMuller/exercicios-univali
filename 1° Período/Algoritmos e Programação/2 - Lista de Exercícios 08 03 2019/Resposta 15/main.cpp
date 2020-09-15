#include <iostream>

using namespace std;

int main()
{
    int n, reversedNumber = 0, remainder;

    cout << "Digite um numero de 5 digitos : \n";
    cin >> n;
    //SE O NUMERO FOR MUITO BAIXO
    if (n<10000){
        n = 10000;
    }
    //SE O NUMERO FOR MUITO ALTO
    if (n>99999){
        n = 99999;
    }
    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }

    cout << "Numero Reverso : " << reversedNumber;

    return 0;
}
