#include <iostream>

using namespace std;

int main()
{
    int empregados , bicicletasvendidas;
    float salariominimo , custobicicleta , precobicicleta;
    cout << "Insira o numero de empregados da loja : \n";
    cin >> empregados;
    cout << "Insira o valor do salario minimo : \n";
    cin >> salariominimo;
    cout << "Insira o custo de cada bicicleta : \n";
    cin >> custobicicleta;
    cout << "Insira o numero de bicicletas vendidas : \n";
    cin >> bicicletasvendidas;
    cout <<"------------------------------------------------------------\n";
    cout <<"Salario final de cada empregado : " << ((salariominimo*2)+ ((0.15*custobicicleta*bicicletasvendidas)/empregados)) << "\n";
    cout <<"Lucro liquido da loja : " << custobicicleta*bicicletasvendidas - ((salariominimo*2)+ ((0.15*custobicicleta*bicicletasvendidas)/empregados));
    return 0;
}
