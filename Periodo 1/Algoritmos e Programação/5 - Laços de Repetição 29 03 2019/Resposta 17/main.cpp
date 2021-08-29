#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int num1,num2;
    //VARIAVEIS PARA A ETAPA 1
    int cont,soma=0;
    int maior=1;
    //VARIAVEIS PARA A ETAPA 2
    int mult=1;
    cout<<"Digite dois numeros diferentes :\n";
    cin>>num1>>num2;
    //ETAPA 1
    cout<<"-------------------------------------------------------------------------------------------\n";
    cout<<"A soma dos numeros pares do intervalo fechado dos numeros "<<num1<<" e "<<num2<<" e igual a :\n";
    if (num1%2==0){
        soma+=num1;
    }
    if (num2%2==0){
        soma+=num2;
    }
    if (num1<=num2){
        cont=num1+1;
        maior = num2;
    } else {
        cont = num2+1;
        maior = num1;
    }
    while (cont<=(maior-1)){
        if (cont%2==0){
            soma+=cont;
        }
        cont++;
    }
    cout<<soma;
    //ETAPA 2
    cout<<"\n-------------------------------------------------------------------------------------------\n";
    cout<<"A multiplicacao dos numeros impares do intervalo fechado dos numeros "<<num1<<" e "<<num2<<" e igual a :\n";
    if (num1<=num2){
        cont=num1+1;
        maior = num2;
    } else {
        cont = num2+1;
        maior = num1;
    }
    if (num1%2!=0){
        mult*=num1;
    }
    if (num2%2!=0){
        mult*=num2;
    }
    while (cont<=(maior-1)){
        if (cont%2!=0){
            mult*=cont;
        }
        cont++;
    }
    cout<<mult;
    return 0;
}
