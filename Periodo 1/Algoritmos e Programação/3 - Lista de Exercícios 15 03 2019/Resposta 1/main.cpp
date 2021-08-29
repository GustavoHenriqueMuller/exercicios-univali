#include <iostream>

using namespace std;

int main()
{
    //VALORES DA ADICAO
    int val,num,sum = 0;
    //VALORES DA MULTIPLICACAO
    int num2,pro = 1;
    int subtracao;
    int digitoverificador;
    cout << "Digite o numero da conta (4 digitos) : \n";
    cin>>val;
    if (val>9999){
        cout<<"Numero muito alto . Favor inserir numero de 4 digitos.";
        return 0;
    }
    if (val<1000){
        cout<<"Numero muito baixo . Favor inserir numero de 4 digitos.";
        return 0;
    }
    //FAZENDO SOMA DOS 4 NUMEROS
    num = val;
    num2 = val;
    while (num != 0)
    {
        sum = sum + num % 10;
        num = num / 10;
    }
    //FAZENDO MULTIPLICACAO DOS 4 DIGITOS
    while(num2!=0)
    {
        pro=pro*(num2%10);
        num2=num2/10;
    }
    subtracao = pro-sum;
    digitoverificador = (subtracao%9);
    cout<<"O seu digito verificador e : "<< digitoverificador;
    return 0;
}
