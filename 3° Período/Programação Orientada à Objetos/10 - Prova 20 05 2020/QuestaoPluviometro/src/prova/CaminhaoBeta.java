package prova;
import prova.Caminhao;

public class CaminhaoBeta extends Caminhao {    
    public CaminhaoBeta(int tamanho) {
        super(tamanho);
    }
    
    private boolean existePluviometroDeTipo(String tipo) {
        for(int i = 0; i < pluviometros.length; i++) {
            if(pluviometros[i] != null && pluviometros[i].tipo == tipo) {
                return true;
            }
        }
        
        return false;
    }
    
    public void inserePluviometro(Pluviometro pluviometro) {
        if(!existePluviometroDeTipo(pluviometro.tipo)){
            for(int i = 0; i < pluviometros.length; i++) {
                if(pluviometros[i] == null) {
                    pluviometros[i] = pluviometro;
                    break;
                }
            }
        }
    }
}
