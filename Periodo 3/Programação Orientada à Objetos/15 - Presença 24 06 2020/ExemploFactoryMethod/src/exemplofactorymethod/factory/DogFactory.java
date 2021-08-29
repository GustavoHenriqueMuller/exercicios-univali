/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplofactorymethod.factory;
import exemplofactorymethod.factory.AnimalFactory;
import exemplofactorymethod.product.Animal;
import exemplofactorymethod.product.Dog;

/**
 *
 * @author Gustavo
 */
public class DogFactory implements AnimalFactory {
    @Override
    public Animal createAnimal() {
        return new Dog();
    }
}
