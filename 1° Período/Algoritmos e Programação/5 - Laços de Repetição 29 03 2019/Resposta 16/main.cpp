#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	//Programado por Gustavo Muller
    char nome [15];
    char nomemaior [15];
    int aluno,prova,contprova=1;
    float nota,notatotal=0,media=0;
    int cont=1;
    int maiormedia=0;
    cout<<"Digite o numero de alunos :\n";
    cin>>aluno;
    cout<<"Digite o numero de provas realizadas :\n";
    cin>>prova;
    cout<<"---------------------------------------------\n";
    while (cont<=aluno){
        contprova=1;
        notatotal=0;
        media=0;
        cout<<"Nome do aluno : ";
        cin>>nome;
            while (contprova<=prova){
                 cout<<"Nota na prova "<<contprova<<" : ";
                 cin>>nota;
                 notatotal+=nota;
                 contprova++;
            }
        media=notatotal/prova;
        if (media>maiormedia){
            maiormedia=media;
            strcpy(nomemaior,nome);
        }
        cout<<"---------------------------------------------\n";
        cout<<nome<<" | MEDIA "<<media<<"\n";
        cout<<"---------------------------------------------\n";
        cont++;
    }
        cout<<"---------------------------------------------\n";
        cout<<"O aluno com maior media e :\n";
        cout<<nomemaior<<" | MEDIA "<<maiormedia<<"\n";
        cout<<"---------------------------------------------\n";
    return 0;
}
