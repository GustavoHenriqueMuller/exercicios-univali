/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio;

/**
 *
 * @author 1978233
 */
public class ContaPoupanca extends ContaBancaria{
    
    double limite;

    public ContaPoupanca(double limite, int numeroConta, double saldo) {
        super(numeroConta, saldo);
        this.limite = limite;
    }

    @Override
    public void depositar(double valor) {
        this.saldo += valor;
    }

    @Override
    public void sacar(double valor){
        if (valor > 0 && this.saldo+this.limite > valor){
            this.saldo -= valor;
        } else {
            // o que fazer aqui
        }
    }

    @Override
    public String mostrarDados() {
        return "conta "+this.numeroConta+" saldo "+this.saldo+" limite "+this.limite;
    }
    
    
}
