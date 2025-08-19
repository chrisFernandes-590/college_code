import java.util.Scanner;

abstract class Operations {
    Operations(double num1, double num2, Scanner scanner){
        System.out.println("Enter the 2 numbers: ");
        num1 = scanner.nextDouble();
        num2 = scanner.nextDouble();
        scanner.close();
    }

}

public class Calculator {
    public static void printBases(){}
    public static void main(String[] args) {
        
    }
}
