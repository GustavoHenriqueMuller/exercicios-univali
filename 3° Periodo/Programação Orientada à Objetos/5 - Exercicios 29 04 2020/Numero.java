public class Numero {
    public static int Lowest(int[] array){
        int lowest = array[0];
        for(int i = 0; i < array.length; i++){
            if(array[i] < lowest){
                lowest = array[i];
            }
        }

        return lowest;
    }
    public static int Highest(int[] array){
        int highest = array[0];
        for(int i = 0; i < array.length; i++){
            if(array[i] > highest){
                highest = array[i];
            }
        }

        return highest;
    }
    public static double Mean(int[] array){
        double mean = 0;
        for(int i = 0; i < array.length; i++){
            mean += array[i];
        }

        mean /= array.length;
        return mean;
    }
}