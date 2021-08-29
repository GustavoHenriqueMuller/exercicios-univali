package questaoestoqueproduto.produtos;
import questaoestoqueproduto.produtos.Produto;

public class Comida extends Produto {
    public double peso;
    public double calorias;
    
    public Comida(String nome, double custo, double peso, double calorias) {
        super(nome, custo);
        this.peso = peso;
        this.calorias = calorias;
    }
}
