/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.prog.financeiro;

/**
 *
 * @author cbughi
 */
abstract public class Funcionario {
    protected String nome;

    public Funcionario(String nome) {
        this.nome = nome;
    }
    
    abstract public double calcularSalario();
    
}
