#include <iostream>

using namespace std;

int main()
{
    float nota1 , nota2 , nota3 , notafinal;
    cout << "Indique a nota da prova 1 : \n";
    cin >> nota1;
    cout << "Indique a nota da prova 2 : \n";
    cin >> nota2;
    cout << "Indique a nota da prova 3 : \n";
    cin >> nota3;
    notafinal = nota1*0.2 + nota2*0.4 + nota3*0.6;
    cout << "A sua media final e : " << notafinal;
    return 0;
}
