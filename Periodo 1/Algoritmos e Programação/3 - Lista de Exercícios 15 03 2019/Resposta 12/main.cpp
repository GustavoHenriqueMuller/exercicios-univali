#include <iostream>

using namespace std;

int main()
{
    int dia,mes,ano;
    //REGRAS DE ANO BISSEXTO
        bool regra1=false;
        bool regra2=false;
        bool regra3=false;
        bool bissexto=false;
    cout << "Digite o valor (em numero) de um dia , mes e ano (respectivamente)\n";
    cin>>dia>>mes>>ano;
    //VERIFICACAO GENERICA
    if ((dia>=1)&&(mes>=1)&&(mes<=12)&&(ano>=1)){
        //VERIFICACAO DE ANO BISSEXTO
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
        //VERIFICACAO DE DIAS NO MES
            //FEVEREIRO
            if ((dia>28)&&(mes==2)&&(bissexto==false)){
                cout<<"Dia invalido.\n";
                return 0;
            //MESES COM 31 DIAS (1,3,5,7,8,10,12)
            } else if ((dia>29)&&(mes==2)&&(bissexto==true)){
                cout<<"Dia invalido.\n";
                return 0;
            } else if ((dia>31)&&((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12))){
                cout<<"Dia invalido.\n";
                return 0;
            //MESES COM 30 DIAS (4,6,9,11)
            } else if ((dia>30)&&((mes==4)||(mes==6)||(mes==9)||(mes==11))){
                cout<<"Dia invalido.\n";
                return 0;
            } else {
                cout<<"O dia "<<dia<<", do mes "<<mes<<", do ano "<<ano<<" existe .\n";
            }
    } else {
    cout<<"Valor(es) invalidos.\n";
    return 0;
    }
    return 0;
}
