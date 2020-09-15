public class Exercicio4 {
    // Funções utilitárias    
    public static void PrintFibs(int n){
        int firstNumber = 1;
        int secondNumber = 1;

        while(secondNumber < n){
            System.out.println(Integer.toString(secondNumber));

            int oldSecondNumber = secondNumber;
            secondNumber += firstNumber;
            firstNumber = oldSecondNumber;
        }
    }
    public static void PrintFacts(int n){
        for(int i = 1; i <= n; i++){
            long fact = 1;
            for(int j = i; j > 0; j--){
                fact *= j;
            }

            Terminal.println(Long.toString(fact));
        }
    }
    public static int Fact(int n){
        if(n == 1 || n == 0){
            return 1;
        } else {
            return n * Fact(n-1);
        }
    }

    // Questões
    public static void Questao1(){
        for(int i = 150; i <= 300; i++){
            System.out.println("Valor: " + Integer.toString(i));
        }
    }
    public static void Questao2(){
        int sum = 0;
        for(int i = 1; i <= 1000; i++){
            sum += i;
        }

        System.out.println("Soma: " + sum);
    }
    public static void Questao3(){
        for(int i = 1; i <= 100; i++){
            if(i % 3 == 0){
                System.out.println(i);
            }
        }
    }
    public static void Questao4(){
        PrintFacts(10);
    }
    public static void Questao5(){
        PrintFacts(20);
        Terminal.println("=======================");
        PrintFacts(30);
        Terminal.println("=======================");
        PrintFacts(40);
        Terminal.println("=======================");
    }
    public static void Questao6(){
        PrintFibs(100);
    }
    public static void Questao7(int number){
        int x = number;

        while(x != 1){
            if(x % 2 == 0){
                x /= 2;
            } else {
                x = (3 * x) + 1;
            }

            Terminal.println(Integer.toString(x));
        }
    }
    public static void Questao8(int number){
        for(int i = 1; i <= number; i++){
            Terminal.print("\n");
            for(int j = 1; j <= i; j++){
                Terminal.print(Integer.toString(j * i) + " ");
            }
        }
    }

    public static void main(String[] args){
        // Chamar as questões aqui
    }
}