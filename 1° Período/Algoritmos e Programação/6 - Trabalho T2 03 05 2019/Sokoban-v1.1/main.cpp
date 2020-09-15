/**
    Estrutura inicial para o jogo SOKOBAN feito por Thiago Felski Pereira
    Jogo feito pelos acadêmicos Gustavo Muller e Gustavo Amorim.
    Data inicial: 02/05/2019
    Última atualização: 12/05/2019
*/
#include <iostream>
#include<windows.h>
#include<conio.h>

#define L 18
#define C 30

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
    int x=1, y=1;
    //Variável para tecla precionada
    char tecla;
    //Coordenadas para impressão na tela
    int i,j;
    int c1x=6,c1y=6,c2x=5,c2y=6; //Variaveis das caixas
    int p1x=4,p1y=25,p2x=14,p2y=5; //Variaveis dos pontos
    while(!((((c1x==p1x)&&(c1y==p1y))&&((c2x==p2x)&&(c2y==p2y)))||(((c1x==p2x)&&(c1y==p2y))&&((c2x==p1x)&&(c2y==p1y))))){
        ///Executa os movimentos
         if ( _kbhit() ){
            tecla = getch();
            switch(tecla)
            {
                case 'w': ///cima
                    x--;
                        ///CAIXA 1 - CIMA
                            //Empurrando caixa 1
                            if ((x==c1x)&&(y==c1y)&&(c1x>1)&&((x-1!=c2x)||(y!=c2y))){
                                c1x--;
                            }
                            //Retrocedendo player
                            if ((x==c1x)&&(y==c1y)&&(c1x==1)){
                                x++;
                            }
                            //Colisão entre duas caixas
                            if ((x==c1x)&&(y==c1y)&&(x-1==c2x)&&(y==c2y)){
                                x++;
                            }
                        ///CAIXA 2 - CIMA
                            //Empurrando caixa 2
                            if ((x==c2x)&&(y==c2y)&&(c2x>1)&&((x-1!=c1x)||(y!=c1y))){
                                c2x--;
                            }
                            //Retrocedendo player
                            if ((x==c2x)&&(y==c2y)&&(c2x==1)){
                                x++;
                            }
                            //Colisão entre duas caixas
                            if ((x==c2x)&&(y==c2y)&&(x-1==c1x)&&(y==c1y)){
                                x++;
                            }
                break;
                case 's': ///baixo
                    x++;
                        ///CAIXA 1 - BAIXO
                            //Empurrando caixa 1
                            if ((x==c1x)&&(y==c1y)&&(c1x<L-2)&&((x+1!=c2x)||(y!=c2y))){
                                c1x++;
                            }
                            //Retrocedendo player
                            if ((x==c1x)&&(y==c1y)&&(c1x==L-2)){
                                x--;
                            }
                            //Colisão entre duas caixas
                            if ((x==c1x)&&(y==c1y)&&(x+1==c2x)&&(y==c2y)){
                                x--;
                            }
                        ///CAIXA 2 - BAIXO
                             //Empurrando caixa 2
                            if ((x==c2x)&&(y==c2y)&&(c2x<L-2)&&((x+1!=c1x)||(y!=c1y))){
                                c2x++;
                            }
                            //Retrocedendo player
                            if ((x==c2x)&&(y==c2y)&&(c2x==L-2)){
                                x--;
                            }
                            //Colisão entre duas caixas
                            if ((x==c2x)&&(y==c2y)&&(x+1==c1x)&&(y==c1y)){
                                x--;
                            }
                break;
                case 'a': ///esquerda
                    y--;
                        ///CAIXA 1 - ESQUERDA
                            //Empurrando caixa 1
                            if ((x==c1x)&&(y==c1y)&&(c1y>1)&&((y-1!=c2y)||(x!=c2x))){
                                c1y--;
                            }
                            //Retrocedendo player
                            if ((x==c1x)&&(y==c1y)&&(c1y==1)){
                                y++;
                            }
                            //Colisão entre duas caixas
                            if ((x==c1x)&&(y==c1y)&&(y-1==c2y)&&(x==c2x)){
                                y++;
                            }
                        ///CAIXA 2 - ESQUERDA
                            //Empurrando caixa 2
                            if ((x==c2x)&&(y==c2y)&&(c2y>1)&&((y-1!=c1y)||(x!=c1x))){
                                c2y--;
                            }
                            //Retrocedendo player
                            if ((x==c2x)&&(y==c2y)&&(c2y==1)){
                                y++;
                            }
                            //Colisão entre duas caixas
                            if ((x==c2x)&&(y==c2y)&&(y-1==c1y)&&(x==c1x)){
                                y++;
                            }
                break;
                case 'd': ///direita
                    y++;
                        ///CAIXA 1 - DIREITA
                            //Empurrando caixa 1
                            if ((x==c1x)&&(y==c1y)&&(c1y<C-2)&&((y+1!=c2y)||(x!=c2x))){
                                c1y++;
                            }
                            //Retrocedendo player
                            if ((x==c1x)&&(y==c1y)&&(c1y==C-2)){
                                y--;
                            }
                            //Colisão entre duas caixas
                            if ((x==c1x)&&(y==c1y)&&(y+1==c2y)&&(x==c2x)){
                                y--;
                            }
                        ///CAIXA 2 - DIREITA
                            //Empurrando caixa 2
                            if ((x==c2x)&&(y==c2y)&&(c2y<C-2)&&((y+1!=c1y)||(x!=c1x))){
                                c2y++;
                            }
                            //Retrocedendo player
                            if ((x==c2x)&&(y==c2y)&&(c2y==C-2)){
                                y--;
                            }
                            //Colisão entre duas caixas
                            if ((x==c2x)&&(y==c2y)&&(y+1==c1y)&&(x==c1x)){
                                y--;
                            }
                break;
            }
         }
         //INICIO: COLISOES COM A PAREDE
         if (x<=0){
            x++;
         }
         if (x>=L-1){
            x--;
         }
         if (y<=0){
            y++;
         }
         if (y>=C-1){
            y--;
         }
        //FIM: COLISOES COM A PAREDE
        /*
            Recoloca o mapa no inicio da tela,
            isso faz com que o jogo seja escrito sempre no mesmo lugar.
            se remover essa linha ele fica imprimindo sempre embaixo do mapa anterior
        */
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa , personagem , caixas e pontos finais .
        i=0;
        while (i<L) {
            j=0;
            while (j<C) {
                if (i==x && j==y){
                    cout<<"@"; //visual personagem
                } else if (i==0 || i==L-1 || j==0 || j==C-1){
                    cout<<char(178); //visual paredes
                } else if ((i==c1x)&&(j==c1y)){
                    cout<<char(254); //visual caixa 1
                } else if ((i==c2x)&&(j==c2y)){
                    cout<<char(254); //visual caixa 2
                } else if ((i==p1x)&&(j==p1y)){
                    cout<<char(248); //visual ponto final 1
                } else if ((i==p2x)&&(j==p2y)){
                    cout<<char(248); //visual ponto final 2
                } else {
                    cout<<" ";
                }
                j++;
            }
        cout<<"\n";
        i++;
        }
    }
    //Exibe a mensagem de vitória
    cout <<"\n==============================\nV I T O R I A \n==============================\n";
    return 0;
}
