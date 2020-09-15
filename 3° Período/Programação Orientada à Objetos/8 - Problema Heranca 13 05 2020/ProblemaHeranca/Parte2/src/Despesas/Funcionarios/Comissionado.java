package Despesas.Funcionarios;

public class Comissionado extends Funcionario {
    double salarioBase;
    double porcentagem;
    double lucroDaEmpresa;
    
    public Comissionado(String nome, double salarioBase, double porcentagem, double lucroDaEmpresa) {
        super(nome);
        this.salarioBase = salarioBase;
        this.porcentagem = porcentagem;
        this.lucroDaEmpresa = lucroDaEmpresa;
    }
    
    public double calcularDespesa() {
        return salarioBase + (porcentagem/100) * lucroDaEmpresa;
    }
}
