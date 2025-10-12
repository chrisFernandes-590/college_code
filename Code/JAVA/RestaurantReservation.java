import java.util.Scanner;

class OverBookingException extends Exception{
    public OverBookingException(String message){
        super(message);
    }
}

public class RestaurantReservation {
    public static int totalTables = 20;
    public static int bookedTables = 0;
    public static void makeReservation(int tables) throws OverBookingException{
        if (tables > totalTables - bookedTables) {
            throw new OverBookingException("Overbooking Error: Only " + (totalTables - bookedTables) + " tables available!");
        }else{
            bookedTables += tables;
            System.out.println("Reservation successful! Total booked: " + bookedTables);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Welcome to the Restaurant Reservation System");
        System.out.println("Total tables available: " + totalTables);

        while (true) {
            System.out.print("\nEnter number of tables to reserve (0 to exit): ");
            int t = sc.nextInt();
            if (t == 0) break;

            try {
                makeReservation(t);
            } catch (OverBookingException e) {
                System.out.println(e.getMessage());
            }
        }

        System.out.println("\nFinal booked tables: " + bookedTables);
        System.out.println("Tables remaining: " + (totalTables - bookedTables));
        sc.close();
    }
}
