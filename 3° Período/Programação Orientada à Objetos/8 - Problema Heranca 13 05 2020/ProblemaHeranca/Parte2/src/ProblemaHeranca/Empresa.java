package ProblemaHeranca;

import Despesas.Faturas.*;
import Despesas.Funcionarios.*;
import Despesas.Prestadores.*;
import Despesas.Despesa;

import java.util.ArrayList;
import java.util.List;

public class Empresa {
    String nome;
    public List<Despesa> despesas;
    
    public Empresa(String nome) {
        this.nome = nome;
        this.despesas = new ArrayList<Despesa>();
    }
    
    public void adicionarDespesa(Despesa despesa) {
        this.despesas.add(despesa);
    }    
   
    public double calcularDespesa() {
        double valorDespesas = 0;
        
        for(Despesa despesa : despesas) {
            valorDespesas += despesa.calcularDespesa();            
        }
      
        return valorDespesas;
    }
    
    public void mostrarDespesas() {
        System.out.println("Despesas da empresa '" + this.nome + "' = " + Double.toString(this.calcularDespesa()));
    }
}
