package questaoestoqueproduto.produtos;
import questaoestoqueproduto.produtos.IProduto;

public abstract class Produto implements IProduto {
    // Criei uma classe Produto além da interface IProduto
    // para não redefinir os atributos "nome" e "custo" em cada classe que herda produto,
    // e também para não redefinir os métodos "getNome()" e "getCusto()".
    
    public String nome;
    public double custo;
    
    public Produto(String nome, double custo) {
        this.nome = nome;
        this.custo = custo;
    }
    
    public String getNome() {
        return nome + " (" + this.getClass().getSimpleName() + ")";
    }
    
    public double getCusto() {
        return custo;
    }
}
