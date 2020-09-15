package exercicio5;
import exercicio5.CadastroPessoas.*;
import exercicio5.Pessoas.*;

public class TestaCadastro {
    public static void main(String[] args) {
        CadastroPessoas cadastro = new CadastroPessoas();
        
        cadastro.cadastrarPessoa(new Cliente("Cliente genérico", new Data(20, 2, 2002), 408));
        cadastro.cadastrarPessoa(new Funcionario("Funcionario genérico", new Data(10, 3, 1992), 765.54));
        cadastro.cadastrarPessoa(new Gerente("Cleberson", new Data(8, 3, 1940), 8000.95, "Ciência da Computação"));
        
        cadastro.imprimirCadastro();
    }
}
