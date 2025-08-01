import java.util.Scanner;

public class Bank {
    static double bankBalance = 0.0;

    static double checkBalance(double bankBalance){
        System.out.printf("\nCurrent Balance: %.2f", bankBalance);
        return bankBalance;
    }

    static void Deposit(Scanner scanner){
        int counter = 3;
        while (true) {
            System.out.println("\nEnter the amount you want to deposit: ");
            double amount = scanner.nextDouble();
            if (amount > 0) {
                bankBalance += amount;
                System.out.println("\nAmount successfully deposited.");
                checkBalance(bankBalance);
                break;
            }else{
                counter--;
                if(counter == 0)break;
                System.out.println("\nEnter a valid amount");
            }
        }
    }

    static void Withdraw(Scanner scanner){
        int counter = 3;
        while (true) {
            System.out.println("\nEnter the amount you want to Withdraw: ");
            double amount = scanner.nextDouble();
            if (amount <= bankBalance && amount > 0) {
                bankBalance -= amount;
                System.out.printf("\nYou withdrew: %.2f", amount);
                checkBalance(bankBalance);
                break;
            }else{
                counter--;
                if(counter == 0)break;
                System.out.println("\nEnter a valid amount");
            }
        }
    }

    static void askInput(Scanner scanner){
        while (true) {
            System.out.println("\n\n\n----- Welcome to the Bank -----");
            System.out.println("What would you like to do (1-4) ?");
            System.out.println("\n1. Check Balance \n2. Deposit \n3. Withdraw \n4. EXIT \n");
            int choice = scanner.nextInt();
    
            if(choice == 4) break;

                switch (choice) {
                    case 1:
                        checkBalance(bankBalance);
                        break;
                    case 2:
                        Deposit(scanner);
                        break;
                    case 3:
                        Withdraw(scanner);
                        break;
                
                    default:
                        System.out.println("You entered an Invalid Choice! Try again");
                        break;
                }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        askInput(sc);

    }
}
