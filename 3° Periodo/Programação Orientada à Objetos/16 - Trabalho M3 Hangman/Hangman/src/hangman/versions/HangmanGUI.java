/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman.versions;

import hangman.bank.IWordBank;
import hangman.logic.HangmanVisualGame;
import hangman.logic.Player;
import hangman.ranking.RankManager;
import java.io.IOException;
import java.util.Set;
import javax.swing.ImageIcon;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 *
 * @author Gustavo
 */
public class HangmanGUI extends HangmanVisualGame {
    private JFrame frame;
    private JPanel panel;
    private JLabel image;
    
    public HangmanGUI(IWordBank bank, String scoresFileName) {
        super(bank);        
        frame = new JFrame("Hangman GUI");
        panel = new JPanel();
        
        try {
            rankManager = new RankManager(scoresFileName);
        } catch(IOException e){
            JOptionPane.showMessageDialog(frame, "An error has ocurred while opening the scores. Exiting...");
            System.exit(0);
        }
    }
    
    @Override
    public void newGame() {
        game.init();
        
        String[] options = {"Play", "Rankings", "Quit"};
        int option = 1 + JOptionPane.showOptionDialog(frame, "Select an option:", "Hangman GUI", JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null, options, options[0]);
        execOption(option);
    }
    
    @Override
    public void getPlayerName() {
        game.playerName = JOptionPane.showInputDialog(frame, "Type your name: ");
    }
    
    @Override
    public void mainLoop() {
        do {
            drawImage();
            
            // Pega a adivinhação do jogador.
            String guess = null;
            
            while(guess == null || guess == "") {
                guess = JOptionPane.showInputDialog(frame, "Guess: " + game.getDisplayWord());
            }            
            
            if (!game.tryLetter(guess.charAt(0))){
                JOptionPane.showMessageDialog(frame, "Wrong, please try again!", "You missed!", JOptionPane.ERROR_MESSAGE);                
            }
            
            drawImage();
        } while (game.hasMoreTries());
    }
    
    @Override
    public void victoryCheck() {
        if (game.hasWon()){
            JOptionPane.showMessageDialog(frame, "Congratulations, you won with " + game.getMistakes() + " mistake(s) (" + Integer.toString(game.getPoints()) + " points).");
        } else {
            JOptionPane.showMessageDialog(frame, "Game Over! The word was: " + game.getCurrentWord() + " (" + Integer.toString(game.getPoints()) + " points).");
        }
    }
    
    @Override
    public void savePlayerToFile() {
        try {
            rankManager.savePlayerToFile(new Player(game.playerName, game.getPoints()));
        } catch(IOException e){
            JOptionPane.showMessageDialog(frame, "An error has ocurred while saving a player to the ranking file. Exiting...");
        }
    }
    
    @Override
    public void showRankings() {
        // Pega os rankings a partir do arquivo.
        Set<Player> players = rankManager.getPlayers();
        String message = "";
            
        // Se os jogadores não é vazio.
        if(!players.isEmpty()) {
            for(Player player : players) {
                message += player.name + " | " + player.points + " points\n";
            }
        } else {
            message = "There are no highscores yet.";
        }
           
        JOptionPane.showMessageDialog(frame, message);
    }
    
    @Override
    public void exit() {
        JOptionPane.showMessageDialog(frame, "Exiting...");
        System.exit(0);
    }

    @Override
    public void showWord() {
        JOptionPane.showMessageDialog(frame, "The word was: " + game.getCurrentWord() + ".");
    }
    
    public void drawImage() {
        // Mostra a imagem na tela.
        if(image != null)
            panel.remove(image);
           
        image = new JLabel(new ImageIcon("assets/" + game.getMistakes() + ".png"));
        image.setLocation(0, 0);
        panel.add(image);
            
        frame.add(panel);
        frame.setSize(530, 550);
        frame.setLocation(700, 300);
            
        frame.show();
    }
}
