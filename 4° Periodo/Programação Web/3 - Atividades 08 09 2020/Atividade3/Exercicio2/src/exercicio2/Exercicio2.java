/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class Exercicio2 {

    /**
     * @param args the command line arguments
     */
   
    public static void main(String[] args) {
        ArrayList<String> array = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        
        for(int i = 0; i < 10; i++) {
            System.out.println("Digite o texto no índice [" + String.valueOf(i) + "]: ");
            array.add(scanner.nextLine());
        }
        
        Collections.sort(array);
        
        for(String s: array){
            System.out.println(s);
        }
    }
}
