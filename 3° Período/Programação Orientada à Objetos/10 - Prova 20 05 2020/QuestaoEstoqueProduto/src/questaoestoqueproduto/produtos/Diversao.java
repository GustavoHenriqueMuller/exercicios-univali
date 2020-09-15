package questaoestoqueproduto.produtos;
import questaoestoqueproduto.produtos.Produto;

public class Diversao extends Produto {
    public String tipo;
    public boolean paraCriancas;
    
    public Diversao(String nome, double custo, String tipo, boolean paraCriancas) {
        super(nome, custo);
        this.tipo = tipo;
        this.paraCriancas = paraCriancas;
    }
}
