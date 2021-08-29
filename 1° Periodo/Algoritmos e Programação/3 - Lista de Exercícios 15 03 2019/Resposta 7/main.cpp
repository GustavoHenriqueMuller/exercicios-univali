#include <iostream>

using namespace std;

int main()
{
    int lado1,lado2,lado3;
    cout << "Digite o valor de cada um dos 3 lados de um triangulo:\n";
    cin>>lado1>>lado2>>lado3;
    if ((lado1>0) && (lado2>0) && (lado3>0)){
        //TRIANGULO EQUILATERO
        if ((lado1==lado2) && (lado2==lado3)){
            cout << "Esse triangulo e equilatero .";
        //TRIANGULO ESCALENO
        } else if ((lado1!=lado2) && (lado2!=lado3)) {
            cout << "Esse triangulo e escaleno .";
        //TRIANGULO ISOSCELES
        } else {
            cout << "Esse triangulo e isosceles .";
        }
    } else {
    cout << "Valor(es) invalido(s).\n";
    return 0;
    }
    return 0;
  }
