#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    long int val;
    int divisor=1,soma=0;
    bool perfeito=false;
    cout << "--------------------------------\nDigite um valor inteiro .\n";
    cin >> val;
    //ACHAR DIVISORES
    while(divisor<val){
        if ((val%divisor)==0){
            soma+=divisor;
        }
        divisor++;
    }
    //ESCREVER RESPOSTA
    if (soma==val){
        perfeito=true;
        cout << "--------------------------------\nO numero "<<val<<" e perfeito .\n";
    } else {
        perfeito=false;
        cout << "--------------------------------\nO numero "<<val<<" nao e perfeito .\n";
    }
    return 0;
}
