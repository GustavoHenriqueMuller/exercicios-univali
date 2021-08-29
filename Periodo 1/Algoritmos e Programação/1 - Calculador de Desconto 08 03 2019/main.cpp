#include <iostream>

using namespace std;

int main()
{
    float valorproduto, valorprodutofinal;
    // Valor padrão de desconto : 10%
    int desconto;
    int idproduto;
    char *produto;
    cout<<"--------------------------------------------------------";
    cout<<"\nDigite o numero respectivo ao produto desejado :\n";
    cout<<"1 - Camisa \n2 - Sapato \n3 - Chapeu\n";
    cout<<"--------------------------------------------------------\n";
    cin>>idproduto;
        if (idproduto == 1){
           produto = "Camisa";
        }
        else if (idproduto == 2){
           produto = "Sapato";
        }
        else if (idproduto == 3){
           produto = "Chapeu";
        }
        else {
            cout<<"--------------------------------------------------------\n";
            cout<<"ERRO : Numero de produto invalido.\n";
            cout<<"--------------------------------------------------------\n";
            return 0;
        }
    cout<<"--------------------------------------------------------";
    cout<<"\nDigite o valor do produto '"<< produto <<"' (R$) .\n";
    cin>>valorproduto;
    cout<<"--------------------------------------------------------";
    cout<<"\nDigite o valor de desconto do produto '"<< produto<<"' (% , de 0% a 100%) .\n";
    cin>>desconto;
    // Checa se o desconto é menor do que 0% ou maior do que 100%
        if (desconto < 0) {
            desconto = 0;
        }
        if (desconto > 100) {
            desconto = 100;
        }
    cout<<"--------------------------------------------------------\n";
    //Faz o calculo de desconto
    valorprodutofinal = valorproduto*((100.0-desconto)/100);
    cout<<"O valor do produto '"<< produto <<"' , com "<< desconto << "% de desconto e : " << valorprodutofinal <<"R$\n";
    cout<<"--------------------------------------------------------";
    return 0;
}
