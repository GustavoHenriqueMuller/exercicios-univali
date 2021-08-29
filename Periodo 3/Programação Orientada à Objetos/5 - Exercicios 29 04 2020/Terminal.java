
public class Terminal {
    // Converte um vetor de string para um vetor de inteiro
    public static int[] StringArrayToIntArray(String[] array){
        int[] intArray = new int[array.length];
        for(int i = 0; i < intArray.length; i++){
            intArray[i] = Integer.parseInt(array[i]);
        }

        return intArray;
    }

    // Converte um vetor de inteiro para um vetor de string
    public static String[] IntArrayToStringArray(int[] array){
        String[] stringArray = new String[array.length];
        for(int i = 0; i < stringArray.length; i++){
            stringArray[i] = Integer.toString(array[i]);
        }

        return stringArray;
    }

    // Mostra um valor na tela e desce uma linha
    public static void println(String text){
        System.out.println(text);
    }

    // Mostra um valor na tela
    public static void print(String text){
        System.out.print(text);
    }

    // Mostra um vetor de tipo genérico na tela
    public static <T> void printArray(T[] array){
        print("{");
        for(int i = 0; i < array.length; i++){
            print(array[i].toString());
            
            if(i < array.length - 1){
                print(", ");
            }            
        }
        print("}\n");
    }
}