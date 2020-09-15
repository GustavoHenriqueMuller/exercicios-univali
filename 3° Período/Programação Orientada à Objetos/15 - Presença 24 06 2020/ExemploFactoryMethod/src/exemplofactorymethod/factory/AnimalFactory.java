/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplofactorymethod.factory;
import exemplofactorymethod.product.Animal;

/**
 *
 * @author Gustavo
 */
public interface AnimalFactory {
    public Animal createAnimal();
}
