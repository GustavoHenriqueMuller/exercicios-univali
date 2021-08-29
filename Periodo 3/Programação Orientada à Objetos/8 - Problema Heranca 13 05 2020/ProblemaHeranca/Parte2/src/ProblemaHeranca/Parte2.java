package ProblemaHeranca;
import Despesas.Faturas.*;
import Despesas.Funcionarios.*;
import Despesas.Prestadores.*;

public class Parte2 {    
    public static void main(String[] args) {
        Empresa minhaEmpresa = new Empresa("Marreco Empresa");
        
        minhaEmpresa.adicionarDespesa(new Horista("Gustavo", 8, 40));        
        minhaEmpresa.adicionarDespesa(new Assalariado("Paulo", 3000));
        minhaEmpresa.adicionarDespesa(new Comissionado("João", 1500, 15, 9000));        
        minhaEmpresa.adicionarDespesa(new Prestador("Zé Bostola", "Coca-Cola", 8, 20));
        minhaEmpresa.adicionarDespesa(new Fatura("Conta de Eletricidade", 400, 24));
        
        minhaEmpresa.mostrarDespesas();
    }
}
