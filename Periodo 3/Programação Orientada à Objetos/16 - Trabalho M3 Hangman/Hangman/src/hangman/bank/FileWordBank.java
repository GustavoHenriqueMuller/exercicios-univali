/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman.bank;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class FileWordBank extends SimpleWordBank {
    private final File file;
    private final Scanner scanner;
    
    public FileWordBank(String fileName) throws FileNotFoundException {
        file = new File(fileName + ".txt");
        scanner = new Scanner(file);          
        
        // Examina todas as linhas do arquivo e adiciona elas ao banco.
        while(scanner.hasNextLine()){
            String line = scanner.nextLine();
            addWord(line);
        }
        
        scanner.close();
    }
}
