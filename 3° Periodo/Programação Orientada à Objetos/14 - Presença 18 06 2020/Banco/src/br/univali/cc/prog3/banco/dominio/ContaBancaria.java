/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio;

import br.univali.cc.prog3.banco.excecoes.InsufficientBalanceException;

/**
 *
 * @author 1978233
 */
public abstract class ContaBancaria implements Imprimivel{
    int numeroConta;
    double saldo;

    public ContaBancaria(int numeroConta, double saldo) {
        this.numeroConta = numeroConta;
        this.saldo = saldo;
    }
    
    protected void transferir(double valor, ContaBancaria destino){
        try {
            this.sacar(valor);
            destino.depositar(valor);
        } catch(InsufficientBalanceException e){
            System.out.println("Você precisa de mais " + Double.toString(e.getNeededAmount()) + "R$ para realizar o saque.");
        }
    }   
    
    abstract public void sacar(double valor) throws InsufficientBalanceException;
    abstract public void depositar(double valor);
}
