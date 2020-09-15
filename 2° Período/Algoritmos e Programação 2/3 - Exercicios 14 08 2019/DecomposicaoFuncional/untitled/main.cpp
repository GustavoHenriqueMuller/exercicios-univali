#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void printMap(){
    system("cls");

    cout << "\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "     |     |     " << endl << endl;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void result(int i,int player){
    if(i==1)
        cout<<"==>\a Player "<<player<<" wins !!\n";
    else
        cout<<"==>\a Game draw !!\n";
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main() {
    int player = 1;
    int i;
    int choice;
    char mark;

    do
    {
        printMap();
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;
        mark =(player == 1) ? 'X' : 'O';
    //MOVIMENTOS DO JOGADOR 1 E 2
        if (square[choice] == choice + '0'){
            square[choice] = mark;
        } else {
            cout<<"Invalid move ";
            player--;
            _getch();
        }
    //CHECAGEM DE VITORIA
        if (square[1] == square[2] && square[2] == square[3]){
            i = 1;
            break;
        } else if (square[4] == square[5] && square[5] == square[6]){
            i = 1;
            break;
        } else if (square[7] == square[8] && square[8] == square[9]){
            i = 1;
            break;
        } else if (square[1] == square[4] && square[4] == square[7]){
            i = 1;
            break;
        } else if (square[2] == square[5] && square[5] == square[8]){
            i = 1;
            break;
        } else if (square[3] == square[6] && square[6] == square[9]){
            i = 1;
            break;
        } else if (square[1] == square[5] && square[5] == square[9]){
            i = 1;
            break;
        } else if (square[3] == square[5] && square[5] == square[7]){
            i = 1;
            break;
        } else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9'){
            i = 0;
            break;
        } else {
            i = -1;
        }
        player++;

    }
    while(i == -1);
    printMap();
    //DECIDE O RESULTADO DA PARTIDA
    result(i,player);
    cout<<&i;
    return 0;
}
