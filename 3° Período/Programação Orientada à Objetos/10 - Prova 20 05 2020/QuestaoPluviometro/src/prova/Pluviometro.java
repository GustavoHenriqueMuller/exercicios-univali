package prova;

public class Pluviometro {
    String tipo;
    double peso;
    double capacidade;
    
    public Pluviometro(String tipo, double peso, double capacidade) {
        this.tipo = tipo;
        this.peso = peso;
        this.capacidade = capacidade;
    }
    
    public double getPeso() {
        return peso;
    }
    
    public double getCapacidade() {
        return capacidade;
    }
    
    public String getTipo() {
        return tipo;
    }
}
