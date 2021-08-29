package Despesas.Faturas;
import Despesas.Despesa;

public class Fatura implements Despesa {
    String tipo;
    double custoPorHora;
    double horasUsadas;
    
    public Fatura(String tipo, double custoPorHora, double horasUsadas){
        this.tipo = tipo;
        this.custoPorHora = custoPorHora;
        this.horasUsadas = horasUsadas;
    }
    
    public double calcularDespesa() {
        return custoPorHora * horasUsadas;
    }
}
