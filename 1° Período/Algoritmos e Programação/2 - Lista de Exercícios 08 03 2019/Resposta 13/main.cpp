#include <iostream>

using namespace std;

int main()
{
    int saque;
    int cedula1 = 0;
    int cedula5 = 0;
    int cedula10 = 0;
    cout <<"--------------------------------------------------------------\n";
    cout <<"Indique o valor do saque :\n";
    cin>>saque;
    if(saque<1){
        cout<<"Valor invalido . Nenhuma cedula foi utilizada na transacao.\n";
        cout <<"--------------------------------------------------------------\n";
        return 0;
    }
    if((saque>=1) && (saque<5)){
            cedula1 = saque;
            cout <<"--------------------------------------------------------------\n";
            cout<<"Foram usadas :\n"<<cedula10<<" cedula(s) de 10R$\n"<<cedula5<<" cedula(s) de 5R$\n"<<cedula1<<" cedula(s) de 1R$\n";
            cout <<"--------------------------------------------------------------\n";
            return 0;
    }
    if((saque>=5) && (saque<10)){
            cedula5 = ((saque-(saque%5))/5);
            cedula1 = saque%5;
            cout <<"--------------------------------------------------------------\n";
            cout<<"Foram usadas :\n"<<cedula10<<" cedula(s) de 10R$\n"<<cedula5<<" cedula(s) de 5R$\n"<<cedula1<<" cedula(s) de 1R$\n";
            cout <<"--------------------------------------------------------------\n";
            return 0;
    }
    if((saque>=10)){
            cedula10 = ((saque-(saque%10))/10);
            cedula5 = ((saque-(cedula10*10))/5);
            cedula1 = (saque-(cedula10*10)-(cedula5*5));
            cout <<"--------------------------------------------------------------\n";
            cout<<"Foram usadas :\n"<<cedula10<<" cedula(s) de 10R$\n"<<cedula5<<" cedula(s) de 5R$\n"<<cedula1<<" cedula(s) de 1R$\n";
            cout <<"--------------------------------------------------------------\n";
            return 0;
    }
    return 0;
}
