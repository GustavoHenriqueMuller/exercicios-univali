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
public class Cavalo extends Animal implements AnimalQueCorre{

    public Cavalo(String nome) {
        super(nome);
    }

    @Override
    public String emitirSom() {
        return "emitindo som de cavalo, essa onomatopeia eu não sei fazer...";
    }
    
    @Override
    public void correr(){
        System.out.println("Um cavalo galopando lindamente");
    }
    
}
