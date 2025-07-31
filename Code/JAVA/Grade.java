import java.util.Scanner;

public class Grade {
    static double getPercentage(Scanner scanner){
        while (true) {
            System.out.println("\nEnter your percentage %: ");
            double percentage = scanner.nextDouble();
            if(percentage >= 0 && percentage <= 100){
                return percentage;
            }else{
                System.out.println("Enter a valid percentage! Try again");
            }
        }
    }

    static char determineGrade(double percentage){
        if (percentage >= 91) return 'A';
        if (percentage >= 81) return 'B';
        if (percentage >= 61) return 'C';
        if (percentage >= 41) return 'D';
        return 'F';
    }

    static void displayResult(char grade){
        System.out.printf("You recived a %c grade\n", grade);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double percentage = getPercentage(sc);
        char grade = determineGrade(percentage);
        displayResult(grade);
    }
}
