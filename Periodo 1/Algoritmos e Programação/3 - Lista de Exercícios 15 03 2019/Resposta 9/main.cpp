#include <iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main()
{
    int a,b,c;
    int delta;
    float x1,x2;
    cout << "Digite os valores de A , B e C da equacao de segundo grau , respectivamente : \n";
    cin >> a>>b>>c;
    if (a!=0){
        delta = (b*b)-(4*a*c);
        if (delta>=1){
            x1 = ((-b + sqrt(delta))/(2.0*a));
            x2 = ((-b - sqrt(delta))/(2.0*a));
        cout<<"x1 = "<<x1<<"\n";
        cout<<"x2 = "<<x2<<"\n";
        } else if (delta==0){
            x1 = (-b)/(2.0*a);
            x2 = (-b)/(2.0*a);
        cout<<"x1 = "<<x1<<"\n";
        cout<<"x2 = "<<x2<<"\n";
        } else {
            cout <<"Valor de Delta invalido .";
        }
    } else {
        cout <<"Valor de A invalido .";
    }
    return 0;
}
