package exercicio1.Animais;
import exercicio1.Animais.Animal;
import exercicio1.Animais.AnimalQueCorre;

public class Cavalo extends Animal implements AnimalQueCorre {
    public Cavalo(String nome, int idade) {
        super(nome, idade);
    }
    
    public void emitirSom() {
        System.out.println("*som de cavalo*");
    }
    
    public void correr() {
        System.out.println("*cavalo correndo*");
    }
}
