package prova;
import prova.*;

public class Prova {
    public static void main(String[] args) {
        CaminhaoAlfa meuCaminhaoAlfa = new CaminhaoAlfa(100);
        CaminhaoBeta meuCaminhaoBeta = new CaminhaoBeta(100);
        
        meuCaminhaoAlfa.inserePluviometro(new Pluviometro("Algum tipo", 5.4, 10));
        meuCaminhaoAlfa.inserePluviometro(new Pluviometro("Algum tipo épico", 5.4, 10));
    }    
}
