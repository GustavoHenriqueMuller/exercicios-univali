#include <iostream>

using namespace std;

float calcular(float altura,float peso){
    return (peso)/(altura*altura);
}

string mostrartipo(float imc){
    string tipo;
    if(imc<10){
        tipo="Desnutricao Grau V";
    } else if ((imc>=10) and (imc<=12.9)){
        tipo="Desnutricao Grau IV";
    } else if ((imc>=13) and (imc<=15.9)){
        tipo="Desnutricao Grau III";
    } else if ((imc>=16) and (imc<=16.9)){
        tipo="Desnutricao Grau II";
    } else if ((imc>=17) and (imc<=18.4)){
        tipo="Desnutricao Grau I";
    } else if ((imc>18.5) and (imc<=24.9)){
        tipo="Normal";
    } else if ((imc>=25) and (imc<=29.9)){
        tipo="Pre-Obesidade";
    } else if ((imc>=30) and (imc<=34.5)){
        tipo="Obesidade Grau I";
    } else if ((imc>=35) and (imc<=39.9)){
        tipo="Obesidade Grau II";
    } else {
        tipo="Obesidade Grau III";
    }
    return tipo;
}

int main()
{
    float altura,peso;
    cout<<"Digite sua altura (m) :\n";
        cin>>altura;
    cout<<"\nDigite seu peso (kg) :\n";
        cin>>peso;
    cout<<"\nO seu IMC e : "<< calcular(altura,peso) <<" ("<< mostrartipo(calcular(altura,peso)) <<").\n";
    return 0;
}
