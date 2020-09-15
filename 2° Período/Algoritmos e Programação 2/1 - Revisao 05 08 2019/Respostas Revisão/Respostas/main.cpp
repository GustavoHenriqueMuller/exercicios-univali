#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
    //RESPOSTA 1
    int Resposta1(){
        float salario;
        float credito;
        cout<<"Digite o seu salario medio (R$) :\n";
        cin >> salario;
        if(salario>=0.0){
            if(salario<=200.0){
                credito=0;
            } else if ((salario>200.0)and(salario<=400.0)){
                credito=salario*0.2;
            } else if ((salario>400.0)and(salario<=600.0)){
                credito=salario*0.3;
            } else {
                credito=salario*0.4;
            }
            cout<<"\nO valor do credito, de um saldo medio de "<<salario<<"R$ e : "<<credito<<"R$.\n";
        } else {
            cout<<"Esse salario nao e valido.\n";
        }
        return 0;
    }
    //RESPOSTA 2
    int Resposta2(){
        float altura;
            int peso;
            char sexo;
            cout << "Digite a sua altura (metros) :\n";
                cin>>altura;
            cout << "Digite o seu sexo (H para Homem , M para Mulher)\n";
                cin>>sexo;
            if((sexo!='H')and(sexo!='M')){
                cout<<"O sexo digitado nao e valido.\n";
                return 0;
            } else if(sexo=='H') {
                peso=((72.7*altura)-58.0);
                cout<<"O peso ideal e : "<<peso<<"kg.\n";
            } else {
                peso=((62.1*altura)-44.7);
                cout<<"O peso ideal e : "<<peso<<"kg.\n";
            }
        return 0;
    }
    //RESPOSTA 3
    int Resposta3(){
        string frase;
        string fraserevertida;
        cout<<"Digite uma frase :\n";
        cin>>frase;
        fraserevertida=frase;
        reverse(fraserevertida.begin(),fraserevertida.end());
        if(frase==fraserevertida){
            cout<<"\nA frase digitada e um palindromo.\n";
        } else {
            cout<<"\nA frase digitada nao e um palindromo.\n";
        }
        return 0;
    }
//MAIN
int main()
{
    cout<<"============================================================\n";
    Resposta1();
    cout<<"============================================================\n";
    return 0;
}
