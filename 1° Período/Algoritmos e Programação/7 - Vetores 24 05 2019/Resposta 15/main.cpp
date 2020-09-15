#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int val[30];
    int cont=0;
    int num=333;
    int contprime=num;
    cout << "Os primeiros 30 numeros primos apos 333 sao : \n";
    while(cont<30){
        contprime=1;
        while(contprime<=num){
            ///Se contprime chegou no num , num e primo
            if(contprime==num){
                val[cont]=num;
                cont++;
            }
            ///Se o resto da divisao de num por contprime e 0 e contprime nao e 1 ou ou num , o numero nao e primo
            if((num%contprime==0)&&(contprime!=1)&&(contprime!=num)){
                goto nextnumber;
            }
            contprime++;
        }
        nextnumber:
        num++;
    }
    ///Printando vetor na tela
    cont=0;
    while(cont<30){
        cout<<"["<<val[cont]<<"] ";
        cont++;
    }
    return 0;
}
