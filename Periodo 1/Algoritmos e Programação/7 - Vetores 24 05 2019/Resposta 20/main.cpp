#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int vetor[21],cont=0,repeat=0,meio,chave;
    ///Gera numeros aleatorios nos vetores de 1 a 100
    srand (time(NULL));
    ///Adicionando valores aleatorios no vetor
        while(cont<21){
            vetor[cont]=rand()%100+1;
            //Checar por numero repetido no primeiro vetor
            repeat=0;
                while(repeat<=cont){
                    if(repeat==cont){
                        goto nextnumber;
                    }
                    if(vetor[cont]==vetor[repeat]){
                        vetor[cont]++;
                        repeat=-1;
                    }
                    repeat++;
                }
            nextnumber:
            cont++;
        }
    ///Ordenando e setando valor do meio
    sort(vetor,vetor+21);
    meio=vetor[10];
    cont=0;
    while(cont<21){
        cout<<"["<<vetor[cont]<<"] ";
        cont++;
    }
    ///Pedindo e procurando por chave
    cout<<"\n\nDigite a chave .\n";
    cin>>chave;
    if(chave==meio){
        cout<<"\nO valor "<<chave<<" existe no vetor (indice 10).\n";
    }
    if(chave<meio){
        ///Intervalo fechado => 0 à 9
        cont=0;
        while(cont<10){
            if(chave==vetor[cont]){
                cout<<"\nO valor "<<chave<<" existe no vetor (indice "<<cont<<").\n";
                break;
            }
            if(cont==9){
                cout<<"\nO valor "<<chave<<" nao existe no vetor.\n";
            }
        cont++;
        }
    }
    if(chave>meio){
        ///Intervalo fechado => 11 à 20
        cont=11;
        while(cont<21){
            if(chave==vetor[cont]){
                cout<<"\nO valor "<<chave<<" existe no vetor (indice "<<cont<<").\n";
                break;
            }
            if(cont==20){
                cout<<"\nO valor "<<chave<<" nao existe no vetor.\n";
            }
        cont++;
        }
    }
    return 0;
}
