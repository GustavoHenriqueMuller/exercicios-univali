package hangman;

import hangman.bank.SimpleWordBank;
import hangman.bank.SiteWordBank;
import hangman.bank.FileWordBank;

import hangman.versions.HangmanConsole;
import hangman.versions.HangmanGUI;
import hangman.logic.HangmanVisualGame;

import java.io.FileNotFoundException;

public class Main {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {        
        try {
            HangmanVisualGame hangman = new HangmanGUI(new FileWordBank("simpleBank"), "scores");
            hangman.newGame();
        } catch (FileNotFoundException e){
            System.out.println("File does not exist.");
        }
    }
}
