#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    //VARIAVEIS DO SISTEMA BASICO
    int candidato=1,inscri=0,idade=0;
    char sexo,exp;
    //VARIAVEIS DOS CALCULOS
    int sumfem=0,sumhom=0;
    int bhomemcont=0,bhomemcontidade=0;
    int chomemcont=0;
    int dmulhercont=0;
    int emulheridade=1000;
    int a,b,c,d,e;
    cout <<"Digite -1 para o numero de inscricao para encerrar o processo .\n";
    while (inscri!=-1){
        // SISTEMA BASICO
        cout << "------------------------------------------------------------\nDigite os dados do candidato "<<candidato<<" :\n";
        cout << "NUMERO DE INSCRICAO : ";
        cin>>inscri;
        if (inscri==-1){
            break;
        }
        cout << "IDADE : ";
        cin>>idade;
        cout << "SEXO ( M ou F ) : ";
        cin>>sexo;
        if ((sexo!='M')&&(sexo!='F')){
            break;
        }
        cout << "EXPERIENCIA ( S ou N ) : ";
        cin>>exp;
        if ((exp!='S')&&(exp!='N')){
            break;
        }
        // FAZENDO CALCULOS
        if(sexo=='F'){
            sumfem++;
        } else {
            sumhom++;
        }
        // QUESTAO B
        if((sexo=='M')&&(exp=='S')){
            bhomemcont++;
            bhomemcontidade+=idade;
        }
        // QUESTAO C
        if((sexo=='M')&&(idade>45)){
            chomemcont++;
        }
        // QUESTAO D
        if((sexo=='F')&&(idade<35)&&(exp=='S')){
            dmulhercont++;
        }
        // QUESTAO E
        if((sexo=='F')&&(exp='S')&&(idade<emulheridade)){
            emulheridade=idade;
        }
        candidato++;
    }
    // RESPOSTAS
    a = sumfem;
    b = bhomemcontidade/bhomemcont;
    c = (chomemcont*100.0)/sumhom;
    d = dmulhercont;
    e = emulheridade;
    cout <<"------------------------------------------------------------\n";
    cout <<"Existem "<<a<<" candidatas do sexo feminino .\n";
    cout <<"A idade media dos homens que apresentam experiencia anterior e : "<<b<<" .\n";
    cout <<"A porcentagem dos homens com mais de 45 anos e de : "<<c<<"% .\n";
    cout <<"A quantidade de mulheres com idade inferior a 35 anos e com experiencia anterior e de : "<<d<<" .\n";
    cout <<"Entre as mulheres que ja tem experiencia anterior , a mais nova possui "<<e<<" anos .\n";
    cout <<"------------------------------------------------------------\n";
    return 0;
}
