#include <iostream>

using namespace std;

int main()
{
    //Programado por Gustavo Muller
    int x,n;
    float somacima=1;
    int termo=1;
    float e=0;
    //FATORIAL
    float contfact=1,factbaixo=2,factsoma=1;
    cout << "---------------------------------------------------------------\n";
    cout << "Digite um valor de X e N , respectivamente , para a equacao : \n";
    cout << "\nE = X+1 - X+2 + X+3 -           X + N ";
    cout << "\n    ---   ---   ---   ... (+/-) ------";
    cout << "\n     2!    3!    4!             (N+1)!";
    cout << "\n---------------------------------------------------------------\n";
    cin>>x>>n;
    do{
        //ACHAR VALOR FATORIAL
        while(contfact<=factbaixo){
            factsoma*=contfact;
            contfact++;
        }
        //ACHAR SINAL DO TERMO
        if ((termo%2)==0){
            e -= ((x+somacima)/factsoma);
        }else{
            e += ((x+somacima)/factsoma);
        }
    somacima++;
    termo++;
    factbaixo++;
    }while (somacima<=n);
    cout<<"\n"<<e;
    return 0;
}
