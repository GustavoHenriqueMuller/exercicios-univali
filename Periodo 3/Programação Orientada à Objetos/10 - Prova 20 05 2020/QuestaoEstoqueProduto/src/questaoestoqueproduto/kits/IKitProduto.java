package questaoestoqueproduto.kits;
import questaoestoqueproduto.produtos.IProduto;

public interface IKitProduto extends IProduto {
    public int getNumeroProdutos();
    public IProduto getProduto(int numero);
}
