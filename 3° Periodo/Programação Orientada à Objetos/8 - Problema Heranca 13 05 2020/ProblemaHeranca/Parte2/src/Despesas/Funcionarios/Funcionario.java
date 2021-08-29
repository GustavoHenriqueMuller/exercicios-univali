package Despesas.Funcionarios;
import Despesas.Despesa;

abstract public class Funcionario implements Despesa {
    String nome;
    
    public Funcionario(String nome){
        this.nome = nome;
    }
}
