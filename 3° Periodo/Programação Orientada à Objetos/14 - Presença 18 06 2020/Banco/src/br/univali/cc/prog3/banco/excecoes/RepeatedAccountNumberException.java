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
public class RepeatedAccountNumberException extends Exception {
    private int numContaRepetida;
    
    public RepeatedAccountNumberException(int numContaRepetida) {
        this.numContaRepetida = numContaRepetida;
    }
    
    public int getNumContaRepetida() {
        return numContaRepetida;
    }
}
