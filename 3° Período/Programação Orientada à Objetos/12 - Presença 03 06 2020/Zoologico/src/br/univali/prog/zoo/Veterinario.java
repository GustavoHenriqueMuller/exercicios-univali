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
public class Veterinario {
    
    public void examinar(Animal animal){
        System.out.println("Examinando o animal "+animal.nome);
        System.out.println(animal.emitirSom());
    }
    
}
