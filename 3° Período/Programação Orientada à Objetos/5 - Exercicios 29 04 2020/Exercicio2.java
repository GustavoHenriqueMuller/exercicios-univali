public class Exercicio2{
    public static void main(String[] args){
        int[] argsInt = Terminal.StringArrayToIntArray(args);

        // Imprime o maior valor do array
        Terminal.println("Maior valor: " + String.valueOf(Numero.Highest(argsInt)));

        // Imprime o menor valor do array
        Terminal.println("Menor valor: " + String.valueOf(Numero.Lowest(argsInt)));

        // Imprime a média do array
        Terminal.println("Média: " + String.valueOf(Numero.Mean(argsInt)));
    }    
}