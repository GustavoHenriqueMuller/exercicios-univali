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
public class Preguica extends Animal{

    public Preguica(String nome) {
        super(nome);
    }
    
    @Override
    public String emitirSom() {
        return "Um som de bicho preguiça vai <<aqui>>";
    }
    
    public void subirArvore(){
        System.out.println("subindo vagarosamente uma árvore");
    }
    
}
