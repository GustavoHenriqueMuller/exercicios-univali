package exercicio5.CadastroPessoas;
import exercicio5.Pessoas.*;

import java.util.ArrayList;
import java.util.List;

public class CadastroPessoas {
    public List<Pessoa> pessoas;
    
    public CadastroPessoas() {
        this.pessoas = new ArrayList<Pessoa>();
    }
    
    public void cadastrarPessoa(Pessoa pessoa) {
        this.pessoas.add(pessoa);
    }
    
    public void imprimirCadastro() {
        for(Pessoa pessoa : pessoas) {
            pessoa.imprimirDados();
            System.out.println("");
        }
    }
}
