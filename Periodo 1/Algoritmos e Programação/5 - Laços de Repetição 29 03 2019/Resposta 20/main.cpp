#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    //VARIAVEIS
    int n;
    float num=2,den=1.0,contden=1;
    float soma=1.0;
    //ACHAR FATORIAL
    int contfac=1;
    cout<<"Digite um valor de N para a seguinte equacao : \n";
    cout<<"S = 1 + 2/1! + 3/2! + 4/3! + ... + N+1/N!\n";
    cin>>n;
    //EQUACAO PRINCIPAL
    while (num<=(n+1)){
        contfac=1;
        den=1.0;
        while (contfac<=contden){
            den*=contfac;
            contfac++;
        }
        soma+=num/den;
        num++;
        contden++;
    }
    cout<<"O valor de S e : "<<soma<<" . \n";
    return 0;
}
