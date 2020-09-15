package exercicio5.Pessoas;
import exercicio5.Pessoas.Funcionario;
import exercicio5.Data;

public class Gerente extends Funcionario {
    public String area;
    
    public Gerente(String nome, Data data, double salario, String area) {
        super(nome, data, salario);
        this.imposto = 5;
        this.area = area;
    }
    
    public void imprimirDados() {
        this.imprimirNome();
        this.imprimirNascimento();
        this.imprimirSalario();
        this.imprimirImposto();
        this.imprimirArea();
    }
    
    public void imprimirArea() {
        System.out.println("Área de trabalho: " + area);
    }
}
