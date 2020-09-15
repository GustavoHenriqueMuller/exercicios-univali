package exercicio1.Animais;
import exercicio1.Animais.Animal;
import exercicio1.Animais.AnimalQueCorre;

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
