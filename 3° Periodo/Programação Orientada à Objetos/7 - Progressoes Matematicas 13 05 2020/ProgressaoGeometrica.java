public class ProgressaoGeometrica extends ProgressaoAritmetica {
    public ProgressaoGeometrica(int primeiroTermo, int razao) {
        super(primeiroTermo, razao);
    }
    
    public int nextValue() {
        cur *= razao;
        return cur;
    }
}
