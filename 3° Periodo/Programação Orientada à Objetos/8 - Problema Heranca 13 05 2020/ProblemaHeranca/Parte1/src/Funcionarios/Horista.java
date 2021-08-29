package Funcionarios;

public class Horista extends Funcionario {
    double horasTrabalhadas;
    double dinheiroPorHora;
    
    public Horista(String nome, double horasTrabalhadas, double dinheiroPorHora) {
        super(nome);
        this.horasTrabalhadas = horasTrabalhadas;
        this.dinheiroPorHora = dinheiroPorHora;
    }
    
    public double calcularDespesa() {
        return horasTrabalhadas * dinheiroPorHora;
    }
}
