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
public class Comissionado extends Funcionario{
    
    private double salarioBase;
    private double totalVendas;
    private double comissao;

    public Comissionado(double salarioBase, double totalVendas, double comissao, String nome) {
        super(nome);
        this.salarioBase = salarioBase;
        this.totalVendas = totalVendas;
        this.comissao = comissao;
    }

    @Override
    public double calcularSalario() {
        return this.salarioBase + (this.totalVendas*this.comissao/100);
    }

    public void setTotalVendas(double totalVendas) {
        this.totalVendas = totalVendas;
    }
    
}
