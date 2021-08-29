/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.excecoes;
import java.lang.Exception;

/**
 *
 * @author Gustavo
 */
public class InsufficientBalanceException extends Exception {
    private double neededAmount;
    
    public InsufficientBalanceException(double neededAmount){
        this.neededAmount = neededAmount;
    }
    
    public double getNeededAmount() {
        return neededAmount;
    }
}
