import java.util.Scanner;

public class Library {

    public static class Book {
        String title;
        String author;
        double price;

        Book(String title, String author, double price){
            this.title = title;
            this.author = author;
            this.price = price;
        }
        void displayDetails(){
            System.out.println("\nTitle: "+title+", Author: "+author+", Price: ₹"+price);
        }
    }

    static final int MAX_BOOKS = 100;
    static Book[] library = new Book[MAX_BOOKS];
    static int bookCount = 0;

    static void addBook(Scanner scanner){
        if (bookCount >= MAX_BOOKS) {
            System.out.println("You cannot any more Books");
            return;
        }
        scanner.nextLine();

        System.out.println("\nEnter the title of the book: ");
        String title = scanner.nextLine();

        System.out.println("\nEnter the name of the author: ");
        String author = scanner.nextLine();

        System.out.println("\nEnter the price of the book: ");
        double price = scanner.nextDouble();

        library[bookCount++] = new Book(title, author, price);
        System.out.println("Book added successfully");
    }

    static void displayAllBooks(){
        if(bookCount == 0){
            System.out.println("\nThe library is empty!");
            return;
        }
        System.out.println("\nList of book in the library: ");
        for(int i = 0; i < bookCount; i++){
            System.out.println("\n"+(i+1)+". ");
            library[i].displayDetails();
        }
    }

    static void totalBookCost(){
        double total = 0.0;
        for (int i = 0; i < bookCount; i++) {
            total += library[i].price;
        }
        System.out.println("\nThe total cost of the books is: "+total);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        while (true) {
            System.out.println("\n\n--- Library Management System ---");
            System.out.println("1. Add Book");
            System.out.println("2. Display All Books");
            System.out.println("3. Total Cost of Books");
            System.out.println("4. Exit");
            System.out.print("Enter your choice (1-4): ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addBook(sc);
                    break;
                case 2:
                    displayAllBooks();
                    break;
                case 3:
                    totalBookCost();
                    break;
                case 4:
                    System.out.println("Exiting Program.");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}

