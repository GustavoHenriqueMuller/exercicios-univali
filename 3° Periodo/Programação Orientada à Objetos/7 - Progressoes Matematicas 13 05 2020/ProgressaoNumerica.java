public class ProgressaoNumerica implements Progressao {    
    int first;
    int cur;
    
    public ProgressaoNumerica(int first) {
        this.first = first;
        cur = first;
    }    
    
    public int firstValue() {
        cur = first;
        return cur;
    }
    
    public int nextValue() {
        cur++;
        return cur;
    }
        
    public void printProgression(int n) {
        System.out.println(this.firstValue());
        for (int x = 1; x < n; x++) {
            System.out.println(this.nextValue());
        }
    }
    
}
