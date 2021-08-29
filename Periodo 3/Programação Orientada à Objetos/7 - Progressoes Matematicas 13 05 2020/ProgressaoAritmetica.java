public class ProgressaoAritmetica extends ProgressaoNumerica {
    int razao;
    
    public ProgressaoAritmetica(int primeiroTermo, int razao) {
        super(primeiroTermo);
        this.razao = razao;
    }
    
    public int nextValue() {
        cur += razao;
        return cur;
    }
}
