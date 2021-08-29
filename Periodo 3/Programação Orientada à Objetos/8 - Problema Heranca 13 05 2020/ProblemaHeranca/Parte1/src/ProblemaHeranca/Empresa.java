package ProblemaHeranca;
import Funcionarios.Funcionario;
import java.util.ArrayList;
import java.util.List;

public class Empresa {
    String nome;
    public List<Funcionario> funcionarios;
    
    public Empresa(String nome) {
        this.nome = nome;
        this.funcionarios = new ArrayList<Funcionario>();
    }
    
    public void adicionarFuncionario(Funcionario funcionario) {
        this.funcionarios.add(funcionario);
    }
    
    public double calcularDespesa() {
        double despesa = 0;
        for(Funcionario funcionario : funcionarios) {
            despesa += funcionario.calcularDespesa();
        }
        
        return despesa;
    }
    
    public void mostrarDespesas() {
        System.out.println("Despesas da empresa '" + this.nome + "' = " + Double.toString(this.calcularDespesa()));
    }
}
