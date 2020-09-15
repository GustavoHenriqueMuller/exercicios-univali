package exercicio2.main;
import exercicio2.Animais.*;

public class Exercicio2 {
    public static void main(String[] args) {
        Cachorro meuCachorro = new Cachorro("Totó", 8);
        Cavalo meuCavalo = new Cavalo("Pocotó", 20);
        Preguica minhaPreguica = new Preguica("Bixo Preguiça", 15);
        
        meuCachorro.emitirSom();
        meuCavalo.emitirSom();
        minhaPreguica.emitirSom();
    }    
}
