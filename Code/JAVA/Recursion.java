public class Recursion {
    static int sumOfDigits(int n){
        if(n == 0){
            return 0;
        }
        return (n%10) + sumOfDigits(n / 10);
    }

    static int factorial(int n){
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    static int power(int x, int n){
        if (n == 0) return 1;
        return x * power(x, n-1);
    }
    public static void main(String[] args) {
        int num = 5;
        System.out.println("Input: "+num);
        System.out.println("Ouput: "+factorial(num));
    }
}
