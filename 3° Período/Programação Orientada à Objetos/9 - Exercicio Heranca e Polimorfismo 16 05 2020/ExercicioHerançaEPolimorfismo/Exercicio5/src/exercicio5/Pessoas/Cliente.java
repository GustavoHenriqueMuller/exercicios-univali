package exercicio5.Pessoas;
import exercicio5.Pessoas.Pessoa;
import exercicio5.Data;
        
public class Cliente extends Pessoa {
    public int codigo;
    
    public Cliente(String nome, Data nascimento, int codigo) {
        super(nome, nascimento);
        this.codigo = codigo;
    }
    
    public void imprimirDados() {
        this.imprimirNome();
        this.imprimirNascimento();
        this.imprimirCodigo();
    }
    
    public void imprimirCodigo() {
        System.out.println("Código: " + Integer.toString(codigo));
    }
}
