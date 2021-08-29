#include <iostream>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    int corretor,contcorretor=1;
    float salario,venda,total=0,totalsalario=0;
    cout<<"Digite o numero de corretores : \n";
    cin>>corretor;
    while(contcorretor<=corretor){
        cout<<"----------------------------------------\n";
        cout<<"Digite o valor das vendas do corretor "<<contcorretor<<".\n";
        cin>>venda;
        if (venda>3000){
            salario = venda*0.35;
        } else if ((venda>=1500)&&(venda<=3000)){
            salario = venda*0.2;
        } else if (venda<1500){
            salario = venda*0.13;
        }
        cout<<"Salario do corretor "<<contcorretor<<" : "<<salario<<"R$.\n";
        totalsalario+=salario;
        total+=venda;
        contcorretor++;
    }
        cout<<"----------------------------------------\n";
        cout<<"Lucro bruto : "<<total<<"R$.\n";
        cout<<"Salarios : "<<totalsalario<<"R$.\n";
        cout<<"Lucro liquido : "<<total-totalsalario<<"R$.\n";
    return 0;
}
