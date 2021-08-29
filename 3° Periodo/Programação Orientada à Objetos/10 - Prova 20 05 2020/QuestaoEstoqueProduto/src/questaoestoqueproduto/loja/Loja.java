package questaoestoqueproduto.loja;
import questaoestoqueproduto.produtos.IProduto;

public class Loja {
    public IProduto produtos[];
    
    public Loja(IProduto... produtos) {
        this.produtos = new IProduto[produtos.length];
        
        for(int i = 0; i < produtos.length; i++) {
            this.produtos[i] = produtos[i];
        }
    }
    
    public double getCustoEstoque() {
        double soma = 0.0;
        
        for(IProduto produto : produtos) {
            soma += produto.getCusto();
        }
        
        return soma;
    }
    
    public void imprimirCustoEstoque() {
        System.out.println("CUSTO DO ESTOQUE\n");
        for(IProduto produto : produtos) {
            System.out.println(produto.getNome() + " : " + Double.toString(produto.getCusto()));
        }
        
        System.out.println("\nTOTAL DO ESTOQUE: " + Double.toString(getCustoEstoque()));
    }
}
