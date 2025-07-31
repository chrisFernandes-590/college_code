import java.util.Scanner;

public class Shop {

    static final String[] menu = {"Espresso", "Cappuccino", "Latte", "Mocha", "Americano"};
    static final double[] prices = {120, 150, 170, 180, 130};
    static final int[] qty = new int[menu.length];

    static final double DISCOUNT_THRESHOLD = 500.00;
    static final double DISCOUNT_RATE = 0.10;
    static final double TAX_RATE = 0.05;

    static double readOrder(Scanner scanner){
        double subtotal = 0.0;
        while (true) {
            System.out.println("\n---- MENU ----");
            for(int i = 0; i < menu.length; i++){
                System.out.printf("%d. %-12s ₹%.2f\n", i+1, menu[i], prices[i]);
            }
            System.out.println("Enter item number (0 to finish): ");
            int choice = scanner.nextInt();

            if (choice == 0) break;

            if (choice >= 1 && choice <= menu.length) {
                int index = choice - 1;
                System.out.println("Enter the quantity: ");
                int quantity = scanner.nextInt();

                qty[index] += quantity;
                double itemTotal = prices[index] * quantity;
                subtotal += itemTotal;
                System.out.printf("Added %d x %s\n", quantity, menu[index]);
            } else{
                System.out.println("The choice is Invalid! Try again"); 
            }
        }
        return subtotal;
    }

    static double calculateDiscount(double subtotal){
        if(subtotal >= DISCOUNT_THRESHOLD){
            return subtotal * DISCOUNT_RATE;
        }
        return 0.0;
    }

    static double calculateTax(double amountAfterDiscount){
        return amountAfterDiscount * TAX_RATE;
    }

    static void printRecipt(double subtotal, double discount, double tax, double total){
        System.out.println("\n---- Recipt ----");
        for (int i = 0; i < menu.length; i++) {
            if(qty[i] > 0){
                double itemTotal = prices[i] * qty[i];
                System.out.printf("%-12s x %d = ₹%.2f\n", menu[i], qty[i], itemTotal);
            }
        }
        System.out.println("-----------------------------");
        System.out.printf("Subtotal   : ₹%.2f\n", subtotal);
        System.out.printf("Discount   : -₹%.2f\n", discount);
        System.out.printf("Tax        : +₹%.2f\n", tax);
        System.out.printf("Total      : ₹%.2f\n", total);
        System.out.println("-----------------------------");
        System.out.println("Thank you for visiting!");
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double subtotal = readOrder(sc);
        double discount = calculateDiscount(subtotal);
        double amountAfterDiscount = subtotal - discount;
        double tax = calculateTax(amountAfterDiscount);
        double total = amountAfterDiscount + tax;

        printRecipt(subtotal, discount, tax, total);

        sc.close();
    }
}
