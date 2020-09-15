
#include <iostream>

using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool validarCpf(string cpf){
    //Testa se o CPF tem 11 digitos
        if(cpf.size() != 11){
            cout<<"O CPF '"<<cpf<<"' e invalido \n(ERRO : Numero invalido de digitos.)\n";
            return false;
        }
    //Testa se o CPF possui todos os dígitos iguais
         int num=((int)cpf[0])-48;
         for(int i=0;i<(cpf.size());i++){
            if(num!=((int)cpf[i])-48){
                break;
            }
            if(i==cpf.size()-1){
                cout<<"O CPF '"<<cpf<<"' e invalido \n(ERRO : Todos os 11 digitos sao iguais.)\n";
                return false;
            }
         }
    //Verificacao do primeiro digito
        long int sum=0;
            for(int i=0 ; i < (cpf.size()-2) ; i++){
                sum += (((int)cpf[i])-48) * (10-i);
            }
        sum=(sum*10)%11;
        if(sum != ((int)cpf[9])-48){
            cout<<"O CPF '"<<cpf<<"' e invalido \n(ERRO : Primeiro digito verificador.)\n";
            return false;
        }
    //Verificacao do segundo digito
        sum=0;
            for(int i=0 ; i < (cpf.size()-1) ; i++){
                sum += (((int)cpf[i])-48) * (11-i);
            }
        sum=(sum*10)%11;
        if(sum != ((int)cpf[10])-48){
            cout<<"O CPF '"<<cpf<<"' e invalido \n(ERRO : Segundo digito verificador.)\n";
            return false;
        }
        cout<<"O CPF '"<<cpf<<"' e valido .\n";
        return true;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void barra(){
    cout<<"=======================================================\n";
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
    string cpf;
    barra();
        cout<<"Digite 11 digitos numericos (CPF) : \n";
        cin>>cpf;
    barra();
        validarCpf(cpf);
    barra();

}
