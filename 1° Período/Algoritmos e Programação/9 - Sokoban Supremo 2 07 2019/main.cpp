/**
    Estrutura inicial para o jogo SOKOBAN SUPREMO feito por Thiago Felski Pereira
    Jogo feito pelos acadêmicos Gustavo Müller e Gustavo Amorim.
    Data inicial: 24/06/2019
    Última atualização: 01/07/2019
*/

#include <iostream>
#include <windows.h>
#include <conio.h>

///Bibliotecas não-originais
#include <stdlib.h>

///Tamanhos do primeiro e segundo mapas , respectivamente
///C = Base , L = Altura
#define C 10
#define L 6

#define C2 9
#define L2 12

using namespace std;

///Função para alterar a cor do texto
void textcolor (int cor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= cor);
}

///Struct que guarda X e Y de pontos
struct obj{
    int x;
    int y;
};

obj ponto1;
obj ponto2;
obj ponto3;
obj ponto4;
obj ponto5;

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

    ///Identifica a tela em que o jogador está . Telas : Menu(0) , Seleção de Mapas(1) , Tutorial(2) , Mapa 1(3) , Mapa 2(4)
    int screen=0,screensel=-1;

    /**      M E N U       */
            bool completo1=false,completo2=false; // valor bool que define se os mapas foram completos pelo player ou não
            screenreset:
            ///faz a condição de vitória total ( dois níveis completos )
            if((completo1==true) and (completo2==true)){
                system("CLS");
                textcolor(10);
                cout<<"============================================================================================================\n";
                textcolor(7);
                cout<<"                                          P A R A B E N S !!!\n";
                textcolor(10);
                cout<<"============================================================================================================\n";
                textcolor(7);
                cout<<"\nVoce venceu os dois incriveis niveis do Sokoban Supremo !!\n\n";
                cout<<">> Digite :\n0 : Menu\n\n-1 : Sair.\n\n";
                textcolor(10);
                cout<<"============================================================================================================\n\n";
                textcolor(7);
                completo1=false;
                completo2=false;
                cin>>screensel;
                    while((screensel != 0) and (screensel != -1)){
                        cout<<"\nTela invalida.\n\n";
                        cin>>screensel;
                    }
                    if(screensel == -1){ //saindo do jogo
                        system("CLS");
                        return 0;
                    }
                    if(screensel == 0){ //indo para o menu
                        system("CLS");
                        screen=screensel;
                    }
                system("CLS");
            }
            if(screen == 0){
                cout<<"============================================================================================================\n";
                cout<<"                                    S O K O B A N          S U P R E M O\n";
                cout<<"============================================================================================================\n";
                cout<<"\nGustavo Muller e Gustavo Amorim - UNIVALI 2019\n\n";
                cout<<">> Digite :\n1 : Jogar\n2 : Tutorial\n\n-1 : Sair.\n\n";
                cout<<"============================================================================================================\n\n";
                cin>>screensel;
                    while((screensel != 1) and (screensel != 2) and (screensel != -1)){
                        cout<<"\nTela invalida.\n\n";
                        cin>>screensel;
                    }
                    if(screensel == -1){ //saindo do jogo
                        system("CLS");
                        return 0;
                    }
                    if((screensel == 1) or (screensel == 2)){ //indo para a tela de tutorial ou de selecao de mapas
                        system("CLS");
                        screen=screensel;
                    }
            }

    /**      S E L E Ç Ã O           D E           M A P A S       */
            int xp = 0,yp = 0; // significados : xp = x preview , yp = y preview
            //Variável para tecla precionada
            char tecla;
            //Coordenadas para impressão na tela
            int i,j;
            ///As duas matrizes abaixo guardam a informacao dos niveis , como locais das paredes , caixas e pontos
            //Primeiro nivel = Requisitado pelo Prof° , Segundo nivel = Feito pelos desenvolvedores
            //0 - Nada , 1 - Parede , 3 - Caixas , 4 - Pontos .
            int nivelumpreview[L][C]={{1,1,1,1,1,1,1,1,1,1},
                                      {1,0,2,1,1,1,4,4,4,1},
                                      {1,0,3,3,0,0,4,3,4,1},
                                      {1,0,0,0,1,3,1,3,0,1},
                                      {1,1,0,0,0,0,0,0,0,1},
                                      {1,1,1,1,1,1,1,1,1,1}};

            int nivelum[L][C]={{1,1,1,1,1,1,1,1,1,1},
                               {1,0,2,1,1,1,4,4,4,1},
                               {1,0,3,3,0,0,4,3,4,1},
                               {1,0,0,0,1,3,1,3,0,1},
                               {1,1,0,0,0,0,0,0,0,1},
                               {1,1,1,1,1,1,1,1,1,1}};

            int niveldoispreview[L2][C2]={{1,1,1,1,1,1,1,1,1},
                                          {1,0,0,0,0,1,1,1,1},
                                          {1,0,0,0,0,0,0,0,1},
                                          {1,0,4,0,1,0,0,4,1},
                                          {1,0,0,0,0,0,0,0,1},
                                          {1,0,0,0,0,0,3,0,1},
                                          {1,1,1,0,0,0,0,0,1},
                                          {1,1,1,0,2,0,0,0,1},
                                          {1,0,0,0,0,1,1,0,1},
                                          {1,0,3,0,0,1,1,0,1},
                                          {1,0,0,0,0,0,0,0,1},
                                          {1,1,1,1,1,1,1,1,1}};

            int niveldois[L2][C2]={{1,1,1,1,1,1,1,1,1},
                                   {1,0,0,0,0,1,1,1,1},
                                   {1,0,0,0,0,0,0,0,1},
                                   {1,0,4,0,1,0,0,4,1},
                                   {1,0,0,0,0,0,0,0,1},
                                   {1,0,0,0,0,0,3,0,1},
                                   {1,1,1,0,0,0,0,0,1},
                                   {1,1,1,0,2,0,0,0,1},
                                   {1,0,0,0,0,1,1,0,1},
                                   {1,0,3,0,0,1,1,0,1},
                                   {1,0,0,0,0,0,0,0,1},
                                   {1,1,1,1,1,1,1,1,1}};

            if(screen == 1){
                cout<<"============================================================================================================\n";
                cout<<"                                  S E L E C A O       D E       M A P A S\n";
                cout<<"============================================================================================================\n";
                xp=0;
                yp=0;
                ///Faz uma pequena prévia do mapa durante a seleção
                if(completo1==true){
                    textcolor(10);
                    cout<<"\nMapa 1 (COMPLETO) :\n";
                    textcolor(7);
                        while(xp<L){
                            yp=0;
                            cout<<"\n";
                            while(yp<C){
                                if(nivelumpreview[xp][yp] == 0){
                                    cout<<" "; // printando o nada
                                } else if (nivelumpreview[xp][yp] == 1){
                                    cout<<char(178); // printando a parede
                                } else if (nivelumpreview[xp][yp] == 2){
                                    cout<<"@"; // printando o player
                                } else if (nivelumpreview[xp][yp] == 3){
                                    cout<<char(254); // printando a caixa
                                } else {
                                    textcolor(10);
                                    cout<<char(248); // printando um ponto
                                    textcolor(7);
                                }
                                yp++;
                            }
                            xp++;
                        }
                    xp=0;
                    yp=0;
                    cout<<"\n";
                } else {
                    textcolor(12);
                    cout<<"Mapa 1 (INCOMPLETO).\n";
                    textcolor(7);
                }
                if(completo2==true){
                    textcolor(10);
                    cout<<"\n\nMapa 2 (COMPLETO) :\n";
                    textcolor(7);
                        while(xp<L2){
                            yp=0;
                            cout<<"\n";
                            while(yp<C2){
                                if(niveldoispreview[xp][yp] == 0){
                                    cout<<" "; // printando o nada
                                } else if (niveldoispreview[xp][yp] == 1){
                                    cout<<char(178); // printando a parede
                                } else if (niveldoispreview[xp][yp] == 2){
                                    cout<<"@"; // printando o player
                                } else if (niveldoispreview[xp][yp] == 3){
                                    cout<<char(254); // printando a caixa
                                } else {
                                    textcolor(10);
                                    cout<<char(248); // printando um ponto
                                    textcolor(7);
                                }
                                yp++;
                            }
                            xp++;
                        }
                } else {
                    textcolor(12);
                    cout<<"\nMapa 2 (INCOMPLETO).";
                    textcolor(7);
                }
                cout<<"\n\n>> Digite :\n0 : Menu\n1 : Mapa 1\n2 : Mapa 2\n\n-1 : Sair.\n\n";
                cout<<"============================================================================================================\n\n";
                cin>>screensel;
                    while((screensel != 0) and (screensel != 1) and (screensel!=2) and (screensel!=-1)){
                        cout<<"\nTela invalida.\n\n";
                        cin>>screensel;
                    }
                    if(screensel == -1){ //saindo do jogo
                        system("CLS");
                        return 0;
                    }
                    if((screensel == 0)){ //indo para o menu
                        system("CLS");
                        screen=screensel;
                        goto screenreset;
                    }
                    if((screensel == 1)){ //indo para o mapa 1
                        system("CLS");
                        screen=3;
                    }
                    if((screensel == 2)){ //indo para o mapa 2
                        system("CLS");
                        screen=4;
                    }
            }

    /**      T U T O R I A L       */
            if(screen == 2){
                cout<<"============================================================================================================\n";
                cout<<"                                             T U T O R I A L\n";
                cout<<"============================================================================================================\n";
                cout<<"\nObjetivo : Voce deve empurrar as caixas ate os pontos , atraves da movimentacao do seu personagem.\n\n";
                cout<<"[W][A][S][D] : Movimenta o personagem para cima , esquerda , baixo e direita , respectivamente.\n";
                cout<<"Ao se aproximar de uma caixa, pressione a tecla que representa a direcao que voce deseja empurrar a caixa para empurra-la.\n\n";
                cout<<"PS : Nao e possivel empurrar uma caixa atraves de uma parede, pois a caixa e um solido, assim como na vida real.\n";
                cout<<"PS 2 : Nao e possivel empurrar mais de uma caixa com o mesmo movimento.\n";
                cout<<"\n>> Digite :\n0 : Menu\n\n-1 : Sair.\n\n";
                cout<<"============================================================================================================\n\n";
                cin>>screensel;
                    while((screensel != 0) and (screensel != -1)){
                        cout<<"\nTela invalida.\n\n";
                        cin>>screensel;
                    }
                    if(screensel == -1){ //saindo do jogo
                        system("CLS");
                        return 0;
                    }
                    if((screensel == 0)){ //indo para o menu
                        system("CLS");
                        screen=screensel;
                        goto screenreset;
                    }
            }

    /**        M A P A      1          */
            //Seta a posição inicial do player , caixas e pontos
            int playerx = 0 , playery = 0; //variáveis de posição do player
            if(screen == 3){
                playerx = 2;
                playery = 1;
                ponto1.x = 6;
                ponto1.y = 2;
                ponto2.x = 6;
                ponto2.y = 1;
                ponto3.x = 7;
                ponto3.y = 1;
                ponto4.x = 8;
                ponto4.y = 1;
                ponto5.x = 8;
                ponto5.y = 2;
            }
            while((screen==3)){
                ///Imprime o jogo: mapa e personagem.
                i=0;
                while (i<L) {
                    j=0;
                    while (j<C) {
                            if((i == playerx) and (j == playery)){
                                    cout<<"@"; // printando o player
                            } else if ((nivelum[i][j] == 3)&&(nivelumpreview[i][j] == 4)){
                                    textcolor(10);
                                    cout<<char(254); // printando a caixa em cima de ponto
                                    textcolor(7);
                            } else if (nivelum[i][j] == 3){
                                    cout<<char(254); // printando as caixas
                            } else if (nivelumpreview[i][j] == 4){
                                    textcolor(10);
                                    cout<<"O"; // printando o ponto
                                    textcolor(7);
                            } else if (nivelum[i][j] == 1){
                                    cout<<char(178); // printando a parede
                            } else {
                                    cout<<" "; // printando o nada
                            }
                        j++;
                    }
                    cout<<"\n";
                    i++;
                    }
                    ///condição de vitória
                    if ((nivelum[ponto1.y][ponto1.x]==3) and (nivelum[ponto2.y][ponto2.x]==3) and (nivelum[ponto3.y][ponto3.x]==3) and (nivelum[ponto4.y][ponto4.x]==3) and (nivelum[ponto5.y][ponto5.x]==3)){
                        completo1=true;
                        cout<<"\n===== V I T O R I A =====\n\n>> Digite :\n0 : Menu.\n-1 : Sair.\n\n";
                        cin>>screensel;
                            while((screensel != 0) and (screensel != -1)){
                                cout<<"\nTela invalida.\n\n";
                                cin>>screensel;
                            }
                            if(screensel==-1){ //saindo do jogo
                                system("CLS");
                                return 0;
                            }
                            if(screensel==0){ //indo para a tela de menu
                                system("CLS");
                                screen=screensel;
                                goto screenreset;
                            }
                    }
                    ///executa os movimentos
                     if ( _kbhit() ){
                        tecla = getch();
                        switch(tecla)
                        {
                            case 'w': /**      C I M A       */
                                ///empurrando a caixa para um espaço livre
                                if ((nivelum[playerx-1][playery] == 3) and ((nivelum[playerx-2][playery] == 0) or ((nivelumpreview[playerx-2][playery] == 4) and (nivelum[playerx-2][playery] != 3)))){
                                    nivelum[playerx][playery] = 0;
                                    playerx--;
                                    nivelum[playerx][playery] = 2;
                                    nivelum[playerx-1][playery] = 3;

                                ///testa se está indo para uma posição vazia ou para uma posição final
                                } else if((nivelum[playerx-1][playery]!=1) and (nivelum[playerx-1][playery]!=3)){
                                    nivelum[playerx][playery] = 0;
                                    playerx--;
                                    nivelum[playerx][playery] = 2;
                                }
                            break;
                            case 's': /**      B A I X O       */
                                ///empurrando a caixa para um espaço livre
                                if ((nivelum[playerx+1][playery] == 3) and ((nivelum[playerx+2][playery] == 0) or ((nivelumpreview[playerx+2][playery] == 4) and (nivelum[playerx+2][playery] != 3)))){
                                    nivelum[playerx][playery] = 0;
                                    playerx++;
                                    nivelum[playerx][playery] = 2;
                                    nivelum[playerx+1][playery] = 3;

                                ///testa se está indo para uma posição vazia ou para uma posição final
                                } else if((nivelum[playerx+1][playery]!=1) and (nivelum[playerx+1][playery]!=3)){
                                    nivelum[playerx][playery] = 0;
                                    playerx++;
                                    nivelum[playerx][playery] = 2;
                                }
                            break;
                            case 'a': /**      E S Q U E R D A      */
                                ///empurrando a caixa para um espaço livre
                                if ((nivelum[playerx][playery-1] == 3) and ((nivelum[playerx][playery-2] == 0) or ((nivelumpreview[playerx][playery-2] == 4) and (nivelum[playerx][playery-2] != 3)))){
                                    nivelum[playerx][playery] = 0;
                                    playery--;
                                    nivelum[playerx][playery] = 2;
                                    nivelum[playerx][playery-1] = 3;

                                ///testa se está indo para uma posição vazia ou para uma posição final
                                } else if((nivelum[playerx][playery-1]!=1) and (nivelum[playerx][playery-1]!=3)){
                                    nivelum[playerx][playery] = 0;
                                    playery--;
                                    nivelum[playerx][playery] = 2;
                                }
                            break;
                            case 'd': /**      D I R E I T A      */
                                ///empurrando a caixa para um espaço livre
                                if ((nivelum[playerx][playery+1] == 3) and ((nivelum[playerx][playery+2] == 0) or ((nivelumpreview[playerx][playery+2] == 4) and (nivelum[playerx][playery+2] != 3)))){
                                    nivelum[playerx][playery] = 0;
                                    playery++;
                                    nivelum[playerx][playery] = 2;
                                    nivelum[playerx][playery+1] = 3;

                                ///testa se está indo para uma posição vazia ou para uma posição final
                                } else if((nivelum[playerx][playery+1]!=1) and (nivelum[playerx][playery+1]!=3)){
                                    nivelum[playerx][playery] = 0;
                                    playery++;
                                    nivelum[playerx][playery] = 2;
                                }
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
    /**        M A P A      2          */
            //Seta a posição inicial do player , caixas e pontos
            if(screen==4){
                playerx = 7;
                playery = 4;
                ponto1.x = 2;
                ponto1.y = 3;
                ponto2.x = 7;
                ponto2.y = 3;
            }
            while((screen==4)){
                ///Imprime o jogo: mapa e personagem.
                i=0;
                while (i<L2) {
                    j=0;
                    while (j<C2) {
                            if((i == playerx) and (j == playery)){
                                    cout<<"@"; // printando o player
                            } else if ((niveldois[i][j] == 3)&&(niveldoispreview[i][j] == 4)){
                                    textcolor(10);
                                    cout<<char(254); // printando a caixa em cima de ponto
                                    textcolor(7);
                            } else if (niveldois[i][j] == 3){
                                    cout<<char(254); // printando as caixas
                            } else if (niveldoispreview[i][j] == 4){
                                    textcolor(10);
                                    cout<<"O"; // printando o ponto
                                    textcolor(7);
                            } else if (niveldois[i][j] == 1){
                                    cout<<char(178); // printando a parede
                            } else {
                                    cout<<" "; // printando o nada
                            }
                        j++;
                    }
                    cout<<"\n";
                    i++;
                    }
                    ///condição de vitória
                    if ((niveldois[ponto1.y][ponto1.x]==3) and (niveldois[ponto2.y][ponto2.x]==3)){
                            completo2=true;
                            cout<<"\n===== V I T O R I A =====\n\n>> Digite :\n0 : Menu.\n-1 : Sair.\n\n";
                            cin>>screensel;
                            while((screensel != 0) and (screensel != -1)){
                                cout<<"\nTela invalida.\n\n";
                                cin>>screensel;
                            }
                            if(screensel==-1){ //saindo do jogo
                                system("CLS");
                                return 0;
                            }
                            if(screensel==0){ //indo para a tela de menu
                                system("CLS");
                                screen=screensel;
                                goto screenreset;
                            }
                    }
                    ///executa os movimentos
                     if ( _kbhit() ){
                        tecla = getch();
                        switch(tecla)
                        {
                            case 'w': /**      C I M A       */
                                ///empurrando a caixa para um espaço livre
                                if ((niveldois[playerx-1][playery] == 3) and ((niveldois[playerx-2][playery] == 0) or ((niveldoispreview[playerx-2][playery] == 4) and (niveldois[playerx-2][playery] != 3)))){
                                    niveldois[playerx][playery] = 0;
                                    playerx--;
                                    niveldois[playerx][playery] = 2;
                                    niveldois[playerx-1][playery] = 3;

                                ///testa se está indo para uma posição vazia ou para uma posição final
                                } else if((niveldois[playerx-1][playery]!=1) and (niveldois[playerx-1][playery]!=3)){
                                    niveldois[playerx][playery] = 0;
                                    playerx--;
                                    niveldois[playerx][playery] = 2;
                                }
                            break;
                            case 's': /**      B A I X O       */
                                ///empurrando a caixa para um espaço livre
                                if ((niveldois[playerx+1][playery] == 3) and ((niveldois[playerx+2][playery] == 0) or ((niveldoispreview[playerx+2][playery] == 4) and (niveldois[playerx+2][playery] != 3)))){
                                    niveldois[playerx][playery] = 0;
                                    playerx++;
                                    niveldois[playerx][playery] = 2;
                                    niveldois[playerx+1][playery] = 3;

                                ///testa se está indo para uma posição vazia ou para uma posição final
                                } else if((niveldois[playerx+1][playery]!=1) and (niveldois[playerx+1][playery]!=3)){
                                    niveldois[playerx][playery] = 0;
                                    playerx++;
                                    niveldois[playerx][playery] = 2;
                                }
                            break;
                            case 'a': /**      E S Q U E R D A      */
                                ///empurrando a caixa para um espaço livre
                                if ((niveldois[playerx][playery-1] == 3) and ((niveldois[playerx][playery-2] == 0) or ((niveldoispreview[playerx][playery-2] == 4) and (niveldois[playerx][playery-2] != 3)))){
                                    niveldois[playerx][playery] = 0;
                                    playery--;
                                    niveldois[playerx][playery] = 2;
                                    niveldois[playerx][playery-1] = 3;

                                ///testa se está indo para uma posição vazia ou para uma posição final
                                } else if((niveldois[playerx][playery-1]!=1) and (niveldois[playerx][playery-1]!=3)){
                                    niveldois[playerx][playery] = 0;
                                    playery--;
                                    niveldois[playerx][playery] = 2;
                                }
                            break;
                            case 'd': /**      D I R E I T A      */
                                ///empurrando a caixa para um espaço livre
                                if ((niveldois[playerx][playery+1] == 3) and ((niveldois[playerx][playery+2] == 0) or ((niveldoispreview[playerx][playery+2] == 4) and (niveldois[playerx][playery+2] != 3)))){
                                    niveldois[playerx][playery] = 0;
                                    playery++;
                                    niveldois[playerx][playery] = 2;
                                    niveldois[playerx][playery+1] = 3;

                                ///testa se está indo para uma posição vazia ou para uma posição final
                                } else if((niveldois[playerx][playery+1]!=1) and (niveldois[playerx][playery+1]!=3)){
                                    niveldois[playerx][playery] = 0;
                                    playery++;
                                    niveldois[playerx][playery] = 2;
                                }
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
