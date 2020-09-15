package exercicio4.Zoologico;
import exercicio4.Animais.*;
import exercicio4.Zoologico.Jaula;

public class Zoologico {
    public Jaula[] jaulas;
    
    public Zoologico(Animal... animais) {
        jaulas = new Jaula[animais.length];
        
        for(int i = 0; i < animais.length; i++){
            jaulas[i] = new Jaula(animais[i]);
        }
    }
    
    public void entreter() {
        for(Jaula jaula : jaulas) {
            jaula.animal.emitirSom();
           
            if(jaula.animal instanceof AnimalQueCorre) {
                AnimalQueCorre animalQueCorre = (AnimalQueCorre)jaula.animal;
                animalQueCorre.correr();
            }
        }
    }
}
