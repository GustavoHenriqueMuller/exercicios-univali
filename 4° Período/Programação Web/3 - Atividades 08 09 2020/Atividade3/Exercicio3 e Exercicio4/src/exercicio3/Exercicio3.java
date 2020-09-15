/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio3;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class Exercicio3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
                
        System.out.println("Digite o nome do arquivo: ");
        String filename = scanner.nextLine();
        System.out.println("Digite a informação que você quer salvar: ");
        String info = scanner.nextLine();        
       
        try {            
            FileWriter writer = new FileWriter(filename + ".txt");
            writer.write(info);
            writer.close();
        } catch (IOException e) {
            System.out.println("Um erro ocorreu.");
        }
    }    
}
