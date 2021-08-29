package questaoestoqueproduto.produtos;
import questaoestoqueproduto.produtos.Produto;

public class Bebida extends Produto {
    public double teorAlcoolico;
    public String marca;
    public double volume;
    
    public Bebida(String nome, double custo, double teorAlcoolico, String marca, double volume) {
        super(nome, custo);
        this.teorAlcoolico = teorAlcoolico;
        this.marca = marca;
        this.volume = volume;
    }    
}
