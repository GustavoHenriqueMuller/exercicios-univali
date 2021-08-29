/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman.bank;
import hangman.bank.IWordBank;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Gustavo
 */
public class SimpleWordBank implements IWordBank {
    private List<String> words;
    
    public SimpleWordBank(String... words){        
        this.words = new ArrayList<>(Arrays.asList(words));
    }
    
    @Override
    public String getWord() {
        return words.get((int) (Math.random() * words.size()));
    }

    @Override
    public void addWord(String word) {
        if(!words.contains(word)){
            words.add(word.toLowerCase());
        }
    }
}
