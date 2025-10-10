import java.util.Scanner;

public class EuclideanDistance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of dimensions
        System.out.print("Enter the number of dimensions: ");
        int n = sc.nextInt();

        double[] P = new double[n];
        double[] Q = new double[n];

        // Input vector P
        System.out.println("Enter elements of vector P:");
        for (int i = 0; i < n; i++) {
            P[i] = sc.nextDouble();
        }

        // Input vector Q
        System.out.println("Enter elements of vector Q:");
        for (int i = 0; i < n; i++) {
            Q[i] = sc.nextDouble();
        }

        // Calculate Euclidean distance
        double distance = 0;
        for (int i = 0; i < n; i++) {
            distance += Math.pow(P[i] - Q[i], 2);
        }
        distance = Math.sqrt(distance);

        System.out.println("Euclidean Distance between P and Q = " + distance);

        sc.close();
    }
}
