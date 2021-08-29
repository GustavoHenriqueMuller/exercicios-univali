/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplofactorymethod.product;
import exemplofactorymethod.product.Animal;

public class Horse implements Animal {    
    public void run(){
        System.out.println("Pocotó, pocotó...");
    }
    
    public void makeSound(){
        System.out.println("<som de cavalo>");
    }
}
