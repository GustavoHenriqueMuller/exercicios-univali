package exercicio3.Veterinario;
import exercicio3.Animais.Animal;

public class Veterinario {
    public void examinar(Animal animal) {
        System.out.println("Examinando animal...");
        animal.emitirSom();
    }
}
