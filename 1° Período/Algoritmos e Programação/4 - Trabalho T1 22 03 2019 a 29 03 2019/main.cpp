#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <sstream>

using namespace std;

int main()
{
    //DECLARACAO DE VARIAVEIS
    long int val;
    int d1,d2,d3,d4,d5,d6,d7,d8,d9;
    int soma1,resto1;
    int soma2,resto2;
    int dv1,dv2;
    cout<<"Digite um valor inteiro de 9 digitos (CPF) : \n\n";
    cin>>val;
    //CODIGO GERAL
        //EXTRAÇÃO DIGITOS
        if ((val>=10000000)&&(val<=99999999) || (val>=100000000)&&(val<=999999999)){
            d1=(val/(100000000))%10;
            d2=(val/(10000000))%10;
            d3=(val/(1000000))%10;
            d4=(val/(100000))%10;
            d5=(val/(10000))%10;
            d6=(val/(1000))%10;
            d7=(val/(100))%10;
            d8=(val/(10))%10;
            d9=(val%10);
            //ACHAR PRIMEIRO DIGITO VERIFICADOR
            soma1 = (d1*10)+(d2*9)+(d3*8)+(d4*7)+(d5*6)+(d6*5)+(d7*4)+(d8*3)+(d9*2);
            resto1 = soma1%11;
            if (resto1<2){
                dv1=0;
            } else {
                dv1=(11-resto1);
            }
            //ACHAR SEGUNDO DIGITO VERIFICADOR
            soma2 = (d1*11)+(d2*10)+(d3*9)+(d4*8)+(d5*7)+(d6*6)+(d7*5)+(d8*4)+(d9*3)+(dv1*2);
            resto2 = soma2%11;
            if (resto2<2){
                dv2=0;
            } else {
                dv2=(11-resto2);
            }
            //ESCREVER CPF INTEIRO
            cout<<"\nO seu CPF e : "<<d1<<""<<d2<<""<<d3<<"."<<d4<<""<<d5<<""<<d6<<"."<<d7<<""<<d8<<""<<d9<<"-"<<dv1<<""<<dv2<<".\n";
        //CASO MENOR QUE 8 DIGITOS OU MAIOR QUE 9
        } else {
            cout<<"\nNumero de digitos invalido .\n";
        }
    return 0;
}
