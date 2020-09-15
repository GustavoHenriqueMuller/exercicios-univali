#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int val[10],num;
    int cont=0;
    ///Declarando valores do vetor pelo usuari
    while(cont<10){
        cout<<"["<<cont<<"] = ";
        cin>>num;
        val[cont]=num;
        cont++;
    }
    ///Ordenando o vetor do menor para maior
    sort(val,val+10);
    ///Printando vetor ordenado
    cont=0;
    cout<<"\n";
    while(cont<10){
        cout<<"["<<val[cont]<<"] ";
        cont++;
    }
    cont=0;
    ///Fazendo comparacao entre valores do vetor
    int prop=(val[cont]+val[9-cont]);
    while((cont<5)&&((val[cont]+val[9-cont])==prop)){
        if(cont==4){
            cout<<"\nA sequencia e equivalente.\n";
        }
        cont++;
    }
    if((val[cont]+val[9-cont])!=prop){
        cout<<"\nA sequencia nao e equivalente.\n";
    }
    return 0;
}
