#include <iostream>

using namespace std;

int main()
{
    int unsigned ano;
    bool regra1=false;
    bool regra2=false;
    bool regra3=false;
    bool bissexto=false;
    cout << "Solicite um ano. \n";
    cin>>ano;
    //TERCEIRA REGRA
    if((ano%400)==0){
        regra3=true;
    }
    //SEGUNDA REGRA
    if(((ano%100)==0)&&(regra3==false)){
        regra2=true;
    }
    //PRIMEIRA REGRA
    if (((ano%4)==0)&&(regra2==false)&&(regra3==false)){
        regra1=true;
    }
    //TESTANDO SE E BISSEXTO OU NAO
    if (regra1==true){
        bissexto=true;
    }
    if (regra2==true){
        bissexto=false;
    }
    if (regra3==true){
        bissexto=true;
    }
    //ESCREVENDO SE E BISSEXTO OU NAO
    if (bissexto==true){
        cout<<"O ano de "<<ano<<" e bissexto.\n";
    } else {
        cout<<"O ano de "<<ano<<" nao e bissexto.\n";
    }
    return 0;
}
