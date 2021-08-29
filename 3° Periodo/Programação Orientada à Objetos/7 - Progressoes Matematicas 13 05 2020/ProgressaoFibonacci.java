public class ProgressaoFibonacci extends ProgressaoAritmetica {
    int past;
    
    public ProgressaoFibonacci() {
        super(0, 1);
        past = 0;
    }

    public int nextValue() {
        if(cur == 0){
            cur = 1;
        } else {
            int oldCur = cur;
            cur = cur + past;
            past = oldCur;
        }
        
        return cur;
    }
}
