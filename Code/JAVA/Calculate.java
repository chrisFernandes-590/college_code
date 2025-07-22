import java.util.Scanner;

public class Calculate {
    // Discount calculation
    public static double calculateDiscount(double amount, double discountThreshold, double discountRate){
        if (amount < discountThreshold) {
            return amount;
        }
        double amountAfterDiscount = amount - (amount * discountRate);
        return amountAfterDiscount;
    };

    // Tax Calculation
    public static double calculateTax(double amountAfterDiscount, double taxRate){
        double taxApplicable = amountAfterDiscount * taxRate;
        return taxApplicable;
    };

    // Show Menu
    public static void readMenu(String menu[], double prices[], int quantity[]){
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < menu.length; i++) {
            System.out.println("\n"+(i + 1)+"."+menu[i]+" - ₹"+prices[i]);
        }

        while (true) {
            System.out.println("What would you like to have ?");
            int choice = sc.nextInt();
            System.out.println("How much you would like to order");
            int qnt = sc.nextInt();
            
            quantity[choice - 1] = qnt;
            System.out.println("Anything Else? (1 - Yes / 2 - No)");
            int ans = sc.nextInt();

            
        }
    };


    // MAIN FUNCTION
    public static void main(String[] args) {
        // Initialising the input arrays
        String[] menu = {"Espresso", "Cappuccino", "Latte", "Mocha", "Americano"};
        double[] prices = {120, 150, 170, 180, 130};
        int[] quantity = {0, 0, 0, 0, 0};

        // Constant variables for the program
        double discountThreshold = 500.0;
        double discountRate = 0.10;
        double taxRate = 0.05;

        double total = calculateDiscount(500.00, discountThreshold, discountRate);
        double tax = calculateTax(total, taxRate);
        System.out.println(tax);
        readMenu(menu, prices, quantity);
    }
}
