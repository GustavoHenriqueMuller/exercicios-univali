package exercicio1.Animais;

public class Animal {
    public String nome;
    public int idade;
    
    public Animal(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }
    
    public void emitirSom() {
        System.out.println("*som genérico*");
    }
}
