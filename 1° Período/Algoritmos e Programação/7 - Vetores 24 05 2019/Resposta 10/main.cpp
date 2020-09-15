#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor[5],qnt=0,cont=0;
    vetor[0]=45;
    vetor[1]=7;
    vetor[2]=32;
    vetor[3]=7;
    vetor[4]=21;
    while(cont<5){
        if(vetor[cont]==7){
            cout<<"O valor de indice "<<cont<<" e 7.\n";
            qnt++;
        }
        cont++;
    }
    cout<<"O numero 7 foi encontrado "<<qnt<<" vezes.\n";
    return 0;
}
