#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    float num1,num2,resultado;
    int operacao;
    cout << "OBS : Insira dois 0's para encerrar os calculos .\n";
    while ((num1!=0)&&(num2!=0)){
        cout << "------------------------------------------\nInsira o primeiro operando . \n";
        cin>>num1;
        cout << "------------------------------------------\nInsira o segundo operando . \n";
        cin>>num2;
        if((num1==0)&&(num2==0)){
           break;
        }
        cout << "------------------------------------------\nIndique a operacao : \n1 - Soma\n2 - Produto\n3 - Divisao\n4 - Potenciacao\n";
        cin>>operacao;
        if (operacao==1){
            resultado = num1+num2;
            cout <<"------------------------------------------\n"<< num1 <<" + "<< num2 << " = " << resultado<<"\n";
        } else if (operacao==2){
            resultado = num1*num2;
            cout <<"------------------------------------------\n"<< num1 <<"*"<< num2 << " = " << resultado<<"\n";
        } else if (operacao==3){
            resultado = num1/num2;
            cout <<"------------------------------------------\n"<< num1 <<"/"<< num2 << " = " << resultado<<"\n";
        } else if (operacao==4){
            resultado = pow(num1,num2);
            cout <<"------------------------------------------\n"<< num1 <<" elevado a "<< num2 << " = " << resultado<<"\n";
        } else {
            cout<<"------------------------------------------\nNumero de operacao invalido .\n";
            break;
        }
    }
    cout<<"------------------------------------------\nFim de calculos .\n";
    return 0;
}
