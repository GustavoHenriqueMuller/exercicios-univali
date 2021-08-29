package exercicio5.Pessoas;
import exercicio5.Data;

public abstract class Pessoa {
    String nome;
    Data nascimento;
    
    public Pessoa(String nome, Data nascimento) {
        this.nome = nome;
        this.nascimento = nascimento;
    }
    
    public abstract void imprimirDados();
    public void imprimirNome() {
        System.out.println("Nome: " + this.nome + " (" + this.getClass().getSimpleName() + ")");
    }
    public void imprimirNascimento() {        
        System.out.println("Nascimento: " + Integer.toString(this.nascimento.dia) + "/" + Integer.toString(this.nascimento.mes) + "/" + Integer.toString(this.nascimento.ano));
    }
}
