#include <iostream>

using namespace std;

int main()
{
    //PS : A VARIAVEL TEMPODIF GUARDA A DIFERENCA DO TEMPO EM DIAS
    int tempodif,tempodia,tempomes,tempoano;
    int dia,mes,ano;
    int udia,umes,uano;
    //INSERINDO DATA ATUAL
    cout << "Indique o dia , mes , e ano ATUAL (respectivamente)." << endl;
    cin >> dia>>mes>>ano;
    if ((dia >= 1) && (dia<=31) && (mes>=1) && (mes<=12)){
        //INSERINDO DATA DE NASCIMENTO
        cout << "Indique o dia , mes , e ano do seu NASCIMENTO (respectivamente)." << endl;
        cin >> udia>>umes>>uano;
        if ((udia >= 1) && (udia<=31) && (umes>=1) && (umes<=12)){
            //FAZENDO CALCULO DE TEMPO
            tempodif = (((mes-1)*30 + dia) + (365-((umes-1)*30 + udia))) + ((ano-uano-1)*365);
            tempoano = tempodif/365;
            tempomes = ((tempodif%365)/30);
            tempodia = (((tempodif%365)%30));
            cout<<"\n"<<tempodif<<" "<<tempoano<<" "<<tempomes<<" "<<tempodia<<" "<<"\n";
            cout<<"Voce esta vivo ha (aproximadamente) : "<<tempoano<<" ano(s) , "<<tempomes<<" mes(es) , "<<tempodia<<" dia(s).\n";
        } else {
            cout <<"Data(s) de nascimento invalida(s).\n";
            return 0;
        }

    } else {
        cout <<"Data(s) atuais invalida(s).\n";
        return 0;
    }

    return 0;
}
