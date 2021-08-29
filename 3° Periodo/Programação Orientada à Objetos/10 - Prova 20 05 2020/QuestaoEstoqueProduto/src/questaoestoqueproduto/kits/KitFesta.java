package questaoestoqueproduto.kits;
import questaoestoqueproduto.kits.IKitProduto;
import questaoestoqueproduto.produtos.Produto;
import questaoestoqueproduto.produtos.IProduto;

public class KitFesta implements IKitProduto {
    public String nome;
    public IProduto produtos[];
    
    public KitFesta(String nome, IProduto... produtos) {
        this.nome = nome;
        this.produtos = new IProduto[produtos.length];
        
        for(int i = 0; i < produtos.length; i++) {
            this.produtos[i] = produtos[i];
        }
    }
    
    public int getNumeroProdutos() {
        return produtos.length;
    }
    
    public IProduto getProduto(int numero){
        return produtos[numero];
    }
    
    public double getCusto() {
        double custo = 0.0;
        for(IProduto produto : produtos) {
            custo += produto.getCusto();
        }
        
        return custo;
    }
    
    public String getNome() {
        return nome + " (" + this.getClass().getSimpleName() + ")";
    }
}
