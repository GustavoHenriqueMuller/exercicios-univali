package exercicio3.main;
import exercicio3.Animais.*;
import exercicio3.Veterinario.Veterinario;

public class Exercicio3 {
    public static void main(String[] args) {
        Veterinario meuVeterinario = new Veterinario();
        
        Cachorro meuCachorro = new Cachorro("Totó", 8);
        Cavalo meuCavalo = new Cavalo("Pocotó", 20);
        Preguica minhaPreguica = new Preguica("Bixo Preguiça", 15);
        
        meuVeterinario.examinar(meuCachorro);
        meuVeterinario.examinar(meuCavalo);
        meuVeterinario.examinar(minhaPreguica);        
    }    
}
