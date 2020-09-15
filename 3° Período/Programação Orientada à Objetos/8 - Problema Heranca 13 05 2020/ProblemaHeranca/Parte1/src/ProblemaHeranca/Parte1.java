package ProblemaHeranca;

import Funcionarios.Comissionado;
import Funcionarios.Horista;
import Funcionarios.Assalariado;

public class Parte1 {
    public static void main(String[] args) {
        Empresa minhaEmpresa = new Empresa("Marreco Empresa");
        
        minhaEmpresa.adicionarFuncionario(new Horista("Gustavo", 8, 40));        
        minhaEmpresa.adicionarFuncionario(new Assalariado("Paulo", 3000));
        minhaEmpresa.adicionarFuncionario(new Comissionado("João", 1500, 15, 9000));
        
        minhaEmpresa.mostrarDespesas();
    }
}
