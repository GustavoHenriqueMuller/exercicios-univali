/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman.logic;

import hangman.bank.IWordBank;

/**
 *
 * @author 1978233
 */
public class Hangman {
    private final IWordBank bank;
    private String currentWord;
    private String displayWord;    
    private int hits;
    private int mistakes;
    private final int maxTries;
    
    public String playerName;

    public Hangman(IWordBank bank) {
        this.bank = bank;
        this.maxTries = 7;        
    }
    
    public void init() {
        this.currentWord = bank.getWord();
        this.displayWord = new String(new char[this.currentWord.length()]).replace("\0", "*");
        this.mistakes = 0;
    }

    public boolean tryLetter(char letter){
        String newDisplayWord = "";
        
        // Se a palavra atual contém a letra, adicionar mais um aos acertos.
        if(currentWord.indexOf(letter) != -1){
            hits++;
        }
        
        for (int i = 0; i < currentWord.length(); i++) {
            if (currentWord.charAt(i) == letter) {
                newDisplayWord += letter;                
            } else if (displayWord.charAt(i) != '*') {
                newDisplayWord += currentWord.charAt(i);
            } else {
                newDisplayWord += "*";
            }
        }
        
        // Se o display não mudou, então o usuário errou.
        if (displayWord.equals(newDisplayWord)){
            mistakes++;
            return false;
        }
        
        // Se o display mudou, então o usuário acertou.
        displayWord = newDisplayWord;
        return true;
    }
    
    public int getPoints() {
        // Pega a quantidade de pontos que o usuário ganhou
        // baseado em quantas perguntas acertou/errou.
        switch(mistakes){
            case 0:
                return 20;
            case 1:
                return 15;
            case 2:
                return 10;                
            case 3:
                return 8;
            case 4:
                return 7;
            case 5:
                return 6;
            case 6:
                return 5;
            default:
                if(hits > 0){
                    return 0;
                } else {
                    return -10;
                }
        }
    }
    
    public boolean hasWon(){
        return displayWord.equals(currentWord);
    }
    
    public String getDisplayWord(){
        return this.displayWord;
    }
    
    public String getCurrentWord(){
        return this.currentWord;
    }
    
    public boolean hasMoreTries(){
        return this.mistakes < this.maxTries && !this.hasWon();
    }
    
    public int getMistakes(){
        return this.mistakes;
    }
}
