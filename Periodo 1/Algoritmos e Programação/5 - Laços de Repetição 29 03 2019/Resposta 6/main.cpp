#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int num=1,cont=1;
    cout << "As tabuadas dos numeros de 1 a 10 , de 1 a 10 e :\n";
    cout<<"------------------------TABUADA DO 1 ------------------------\n";
    repetir:
    while ((cont<=10)&&(num<=10)){
        cout<<num*cont<<"\n";
        cont++;
    }
    if((cont>10)&&(num<10)){
        cont=1;
        num++;
        cout<<"------------------------TABUADA DO "<<num<<" ------------------------\n";
        goto repetir;
    }
    return 0;
}
