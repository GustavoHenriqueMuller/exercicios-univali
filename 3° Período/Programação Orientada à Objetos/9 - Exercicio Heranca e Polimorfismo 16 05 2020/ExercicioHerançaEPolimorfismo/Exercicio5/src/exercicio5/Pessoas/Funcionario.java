package exercicio5.Pessoas;
import exercicio5.Pessoas.Pessoa;
import exercicio5.Data;

public class Funcionario extends Pessoa {
    public double salario;
    public double imposto;
    
    public Funcionario(String nome, Data data, double salario) {
        super(nome, data);
        this.salario = salario;
        this.imposto = 3;
    }
    
    public double calculaImposto() {
        return (imposto/100) * salario;
    }
    
    public void imprimirDados() {
        this.imprimirNome();
        this.imprimirNascimento();
        this.imprimirSalario();
        this.imprimirImposto();
    }
    
    public void imprimirSalario() {
        System.out.println("Salário: " + Double.toString(this.salario));
    }
    
    public void imprimirImposto() {
        System.out.println("Imposto : " + Double.toString(this.calculaImposto()));
    }
}
