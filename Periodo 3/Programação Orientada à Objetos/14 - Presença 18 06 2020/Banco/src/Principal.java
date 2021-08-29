
import br.univali.cc.prog3.banco.visao.ExecutavelGUI;
import br.univali.cc.prog3.banco.visao.ExecutavelTeste;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 1978233
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String tipo = "gui";
        if (args != null && args.length >= 1){
            tipo = (args[0].equalsIgnoreCase("teste") || args[0].equalsIgnoreCase("gui")) ? args[0] : tipo;
        }
        if (tipo.equals("teste")){
            new ExecutavelTeste();
        } else {
            new ExecutavelGUI();
        }
    }
    
}
