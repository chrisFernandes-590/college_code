import java.util.Scanner;

class Student {
    private int rollNumber;
    private String name;
    private String className;

    public Student() {}

    public Student(int rollNumber, String name, String className) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.className = className;
    }

    public int getRollNumber() {
        return rollNumber;
    }

    public String getName() {
        return name;
    }

    public String getClassName() {
        return className;
    }

    public void displayDetails() {
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Name: " + name);
        System.out.println("Class: " + className);
    }

    public void calculatePerformance() {}
}

class Result extends Student {
    private double mark1;
    private double mark2;
    private double mark3;
    private double percentage;
    private char grade;
    private static int totalResults = 0;

    public Result(int rollNumber, String name, String className, double mark1, double mark2, double mark3) {
        super(rollNumber, name, className);
        this.mark1 = mark1;
        this.mark2 = mark2;
        this.mark3 = mark3;
        totalResults++;
    }

    public void calculatePerformance() {
        percentage = (mark1 + mark2 + mark3) / 3;
        if (percentage >= 85) grade = 'A';
        else if (percentage >= 70) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else grade = 'F';
    }

    public void displayDetails() {
        super.displayDetails();
        System.out.println("Marks: " + mark1 + ", " + mark2 + ", " + mark3);
        System.out.println("Percentage: " + String.format("%.2f", percentage) + "%");
        System.out.println("Grade: " + grade);
        System.out.println("---------------------------");
    }

    public static int getTotalResults() {
        return totalResults;
    }
}

public class StudentManagement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        sc.nextLine();
        Result[] students = new Result[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for student " + (i + 1) + ":");
            System.out.print("Roll Number: ");
            int roll = sc.nextInt();
            sc.nextLine();
            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Class Name: ");
            String cls = sc.nextLine();
            System.out.print("Mark 1: ");
            double m1 = sc.nextDouble();
            System.out.print("Mark 2: ");
            double m2 = sc.nextDouble();
            System.out.print("Mark 3: ");
            double m3 = sc.nextDouble();
            sc.nextLine();
            students[i] = new Result(roll, name, cls, m1, m2, m3);
            students[i].calculatePerformance();
        }

        System.out.println("\n--- Student Reports ---");
        for (Result r : students) {
            r.displayDetails();
        }

        System.out.println("Total Result objects created: " + Result.getTotalResults());
        sc.close();
    }
}
