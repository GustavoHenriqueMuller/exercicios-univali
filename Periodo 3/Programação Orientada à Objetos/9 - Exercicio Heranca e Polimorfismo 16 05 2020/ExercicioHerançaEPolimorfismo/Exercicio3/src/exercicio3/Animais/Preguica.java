package exercicio3.Animais;
import exercicio3.Animais.Animal;

public class Preguica extends Animal {
    public Preguica(String nome, int idade) {
        super(nome, idade);
    }
    
    public void emitirSom() {
        System.out.println("*som de preguica*");
    }
    
    public void subirEmArvore() {
        System.out.println("*subi em árvore*");
    }
}
