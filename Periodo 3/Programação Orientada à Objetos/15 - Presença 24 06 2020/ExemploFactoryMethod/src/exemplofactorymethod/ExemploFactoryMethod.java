/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplofactorymethod;
import exemplofactorymethod.product.*;
import exemplofactorymethod.factory.*;

/**
 *
 * @author Gustavo
 */
public class ExemploFactoryMethod {

    /**
     * Esse código representa como poderia ser criada uma solução para um problema
     * que precisa instanciar classes de animais diferentes, como cachorro e cavalo
     * através do padrão de projeto Factory Method.
     */
    public static void main(String[] args) {
        HorseFactory fabricaCavalos = new HorseFactory();
        DogFactory fabricaCachorros = new DogFactory();
        
        Horse meuCavalo = (Horse)fabricaCavalos.createAnimal();
        Dog meuCachorro = (Dog)fabricaCachorros.createAnimal();
        
        meuCavalo.run();
        meuCavalo.makeSound();
        
        meuCachorro.run();
        meuCachorro.makeSound();
    }
}
