/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplobridge;
import exemplobridge.Abstract.*;
import exemplobridge.Concrete.*;

/**
 *
 * @author Gustavo
 */
public class ExemploBridge {

    /**
     * Esse código mostra um exemplo de como o padrão de projeto Bridge poderia
     * ser usado em um jogo eletrônico, onde o vilão e o herói são personagens,
     * Personagem seria a abstração enquanto herói e vilão seriam a implementação.
     */
    public static void main(String[] args) {
        Hero meuHeroi = new Hero();
        Villain meuVilao = new Villain();
        
        meuHeroi.move();
        meuHeroi.speak("Vou derrotar o vilão");
        
        meuVilao.move();
        meuVilao.speak("Vou derrotar o herói");
    }
}
