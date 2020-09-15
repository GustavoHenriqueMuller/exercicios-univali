package Despesas.Prestadores;
import Despesas.Funcionarios.Horista;

public class Prestador extends Horista {
    String nomeDaEmpresa;
    
    public Prestador(String nome, String nomeDaEmpresa, double horasTrabalhadas, double dinheiroPorHora) {        
        super(nome, horasTrabalhadas, dinheiroPorHora);
        this.nomeDaEmpresa = nomeDaEmpresa;
    }
}
