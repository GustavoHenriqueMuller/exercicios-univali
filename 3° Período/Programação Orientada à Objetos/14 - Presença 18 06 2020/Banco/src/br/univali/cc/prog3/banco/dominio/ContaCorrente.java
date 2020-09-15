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
public class ContaCorrente extends ContaBancaria{
    
    double taxaOperacao;

    public ContaCorrente(double taxaOperacao, int numeroConta, double saldo) {
        super(numeroConta, saldo);
        this.taxaOperacao = taxaOperacao;
    }
    

    @Override
    public void sacar(double valor) throws InsufficientBalanceException {
        if (valor > 0 && this.saldo > valor+(taxaOperacao/100*valor)){
            this.saldo -= valor;
            this.saldo -= taxaOperacao/100*valor;
        } else {
            // Não há saldo suficiente; Vamos jogar uma exceção.
            // A exceção vai conter quanto de dinheiro faltou na conta para realizar o saque corretamente.
            throw new InsufficientBalanceException(- (this.saldo - valor - taxaOperacao/100*valor));
        }
    }

    @Override
    public void depositar(double valor) {
        this.saldo += valor;
        this.saldo -= taxaOperacao/100*valor;
    }

    @Override
    public String mostrarDados() {
        return "Conta: " + this.numeroConta + " | Saldo: " + this.saldo;
        
    }
    
}
