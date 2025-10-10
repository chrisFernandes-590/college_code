import java.util.ArrayList;
import java.util.Scanner;

class Donation {
    String category;
    String foodName;
    double quantity; // in kg

    public Donation(String category, String foodName, double quantity) {
        this.category = category;
        this.foodName = foodName;
        this.quantity = quantity;
    }
}

class FoodDonationSystem {
    static ArrayList<Donation> donations = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n=== NGO Food Donation Management System ===");
            System.out.println("1. Add Donation");
            System.out.println("2. View Donation Summary");
            System.out.println("3. View Total Donations");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    addDonation(sc);
                    break;
                case 2:
                    viewDonationSummary();
                    break;
                case 3:
                    viewTotalDonations();
                    break;
                case 4:
                    System.out.println("Exiting... Thank you!");
                    break;
                default:
                    System.out.println("Invalid choice! Try again.");
            }
        } while (choice != 4);

        sc.close();
    }

    public static void addDonation(Scanner sc) {
        System.out.print("Enter category (grains, pulses, fruits, vegetables): ");
        String category = sc.nextLine().trim().toLowerCase();

        System.out.print("Enter food name (e.g., wheat, rice, apple): ");
        String foodName = sc.nextLine().trim().toLowerCase();

        System.out.print("Enter quantity (in kg): ");
        double quantity = sc.nextDouble();
        sc.nextLine();

        boolean found = false;

        for (Donation d : donations) {
            if (d.category.equalsIgnoreCase(category) && d.foodName.equalsIgnoreCase(foodName)) {
                d.quantity += quantity; // update quantity
                found = true;
                System.out.println("Updated existing donation: " + foodName + " -> " + d.quantity + " kg total.");
                break;
            }
        }

        if (!found) {
            donations.add(new Donation(category, foodName, quantity));
            System.out.println("New donation added successfully.");
        }
    }

    public static void viewDonationSummary() {
        if (donations.isEmpty()) {
            System.out.println("No donations recorded yet!");
            return;
        }

        System.out.println("\n=== Donation Summary by Category ===");

        // First, find all unique categories
        ArrayList<String> categories = new ArrayList<>();
        for (Donation d : donations) {
            if (!categories.contains(d.category)) {
                categories.add(d.category);
            }
        }

        // For each category, show items
        for (String cat : categories) {
            double catTotal = 0;
            System.out.println("\n" + capitalize(cat) + ":");
            for (Donation d : donations) {
                if (d.category.equals(cat)) {
                    System.out.println("  " + capitalize(d.foodName) + " - " + d.quantity + " kg");
                    catTotal += d.quantity;
                }
            }
            System.out.println("  >> Total " + capitalize(cat) + ": " + catTotal + " kg");
        }
    }

    public static void viewTotalDonations() {
        double total = 0;
        for (Donation d : donations) {
            total += d.quantity;
        }
        System.out.println("\nTotal Food Donations: " + total + " kg");
    }


    private static String capitalize(String str) {
        if (str == null || str.isEmpty()) return str;
        return str.substring(0, 1).toUpperCase() + str.substring(1);
    }
}
