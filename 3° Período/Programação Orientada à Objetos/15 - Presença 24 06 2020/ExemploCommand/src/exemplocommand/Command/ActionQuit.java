/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplocommand.Command;
import exemplocommand.Command.IAction;

/**
 *
 * @author Gustavo
 */
public class ActionQuit implements IAction {
    @Override
    public void execute() {
        System.exit(0);
    }    
}
