#include <iostream>

using namespace std;

int main()
{
    float diaria;
    float multdiaria;
    cout << "Seja bem vindo ao Hotel C++ ! Quantas diarias voce deseja ?\n";
    cin>>diaria;
    if (diaria>10.0){
        multdiaria=4.0;
    }
    if (diaria==10.0){
        multdiaria=5.0;
    }
    if (diaria<10.0){
        multdiaria=8.5;
    }
    cout <<"Preco de diaria : "<<diaria*50<<"R$\n";
    cout <<"Preco de taxa de servico : "<<multdiaria*diaria<<"R$\n";
    cout <<"------------------------------------------------\n";
    cout<<"Preco total : "<<(diaria*50)+(multdiaria*diaria)<<"R$\n";
    return 0;
}
