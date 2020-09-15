package exercicio4;
import exercicio4.Animais.*;
import exercicio4.Zoologico.*;

public class Exercicio4 {
    public static void main(String[] args) {
        Cachorro meuCachorro = new Cachorro("Totó", 8);
        Cavalo meuCavalo = new Cavalo("Pocotó", 20);
        Preguica minhaPreguica = new Preguica("Bixo Preguiça", 15);
        
        Zoologico meuZoologico = new Zoologico(meuCachorro, meuCavalo, minhaPreguica);
        
        meuZoologico.entreter();
    }    
}
