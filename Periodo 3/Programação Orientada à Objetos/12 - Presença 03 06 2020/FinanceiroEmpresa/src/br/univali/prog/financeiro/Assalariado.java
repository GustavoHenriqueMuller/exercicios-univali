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
public class Assalariado extends Funcionario {
    
    private double salario;

    public Assalariado(double salario, String nome) {
        super(nome);
        this.salario = salario;
    }

    @Override
    public double calcularSalario() {
        return this.salario;
    }
    
    
}
