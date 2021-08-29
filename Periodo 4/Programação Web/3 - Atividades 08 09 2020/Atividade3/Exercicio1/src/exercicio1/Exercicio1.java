/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class Exercicio1 {

    /**
     * @param args the command line arguments
     */
   
    public static void main(String[] args) {
        ArrayList<Integer> array = new ArrayList<Integer>();
        Scanner scanner = new Scanner(System.in);
        
        for(int i = 0; i < 10; i++) {
            System.out.println("Digite o número no índice [" + String.valueOf(i) + "]: ");
            array.add(scanner.nextInt());
        }
        
        Collections.sort(array);
        
        for(Integer i: array){
            System.out.println(String.valueOf(i));
        }
    }
}
