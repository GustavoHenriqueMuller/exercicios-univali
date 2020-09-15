
public class Exercicio3 {
    public static void main(String[] args){
        System.out.println(args[0]);
        int[] intArray = Terminal.StringArrayToIntArray(args);

        for(int i = 0; i < intArray.length; i++){
            String points = "";
            for(int j = 0; j < intArray[i]; j++){
                points += "*";
            }

            Terminal.println("Aluno " + i + ": " + points);
        }

        Terminal.print("Média: " + String.valueOf(Numero.Mean(intArray)));
    }
}