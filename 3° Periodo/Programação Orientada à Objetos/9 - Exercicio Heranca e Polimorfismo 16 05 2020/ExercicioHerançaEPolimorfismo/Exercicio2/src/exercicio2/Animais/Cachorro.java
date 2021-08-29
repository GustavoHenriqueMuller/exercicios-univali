package exercicio2.Animais;
import exercicio2.Animais.Animal;
import exercicio2.Animais.AnimalQueCorre;

public class Cachorro extends Animal implements AnimalQueCorre {
    public Cachorro(String nome, int idade) {
        super(nome, idade);
    }
    
    public void emitirSom() {
        System.out.println("*som de cachorro*");
    }
    
    public void correr() {
        System.out.println("*cahorro correndo*");
    }
}
