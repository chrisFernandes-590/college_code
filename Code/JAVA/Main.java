import java.util.*;

class Donations {
    String category;
    String foodName;
    double quantity;

    Donations(String category, String foodName, double quantity){
        this.category = category;
        this.foodName = foodName;
        this.quantity = quantity;
    }
    static Scanner sc = new Scanner(System.in);
    
}

public class Main{
    static ArrayList<Donations> donation = new ArrayList<>();
    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Add donation 2: View donations Summary 3. View total donations");
            choice = sc.nextInt();
            sc.nextLine();
            switch (choice) {
                case 1:
                    addDonation();
                    break;
                case 2:
                    viewDonationSummary();
                    break;
                case 3:
                    viewTotalDonations();
                    break;
                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        } while (choice >= 4);
    void addDonation(){
        System.out.println("Enter the category of food (Grains, Fruits & Vegetables): ");
        String category = sc.nextLine();
        System.out.println("Enter the Name of food: ");
        String foodName = sc.nextLine();
        System.out.println("Enter the quantity of food: ");
        double quantity = sc.nextDouble();
        sc.nextLine();
        boolean flag = 0;
        for (int i = 0; i < donation.size(); i++) {
            Donations d1 = donation.get(i);
            if (d1.category.equals(category) && d1.foodName.equals(foodName)) {
                flag = 1;
                d1.quantity += quantity;
            }
        }
    }
    
}
