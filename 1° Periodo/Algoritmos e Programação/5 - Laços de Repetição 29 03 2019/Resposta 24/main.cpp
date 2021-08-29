#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    // Programado por Gustavo Muller
    int valor;
    //FATORIAL
    int factdivisor=1;
    long int factsoma=1;
    //FIBONACCI
    bool pertencefibo=false;
    int nfibonacci=0,valorfibo=0;
    int t1=0,t2=1;
    //QUANTIDADE TOTAL
    int qnt=1;
    //QUANTIDADE IMPAR
    int qntimpar=0;
    cout <<"Digite 0 para acabar com a sequencia .\n";
    while(valor!=0){
        cout <<"-----------------------------\nDigite o "<<qnt<<" numero : \n";
        cin >> valor;
        //FAZER FATORIAL
        while(factdivisor<=valor){
            factsoma*=factdivisor;
            factdivisor++;
        }
        cout <<"O fatorial de "<<valor<<" e "<<factsoma<<" .\n";
        //FAZER FIBONACCI
        while((nfibonacci<valor)&&(valorfibo!=valor)){
            valorfibo=t1+t2;
            t1=t2;
            t2=valorfibo;
            if(valorfibo==valor){
                pertencefibo=true;
                break;
            }
            nfibonacci++;
        }
        if (pertencefibo==true){
            cout <<"O "<<valor<<" pertence a Serie de Fibonnaci .\n";
        } else {
            cout <<"O "<<valor<<" nao pertence a Serie de Fibonnaci .\n";
        }
        //FAZER TESTE ÍMPAR
        if ((valor%2)!=0){
            qntimpar++;
        }
        qnt++;
    }
    //FAZER QUANTIDADE DE NUMEROS DIGITADOS
    cout <<"-----------------------------\nForam digitados "<<qnt<<" numeros .\n";
    cout <<"A porcentagem de numeros impares e "<< ((qntimpar*100)/qnt) <<"% . \n";
    return 0;
}
