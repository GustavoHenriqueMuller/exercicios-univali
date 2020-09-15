#include <iostream>

using namespace std;

int main()
{
    float num1,num2;
    cout << "Digite o primeiro numero.\n";
    cin >> num1;
    cout << "Digite o segundo numero.\n";
    cin >> num2;
    if (num1>num2) {
        cout << "O primeiro numero e o maior (" << num1 << ").\n";
    }
    if (num2>num1) {
        cout << "O segundo numero e o maior (" << num2 << ").\n";
    }
    if (num2==num1) {
        cout << "Os dois numeros sao iguais.\n";
    }
    return 0;
}
