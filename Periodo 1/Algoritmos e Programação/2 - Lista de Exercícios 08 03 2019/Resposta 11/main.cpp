#include <iostream>

using namespace std;

int main()
{
    float creprovados , dreprovados , totalreprovados;
    int c = 60;
    int d = 20;
    cout << "Insira a porcentagem de alunos reprovados na turma C ( 60 alunos )\n";
    cin >> creprovados;
    cout << "Insira a porcentagem de alunos reprovados na turma D ( 20 alunos )\n";
    cin >> dreprovados;
    cout << "Numero de alunos reprovados na sala C : " << c*(creprovados/100) << "\n";
    cout << "Numero de alunos reprovados na sala D : " << d*(dreprovados/100) << "\n";
    totalreprovados = ((c*(creprovados/100) + d*(dreprovados/100))*100)/80;
    cout << "Porcentagem de alunos em relacao as duas salas : " << totalreprovados << "%";
    return 0;
}
