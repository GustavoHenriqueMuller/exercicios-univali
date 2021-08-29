/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman.logic;

/**
 *
 * @author Gustavo
 */
public class Player implements Comparable<Player> {
    public String name;
    public Integer points;
    
    public Player(String name, int points){
        this.name = name;
        this.points = points;
    }

    @Override
    public int compareTo(Player t) {
        return this.name.compareTo(t.name);
    }
}
