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
abstract public class Animal {
    String nome;
    int idade;

    public Animal(String nome) {
        this.nome = nome;
        this.idade = idade;
    }
    
    abstract public String emitirSom();
}
