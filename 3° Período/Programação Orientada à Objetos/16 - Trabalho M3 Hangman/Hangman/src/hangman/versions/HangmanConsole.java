/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman.versions;

import hangman.bank.IWordBank;
import hangman.logic.Player;
import hangman.ranking.RankManager;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import hangman.logic.HangmanVisualGame;
import java.util.Set;

/**
 *
 * @author 1978233
 */
public class HangmanConsole extends HangmanVisualGame {    
    protected Scanner scanner;
    
    public HangmanConsole(IWordBank bank, String scoresFileName) {
        super(bank);
        scanner = new Scanner(System.in);
        
        try {
            rankManager = new RankManager(scoresFileName);
        } catch(IOException e){
            System.out.println("An error has ocurred while opening the scores. Exiting...");
            System.exit(0);
        }
    }
    
    @Override
    public void newGame(){
        game.init();
        
        // Pega as opções que o player deseja.
        System.out.println("1 - Play");
        System.out.println("2 - Rankings");
        System.out.println("_ - Exit");
        
        int option = scanner.nextInt();
        execOption(option);
    }
    
    @Override
    public void getPlayerName() {
        System.out.println("Type your name: ");
        game.playerName = scanner.next();
    }
    
    @Override
    public void mainLoop() {
        do {
            System.out.println("Guess a word:");
            System.out.println(game.getDisplayWord());            
            
            // Pega a adivinhação do jogador.
            char guess = scanner.next().charAt(0);
            
            while(guess == ' ') {
                guess = scanner.next().charAt(0);
            }
            
            if (!game.tryLetter(guess)){
                System.out.println("Wrong, please try again!");
                this.draw(game.getMistakes());
            }
        } while (game.hasMoreTries());
    }
    
    @Override
    public void victoryCheck() {
        if (game.hasWon()){
            System.out.println("Congratulations, you won with " + game.getMistakes() + " mistake(s) (" + Integer.toString(game.getPoints()) + " points).");
        } else {
            System.out.println("Game Over! The word was: " + game.getCurrentWord() + " (" + Integer.toString(game.getPoints()) + " points).");
        }
    }
    
    @Override
    public void savePlayerToFile() {        
        try {
            rankManager.savePlayerToFile(new Player(game.playerName, game.getPoints()));
        } catch(IOException e){
            System.out.println("An error has ocurred while saving a player to the ranking file. Exiting...");
        }
    }
    
    @Override
    public void showRankings() {
        // Pega os rankings a partir do arquivo.
        Set<Player> players = rankManager.getPlayers();
            
        // Se os jogadores não é vazio.
        if(!players.isEmpty()) {
            for(Player player : players) {
                System.out.println(player.name + " | " + player.points);
            }
        } else {
            System.out.println("There are no highscores yet.");
        }
    }
    
    @Override
    public void exit() {
        System.out.println("Exiting...");
    }
    
    @Override
    public void showWord() {
        System.out.println("The word was: " + game.getCurrentWord() + ".");
    }
    
    private void draw(int mistakes){
        switch(mistakes){
            case 1:
                System.out.println();
                System.out.println();
                System.out.println();
                System.out.println();
                System.out.println("___|___");
                System.out.println();
                break;
            case 2:
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("___|___");
                break;
            case 3:
                System.out.println("   ____________");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   | ");
                System.out.println("___|___");
                break;
            case 4:
                System.out.println("   ____________");
                System.out.println("   |          _|_");
                System.out.println("   |         /   \\");
                System.out.println("   |        |     |");
                System.out.println("   |         \\_ _/");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("   |");
                System.out.println("___|___");
                break;
            case 5:
                System.out.println("   ____________");
                System.out.println("   |          _|_");
                System.out.println("   |         /   \\");
                System.out.println("   |        |     |");
                System.out.println("   |         \\_ _/");
                System.out.println("   |           |");
                System.out.println("   |           |");
                System.out.println("   |");
                System.out.println("___|___");
                break;
            case 6:
                System.out.println("   ____________");
                System.out.println("   |          _|_");
                System.out.println("   |         /   \\");
                System.out.println("   |        |     |");
                System.out.println("   |         \\_ _/");
                System.out.println("   |           |");
                System.out.println("   |           |");
                System.out.println("   |          / \\ ");
                System.out.println("___|___      /   \\");
                break;
            case 7:
                System.out.println("   ____________");
                System.out.println("   |          _|_");
                System.out.println("   |         /   \\");
                System.out.println("   |        |     |");
                System.out.println("   |         \\_ _/");
                System.out.println("   |          _|_");
                System.out.println("   |         / | \\");
                System.out.println("   |          / \\ ");
                System.out.println("___|___      /   \\");
                break;
        }
    }    
}
