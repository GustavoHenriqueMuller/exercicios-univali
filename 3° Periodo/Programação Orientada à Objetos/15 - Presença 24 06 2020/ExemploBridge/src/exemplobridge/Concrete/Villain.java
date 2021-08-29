/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplobridge.Concrete;
import exemplobridge.Abstract.ICharacter;

/**
 *
 * @author Gustavo
 */
public class Villain implements ICharacter {
    @Override
    public void move() {
        System.out.println("Sou o vilão e me movi pra algum lugar.");
    }

    @Override
    public void speak(String coisa) {
        System.out.println("Sou o vilão e falei: " + coisa);
    }
    
}
