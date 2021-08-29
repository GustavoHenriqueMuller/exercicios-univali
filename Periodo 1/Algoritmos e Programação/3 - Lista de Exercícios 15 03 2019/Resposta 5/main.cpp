#include <iostream>

using namespace std;

int main()
{
    float num1,num2,num3,menor,maior,intermediario;
    cout << "Digite o primeiro numero .\n";
    cin >> num1;
    cout << "Digite o segundo numero .\n";
    cin >> num2;
    cout << "Digite o terceiro numero .\n";
    cin >> num3;
    //----------------------------------TESTE DE NUMERO MENOR
    //Se o primeiro numero for o menor
    if ((num1 < num2) && (num1<num3)){
        menor=num1;
    }
    //Se o segundo numero for o menor
    if ((num2 < num1) && (num2<num3)){
        menor=num2;
    }
    //Se o terceiro numero for o menor
    if ((num3 < num1) && (num3<num2)){
        menor=num3;
    }
    //----------------------------------TESTE DE NUMERO MAIOR
    //Se o primeiro numero for o maior
    if ((num1 > num2) && (num1>num3)){
        maior=num1;
    }
    //Se o segundo numero for o maior
    if ((num2 > num1) && (num2>num3)){
        maior=num2;
    }
    //Se o terceiro numero for o maior
    if ((num3 > num1) && (num3>num2)){
        maior=num3;
    }
    //----------------------------------TESTE DE NUMERO INTERMEDIARIO
    if (((maior == num1) || (menor== num1)) && ((maior == num2) || (menor == num2))){
        intermediario=num3;
    }
    if (((maior == num1) || (menor== num1)) && ((maior == num3) || (menor == num3))){
        intermediario=num2;
    }
    if (((maior == num3) || (menor== num3)) && ((maior == num2) || (menor == num2))){
        intermediario=num1;
    }
    if ((num1!=num2) && (num2!=num3)){
        cout << "O menor numero e : "<<menor<<"\n";
        cout << "O numero intermediario e : "<<intermediario<<"\n";
        cout << "O maior numero e : "<<maior<<"\n";
    } else {
        cout << "Numero(s) invalidos .\n";
    }
    return 0;
}
