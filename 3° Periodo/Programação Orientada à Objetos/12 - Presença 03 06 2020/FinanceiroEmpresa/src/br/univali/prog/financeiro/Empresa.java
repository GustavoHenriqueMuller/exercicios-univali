/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.prog.financeiro;

import java.util.Collection;
import java.util.HashSet;

/**
 *
 * @author cbughi
 */
public class Empresa {
    
    private Collection<Funcionario> funcionarios;

    public Empresa() {
        funcionarios = new HashSet<>();
    }
    
    public void adicionarFuncionario(Funcionario funcionario){
        funcionarios.add(funcionario);
    }
    
    public double calcularDespesas(){
        double despesas = 0;
        for (Funcionario funcionario:funcionarios){
            despesas += funcionario.calcularSalario();
        }
        return despesas;
    }    
}