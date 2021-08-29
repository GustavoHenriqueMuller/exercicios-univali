#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int val=101,cont=1,divisor=1, p=1;
    cout << "Os 20 primeiros numeros primos apos o 100 sao : \n";
    while(cont<=20){
        while (divisor<val){
            if ((val%divisor==0)&&(divisor!=val)&&(divisor!=1)){
                p=0;
                break;
            }
            divisor++;
        }
        if(p==1){
            cout<<cont<<": "<<val<<"\n";
            cont++;
        }
        p=1;
        divisor=1;
        val++;
    }
    return 0;
    }
