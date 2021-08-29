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
public class Horista extends Funcionario{
    
    private double valorHora;
    private double qtdeHoras;

    public Horista(double valorHora, double qtdeHoras, String nome) {
        super(nome);
        this.valorHora = valorHora;
        this.qtdeHoras = qtdeHoras;
    }
    

    public void setQtdeHoras(double qtdeHoras) {
        this.qtdeHoras = qtdeHoras;
    }

    @Override
    public double calcularSalario() {
        return this.valorHora*this.qtdeHoras;
    }
    
}
