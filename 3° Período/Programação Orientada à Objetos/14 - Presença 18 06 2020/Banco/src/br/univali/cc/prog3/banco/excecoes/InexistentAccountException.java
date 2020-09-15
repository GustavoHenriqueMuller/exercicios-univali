/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.excecoes;

/**
 *
 * @author Gustavo
 */
public class InexistentAccountException extends Exception{
    private int inexistentAccountNumber;
    
    public InexistentAccountException(int accountNumber){
        this.inexistentAccountNumber = accountNumber;
    }
    
    public int getInexistentAccountNumber(){
        return this.inexistentAccountNumber;
    }
}
