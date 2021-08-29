
import br.univali.prog.financeiro.Assalariado;
import br.univali.prog.financeiro.Comissionado;
import br.univali.prog.financeiro.Empresa;
import br.univali.prog.financeiro.Funcionario;
import br.univali.prog.financeiro.Horista;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author cbughi
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        //testando a logica;
        Empresa boteco = new Empresa();
        
        Funcionario funcionario1 = new Assalariado(1500, "joao");
        Funcionario funcionario2 = new Horista(15, 100, "maria");
        Funcionario funcionario3 = new Comissionado(1500, 15000, 5, "joao");
        
        boteco.adicionarFuncionario(funcionario1);
        boteco.adicionarFuncionario(funcionario2);
        boteco.adicionarFuncionario(funcionario3);
        
        System.out.println("Total despesas com funcionarios da empresa");
        System.out.println(boteco.calcularDespesas());
        
    }
    
}
