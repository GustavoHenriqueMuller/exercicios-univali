/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.prog.zoo;

import java.util.Collection;
import java.util.TreeSet;

/**
 *
 * @author cbughi
 */
public class Zoologico {
    private Collection<Animal> jaulas;
    
    public Zoologico() {
        jaulas = new TreeSet<Animal>();
    }

    public void adicionarAnimal(Animal animal) {       
        jaulas.add(animal);
    }
    
    public Collection animais() {
        return jaulas;
    }
    
    public void cutucarAnimal(String animalNome){
        for(Animal animal : jaulas) {
            if(animal.nome == animalNome) {
                System.out.println(animal.emitirSom());
            
                if (animal instanceof AnimalQueCorre) {
                    ((AnimalQueCorre)animal).correr();
                }
            }
        }
    }
    
    public void cutucarTodos() {
        for(Animal animal : jaulas) {
            cutucarAnimal(animal.nome);
        }
    }
}
