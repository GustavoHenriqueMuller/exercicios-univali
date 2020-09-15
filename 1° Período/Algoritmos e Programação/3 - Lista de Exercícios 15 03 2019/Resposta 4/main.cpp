#include <iostream>

using namespace std;

int main()
{
    float num1,num2,num3,resultado;
    cout << "Digite o primeiro numero .\n";
    cin >> num1;
    cout << "Digite o segundo numero .\n";
    cin >> num2;
    cout << "Digite o terceiro numero .\n";
    cin >> num3;
    //Se o primeiro numero for o maior
    if ((num1 < num2) && (num1<num3)){
        resultado=num1;
    }
    //Se o segundo numero for o maior
    if ((num2 < num1) && (num2<num3)){
        resultado=num2;
    }
    //Se o terceiro numero for o maior
    if ((num3 < num1) && (num3<num2)){
        resultado=num3;
    }
    if ((num1!=num2) && (num2!=num3)){
        cout << "O menor numero e : "<<resultado<<"\n";
    }
    return 0;
}
