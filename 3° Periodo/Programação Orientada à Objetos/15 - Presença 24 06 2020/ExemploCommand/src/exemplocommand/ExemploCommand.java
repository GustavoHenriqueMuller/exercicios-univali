/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplocommand;
import exemplocommand.Menu;

/**
 *
 * @author Gustavo
 */
public class ExemploCommand {

    /**
     * Esse programa mostra o funcionamento de uma pequena interface em console
     * que lida com diversos tipos de comandos do usuário através do padrão
     * de projeto Command.
     * 
     * Se ele digitar 1, um evento de print é realizado.
     * Se ele digitar qualquer outra coisa, o programa termina.
     */
    public static void main(String[] args) {
        Menu meuMenu = new Menu();
        meuMenu.run();
    }   
}
