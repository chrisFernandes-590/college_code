import java.util.Scanner;

public class StringCompression {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        String compressed = compressString(input);
        System.out.println("Output: " + compressed);

        sc.close();
    }

    public static String compressString(String str) {
        StringBuffer sb = new StringBuffer();
        int count = 1;

        for (int i = 0; i < str.length() - 1; i++) {
            if (str.charAt(i) == str.charAt(i + 1)) {
                count++;
            } else {
                sb.append(str.charAt(i));
                sb.append(count);
                count = 1;
            }
        }

        sb.append(str.charAt(str.length() - 1));
        sb.append(count);

        if (sb.length() >= str.length()) {
            return str;
        } else {
            return sb.toString();
        }
    }
}
