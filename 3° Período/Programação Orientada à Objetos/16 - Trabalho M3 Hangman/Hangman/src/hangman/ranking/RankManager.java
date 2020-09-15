/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman.ranking;
import hangman.logic.Player;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

/**
 *
 * @author Gustavo
 */
public class RankManager {
    private Set<Player> players;
    private File file;
    
    public RankManager(String fileName) throws FileNotFoundException {
        this.file = new File(fileName + ".txt");
        players = loadPlayersFromFile();        
    }
    
    public void savePlayerToFile(Player playerToSave) throws IOException {
        FileWriter fileOutput = new FileWriter(file);
        players.add(playerToSave);
        
        for(Player player: players){
            // Escreve o nome e pontos dos jogadores no arquivo.
            fileOutput.write(player.name + " / " + player.points + "\n");
        }
        
        fileOutput.close();
    }
    
    private Set<Player> loadPlayersFromFile() throws FileNotFoundException {
        // Reseta a lista de players.
        players = new TreeSet<Player>();
        Scanner scanner = new Scanner(file);
        
        while(scanner.hasNextLine()){
            String line = scanner.nextLine();
            
            // Explode a linha para conseguir o nome e pontos do jogador.
            String[] array = line.split(" / ");
            
            // Cria um novo jogador e adiciona ele ao vetor.
            Player newPlayer = new Player(array[0], Integer.parseInt(array[1]));
            players.add(newPlayer);
        }
        
        scanner.close();        
        return players;
    }
    
    public Set<Player> getPlayers(){
        return players;
    }
}
