#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main() {
    ///NOTAS
        //Player 1 = X(1)
        //Player 2 = O(2)

    const int lin=3;
    const int col=3;

    int x,y;

    int jogo[lin][col]={(0,0,0),
                        (0,0,0),
                        (0,0,0)};
    int player=1;
    int alguemjogou=0;
    int elementosvazios=9;

    bool isplaying=1;

    //JOGO MAIN
    while(isplaying==1){
        system("cls");
        alguemjogou=0;
        elementosvazios=9;
        cout << "=============================\nJOGO DA VELHA\n=============================\n\n";
        ///PRINTA O JOGO
        for(int i=0;i<lin;i++){
            for(int j=0;j<col;j++){
                if(jogo[i][j]==0){
                    cout<<"[ ] ";
                } else if(jogo[i][j]==1){
                    cout<<"[X] ";
                } else if(jogo[i][j]==2){
                    cout<<"[O] ";
                }
            }
            cout<<"\n";
        }
            ///CHECAGEM DE VITÓRIA
            for(int i=0;i<lin;i++){
                //checa as linhas de mesmo indice que i
                if((jogo[i][0]==jogo[i][1]) and (jogo[i][2]==jogo[i][1])){
                        if(jogo[i][0]==1){
                            cout<<"\nJogador 1 venceu !\n\n";
                            isplaying=0;
                            alguemjogou=1;
                            break;
                        } else if(jogo[i][0]==2){
                            cout<<"\nJogador 2 venceu !\n\n";
                            isplaying=0;
                            alguemjogou=1;
                            break;
                        }
                }
            }
            for(int i=0;i<col;i++){
                //checa as colunas de mesmo indice que i
                if((jogo[0][i]==jogo[1][i]) and (jogo[2][i]==jogo[1][i])){
                        if(jogo[0][i]==1){
                            cout<<"\nJogador 1 venceu !\n\n";
                            isplaying=0;
                            alguemjogou=1;
                            break;
                        } else if(jogo[0][i]==2){
                            cout<<"\nJogador 2 venceu !\n\n";
                            isplaying=0;
                            alguemjogou=1;
                            break;
                        }
                }
            }
            //checa a diagonal primária
            if((jogo[0][0]==jogo[1][1]) and (jogo[1][1]==jogo[2][2])){
                if(jogo[0][0]==1){
                    cout<<"\nJogador 1 venceu !\n\n";
                    isplaying=0;
                    alguemjogou=1;
                    break;
                } else if (jogo[0][0]==2){
                    cout<<"\nJogador 2 venceu !\n\n";
                    isplaying=0;
                    alguemjogou=1;
                    break;
                }
            }
            //checa a diagonal secundária
            if((jogo[0][2]==jogo[1][1]) and (jogo[1][1]==jogo[2][0])){
                if(jogo[0][2]==1){
                    cout<<"\nJogador 1 venceu !\n\n";
                    isplaying=0;
                    alguemjogou=1;
                    break;
                } else if (jogo[0][2]==2){
                    cout<<"\nJogador 2 venceu !\n\n";
                    isplaying=0;
                    alguemjogou=1;
                    break;
                }
            }
            /// CHECA SE AINDA HA ELEMENTOS VAZIOS NA MATRIZ
            for(int i=0;i<lin;i++){
                for(int j=0;j<col;j++){
                    if((jogo[i][j]==1) or (jogo[i][j]==2)){
                        elementosvazios-=1;
                    }
                }
            }
            if(elementosvazios==0){
                cout<<"\nNao ha mais espacos vazios. Jogo finalizado.\n\n";
                alguemjogou=1;
                isplaying=0;
                break;
            }
        //pede a cada jogador fazer sua acao
            /// TURNO DO JOGADOR 1
            if((player==1) and (alguemjogou==0)){
                cout<<"\n=============================\nJOGADOR 1 , SUA VEZ.\n=============================\n\nLinha : ";
                    x=_getch()-48;
                    cout<<x;
                    cout<<"\n";
                cout<<"Coluna : ";
                    y=_getch()-48;
                    cout<<y;
                    cout<<"\n";
                while((jogo[x-1][y-1]!=0)||(x-1>lin)||(x-1<0)||(y-1>col)||(y-1<0)){
                    cout<<"\nPosicao invalida.\nLinha : ";
                        x=_getch()-48;
                        cout<<x;
                        cout<<"\n";
                    cout<<"Coluna : ";
                        y=_getch()-48;
                        cout<<y;
                        cout<<"\n";
                }
                jogo[x-1][y-1]=1;
                player=2;
                alguemjogou=1;
            }
            /// TURNO DO JOGADOR 2
            if((player==2) and (alguemjogou==0)){
                cout<<"\n=============================\nJOGADOR 2 , SUA VEZ.\n=============================\n\nLinha : ";
                    x=_getch()-48;
                    cout<<x;
                    cout<<"\n";
                cout<<"Coluna : ";
                    y=_getch()-48;
                    cout<<y;
                    cout<<"\n";
                while((jogo[x-1][y-1]!=0)||(x-1>lin)||(x-1<0)||(y-1>col)||(y-1<0)){
                    cout<<"\nPosicao invalida.\nLinha : ";
                        x=_getch()-48;
                        cout<<x;
                        cout<<"\n";
                    cout<<"Coluna : ";
                        y=_getch()-48;
                        cout<<y;
                        cout<<"\n";
                }
                jogo[x-1][y-1]=2;
                player=1;
                alguemjogou=1;
            }
    }
    cout << "=============================\n";
    return 0;
}
