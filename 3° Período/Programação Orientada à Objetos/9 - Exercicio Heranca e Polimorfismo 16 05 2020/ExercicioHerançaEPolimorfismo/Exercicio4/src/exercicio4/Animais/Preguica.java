package exercicio4.Animais;
import exercicio4.Animais.Animal;

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
