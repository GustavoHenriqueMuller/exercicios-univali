/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio;

import java.util.ArrayList;
import java.util.List;
import br.univali.cc.prog3.banco.excecoes.RepeatedAccountNumberException;
import br.univali.cc.prog3.banco.excecoes.InexistentAccountException;

/**
 *
 * @author 1978233
 */
public class Banco implements Imprimivel{
    
    List<ContaBancaria> contas;

    public Banco() {
        contas = new ArrayList<>();
    }
    
    public void inserirConta(ContaBancaria conta) throws RepeatedAccountNumberException{
        for(ContaBancaria contaBancaria : contas){
            if(conta.numeroConta == contaBancaria.numeroConta) {
                // Uma conta de número igual já existe. Logo, jogamos uma exceção.
                throw new RepeatedAccountNumberException(conta.numeroConta);
            }
        }
        
        this.contas.add(conta);
    }
    
    public void removerConta(ContaBancaria conta){
        this.contas.remove(conta);
    }

    public void transferir(int contaOrigem, int contaDestino, double valor){
        try {
            ContaBancaria origem = this.buscarConta(contaOrigem);
            ContaBancaria destino = this.buscarConta(contaDestino);
            
            origem.transferir(valor, destino);
        } catch(InexistentAccountException e) {
            System.out.println("A conta de origem ou de destino não existe. ID da conta não existente: " + Integer.toString(e.getInexistentAccountNumber()));
        }
    }    
    
    public ContaBancaria buscarConta(int numero) throws InexistentAccountException{
        for(ContaBancaria conta:contas){
            if (conta.numeroConta == numero){
                return conta;
            }
        }
        
        // A conta não foi encontrada. Jogamos uma exceção.
        throw new InexistentAccountException(numero);
    }

    @Override
    public String mostrarDados() {
        String resultado = "";
        for(ContaBancaria conta:contas){
            resultado += "\n" + conta.mostrarDados();
        }
        return resultado;
    }
}
