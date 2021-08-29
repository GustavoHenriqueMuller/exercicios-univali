/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman.logic;

import hangman.bank.IWordBank;
import hangman.ranking.RankManager;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public abstract class HangmanVisualGame {
    protected Hangman game;
    protected RankManager rankManager;
    
    public HangmanVisualGame(IWordBank bank){
        game = new Hangman(bank);
    }
    
    public void execOption(int option){
        switch(option){            
            case 1:
                // Pega o nome do jogador.
                getPlayerName();
                
                // Loop principal.
                mainLoop();
                
                // Mostra a palavra depois do jogo acabar.
                showWord();

                // Checagem de vitória.
                victoryCheck();
        
                // Salva o jogador num arquivo.
                savePlayerToFile();
                
                // Sai do jogo.
                exit();
                return;
            case 2:
                // Mostra os rankings.
                showRankings();
                
                // Sai do jogo.
                exit();
                return;
            default:
                // Saí do jogo.
                exit();
                return;
        }
    }
    public abstract void getPlayerName();
    public abstract void newGame();
    public abstract void mainLoop();
    public abstract void showWord();
    public abstract void victoryCheck();
    public abstract void savePlayerToFile();
    public abstract void showRankings();
    public abstract void exit();
}
