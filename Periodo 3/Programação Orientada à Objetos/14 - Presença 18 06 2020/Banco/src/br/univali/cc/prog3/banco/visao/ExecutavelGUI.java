/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.visao;

import br.univali.cc.prog3.banco.dominio.Banco;
import br.univali.cc.prog3.banco.dominio.ContaCorrente;
import br.univali.cc.prog3.banco.dominio.ContaPoupanca;
import javax.swing.JOptionPane;
import br.univali.cc.prog3.banco.excecoes.RepeatedAccountNumberException;

/**
 *
 * @author 1978233
 */
public class ExecutavelGUI {
    
    Banco bb;

    public ExecutavelGUI() {
        bb = new Banco();
        menuPrincipal();
    }

    private void menuPrincipal() {
        String[] opcoes = {"Criar CC","Criar CP","Selecionar","Remover","Relatorio","Transferir","Sair"};
        //Object teste = JOptionPane.showInputDialog(null, "", "Menu principal", 0, null, opcoes, null);
        
        int opcao = JOptionPane.showOptionDialog(null, "Escolha uma opção", "Menu principal", 0, -1, null, opcoes, 0);
        
        switch (opcao){
            case 0: criarContaCorrente(); break;
            case 1: criarContaPoupanca(); break;
            case 2: selecionarConta();break;
            case 3: removerConta();break;
            case 4: relatorio();break;
            case 5: transferir();break;
        }
        
        if (opcao != 6){
            this.menuPrincipal();
        }
    }

    private void criarContaCorrente() {
        double taxa = Double.parseDouble(JOptionPane.showInputDialog("Informe a taxa"));
        double saldoInicial = Double.parseDouble(JOptionPane.showInputDialog("Informe o saldo inicial"));
        int numeroConta = Integer.parseInt(JOptionPane.showInputDialog("Informe o numero da conta"));
        
        ContaCorrente cc = new ContaCorrente(taxa, numeroConta, saldoInicial);
            
        try {
            bb.inserirConta(cc);
        } catch(RepeatedAccountNumberException e) {
            System.out.println("Uma conta corrente de código " + Integer.toString(e.getNumContaRepetida()) + " já existe.");
        }
    }
    
    private void criarContaPoupanca() {
        double limite = Double.parseDouble(JOptionPane.showInputDialog("Informe o limite"));
        double saldoInicial = Double.parseDouble(JOptionPane.showInputDialog("Informe o saldo inicial"));
        int numeroConta = Integer.parseInt(JOptionPane.showInputDialog("Informe o numero da conta"));
        
        ContaPoupanca cc = new ContaPoupanca(limite, numeroConta, saldoInicial);
            
        try {
            bb.inserirConta(cc);
        } catch(RepeatedAccountNumberException e) {
            System.out.println("Uma conta de poupança de código " + Integer.toString(e.getNumContaRepetida()) + " já existe.");
        }
    }
    
    private void transferir(){
        int contaOrigem = Integer.parseInt(JOptionPane.showInputDialog("numero conta origem"));
        int contaDestino = Integer.parseInt(JOptionPane.showInputDialog("numero conta destino"));
        double valor = Double.parseDouble(JOptionPane.showInputDialog("Informe o valor de transferencia"));
        this.bb.transferir(contaOrigem, contaDestino, valor);
        JOptionPane.showMessageDialog(null, "tudo certo, podemos ir embora!");
    }
    

    private void selecionarConta() {
        JOptionPane.showMessageDialog(null, "Não implementado");
    }

    private void removerConta() {
        JOptionPane.showMessageDialog(null, "Não implementado");
    }

    private void relatorio() {
        JOptionPane.showMessageDialog(null, bb.mostrarDados());
    }
}
