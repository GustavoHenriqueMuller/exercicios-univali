package prova;
import prova.Pluviometro;

public class Caminhao {
    public Pluviometro pluviometros[];
    
    public Caminhao(int tamanho) {
        pluviometros = new Pluviometro[tamanho];
    }
    
    public void inserePluviometro(Pluviometro pluviometro) {
        for(int i = 0; i < pluviometros.length; i++){
            if(pluviometros[i] == null) {
                pluviometros[i] = pluviometro;
                break;
            }
        }
    }
}
