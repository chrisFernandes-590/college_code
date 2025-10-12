import java.util.*;
public class NegativeInput {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.println("Enter a number: ");
            int num = sc.nextInt();

            if (num < 0) {
                throw new IllegalArgumentException("Error: Negative input is not allowed!");
            }

            System.out.println("You entered: " + num);
        } catch(IllegalArgumentException e){
            System.out.println(e.getMessage());
        }
        catch (Exception e) {
            System.out.println("Invalid input! Please enter a valid number.");
        }

        sc.close();
    }
}