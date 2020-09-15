package Funcionarios;

public class Assalariado extends Funcionario {
    double salario;
    
    public Assalariado(String nome, double salario) {
        super(nome);
        this.salario = salario;
    }
    
    public double calcularDespesa() {
        return salario;
    }
}
