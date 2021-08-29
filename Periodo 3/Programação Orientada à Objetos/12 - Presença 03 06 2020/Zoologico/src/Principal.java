import br.univali.prog.zoo.Animal;
import br.univali.prog.zoo.Cachorro;
import br.univali.prog.zoo.Cavalo;
import br.univali.prog.zoo.Preguica;
import br.univali.prog.zoo.Veterinario;
import br.univali.prog.zoo.Zoologico;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author cbughi
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Principal principal = new Principal();
        System.out.println("---------------------------------------------------------");
        principal.exercicio2();
        System.out.println("---------------------------------------------------------");
        principal.exercicio3();
        System.out.println("---------------------------------------------------------");
        principal.exercicio4();
    }
    
    public void exercicio2(){
        Animal animal;
        
        animal = new Cachorro("cao");
        System.out.println(animal.emitirSom());

        animal = new Cavalo("alazão");
        System.out.println(animal.emitirSom());

        animal = new Preguica("preguiça");
        System.out.println(animal.emitirSom());
        
    }
    
    public void exercicio3(){
       
        Animal animal1 = new Cachorro("cao");
        Animal animal2 = new Cavalo("alazão");
        Animal animal3 = new Preguica("preguiça");
        
        Veterinario joao = new Veterinario();
        
        joao.examinar(animal1);
        joao.examinar(animal2);
        joao.examinar(animal3);
    }
    
    public void exercicio4() {
        //limitei a 3 animais por preguiça.
        Animal animal1 = new Cachorro("cao");
        Animal animal2 = new Cavalo("alazão");
        Animal animal3 = new Preguica("preguiça");
        
        Zoologico zooPomerode = new Zoologico();
        zooPomerode.adicionarAnimal(animal1);
        zooPomerode.adicionarAnimal(animal2);
        zooPomerode.adicionarAnimal(animal3);
        zooPomerode.cutucarTodos();
    }    
}
