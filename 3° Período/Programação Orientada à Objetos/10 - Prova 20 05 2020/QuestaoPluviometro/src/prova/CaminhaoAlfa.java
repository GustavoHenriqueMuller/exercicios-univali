package prova;
import prova.Caminhao;

public class CaminhaoAlfa extends Caminhao {
    public final double pesoMax = 500.0;
    
    public CaminhaoAlfa(int tamanho) {
        super(tamanho);
    }
    
    private double somaPesoPluviometros() {
        double soma = 0.0;
        for(Pluviometro pluviometro : pluviometros) {
            if(pluviometro != null){
                soma += pluviometro.peso;
            }            
        }        
        return soma;
    }
    
    public void inserePluviometro(Pluviometro pluviometro) {
        for(int i = 0; i < pluviometros.length; i++){
            if(pluviometros[i] == null && (somaPesoPluviometros() + pluviometro.peso < pesoMax)) {
                pluviometros[i] = pluviometro;
                break;
            }
        }
    }
}
