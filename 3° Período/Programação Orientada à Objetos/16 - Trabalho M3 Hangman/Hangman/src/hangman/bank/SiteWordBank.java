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
public class SiteWordBank extends SimpleWordBank {
    private final File file;
    private final Scanner scanner;
    private boolean isExaminingBody;
    
    public SiteWordBank(String htmlName) throws FileNotFoundException {
        file = new File(htmlName + ".html");
        scanner = new Scanner(file);
        isExaminingBody = false;        
        
        while(scanner.hasNextLine()){
            String line = scanner.nextLine();
            
            // Encontramos o body, vamos extrair o inner HTML dos elementos.
            if(line.contains("<body>")) {
                isExaminingBody = true;
            }
            
            if(line.contains("</body>")) {
                isExaminingBody = false;
            }
            
            // Extrai o inner HTML e coloca no banco, se a linha sendo examinada
            // não for a própria linha do "<body>".
            if(isExaminingBody && !line.contains("<body>")) {          
                line = line.substring(line.indexOf(">") + 1);
                line = line.substring(0, line.indexOf("<"));
                
                addWord(line);
            }
        }        
        
        scanner.close();
    }
}
