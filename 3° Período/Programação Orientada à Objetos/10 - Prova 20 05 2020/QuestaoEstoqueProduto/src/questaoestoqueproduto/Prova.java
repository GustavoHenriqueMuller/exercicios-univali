package questaoestoqueproduto;
import questaoestoqueproduto.kits.*;
import questaoestoqueproduto.loja.*;
import questaoestoqueproduto.produtos.*;

public class Prova {
    public static void main(String[] args) {
        KitFesta meuKitFesta = new KitFesta("Produtos da Festa do Gustavo",
                                            new Comida("Brigadeiro", 1.25, 0.01, 50),
                                            new Bebida("Água Mineral", 4, 0, "Crystal", 500));
        
        Loja minhaLoja = new Loja(new Bebida("Vodka", 45, 50, "Alguma marca de álcool", 2),
                                  new Comida("Hamburguer", 8, 0.25, 300),
                                  new Diversao("DOTA 2", 0, "MOBA", false),
                                  meuKitFesta);
        
        minhaLoja.imprimirCustoEstoque();
    }
}
