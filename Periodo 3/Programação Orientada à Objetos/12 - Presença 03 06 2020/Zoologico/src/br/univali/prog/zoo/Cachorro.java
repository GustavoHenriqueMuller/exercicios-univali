/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.prog.zoo;

/**
 *
 * @author cbughi
 */
public class Cachorro extends Animal implements AnimalQueCorre{

    public Cachorro(String nome) {
        super(nome);
    }

    @Override
    public String emitirSom() {
        return "au au";
    }
    
    @Override
    public void correr(){
        System.out.println("Estou correndo como um cachorro deve correr...");
    }
    
}
