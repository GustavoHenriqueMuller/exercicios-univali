/**
    Estrutura inicial para o jogo SOKOBAN feito por Thiago Felski Pereira
    Jogo feito pelos acadêmicos Gustavo Muller e Gustavo Amorim.
    Data inicial: 02/05/2019
    Última atualização: 06/05/2019
*/
#include <iostream>
#include<windows.h>
#include<conio.h>

#define L 30
#define C 60

using namespace std;

int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
        //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
        //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
        //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
        short int CX=0, CY=0;
        COORD coord;
        coord.X = CX;
        coord.Y = CY;
        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


    //Posição inicial do personagem no console
    int x=3, y=3;
    //Variável para tecla precionada
    char tecla;
    //Coordenadas para impressão na tela
    int i,j;
    while(1){
        ///Imprime o jogo: mapa e personagem.
        i=0;
        while (i<L) {
            j=0;
            while (j<C) {
                if (i==x and j==y){
                    cout<<"@";
                } else if (i==0 or i==L-1 or j==0 or j==C-1){
                    cout<<"°";
                } else {
                    cout<<" ";
                }
                j++;
            }
        cout<<"\n";
        i++;
        }
        ///executa os movimentos
         if ( _kbhit() ){
            tecla = getch();
            switch(tecla)
            {
                case 'w': ///cima
                    x--;
                break;
                case 's': ///baixo
                    x++;
                break;
                case 'a': ///esquerda
                    y--;
                break;
                case 'd': ///direita
                    y++;
                break;
            }
         }

        /*
            Recoloca o mapa no inicio da tela,
            isso faz com que o jogo seja escrito sempre no mesmo lugar.
            se remover essa linha ele fica imprimindo sempre embaixo do mapa anterior
        */
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    return 0;
}
