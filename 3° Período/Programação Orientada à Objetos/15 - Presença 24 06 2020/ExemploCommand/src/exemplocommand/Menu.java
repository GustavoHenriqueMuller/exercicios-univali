/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplocommand;

import exemplocommand.Command.*;

import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class Menu {
    public void executeAction(int index) {
        IAction action;
        
        switch (index){
            case 1:
                action = new ActionPrint();
                action.execute();
                break;
            default:
                action = new ActionQuit();
                action.execute();
                break;
        }
    }
    
    public void run(){
        System.out.println("1 - Print Action");
        System.out.println("X - Quit Action");
        
        Scanner scan = new Scanner(System.in);
        executeAction(scan.nextInt());
        
        scan.close();
    }
}
