package Funcionarios;

abstract public class Funcionario {
    String nome;
    
    public Funcionario(String nome){
        this.nome = nome;
    }
    
    public abstract double calcularDespesa();
}
