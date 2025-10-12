import java.util.Scanner;

public class StringBufferExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        StringBuffer sb = new StringBuffer(input);

        System.out.println("\n--- StringBuffer Manipulations ---");

        // 1. append()
        sb.append(" Java");
        System.out.println("1. After append(): " + sb);

        // 2. insert()
        sb.insert(0, "Hello ");
        System.out.println("2. After insert(): " + sb);

        // 3. replace()
        sb.replace(6, 11, "World");
        System.out.println("3. After replace(): " + sb);

        // 4. delete()
        sb.delete(6, 11);
        System.out.println("4. After delete(): " + sb);

        // 5. reverse()
        sb.reverse();
        System.out.println("5. After reverse(): " + sb);
        sb.reverse(); // restore to original for next ops

        // 6. capacity()
        System.out.println("6. Capacity: " + sb.capacity());

        // 7. length()
        System.out.println("7. Length: " + sb.length());

        // 8. charAt()
        System.out.println("8. Character at index 2: " + sb.charAt(2));

        // 9. setCharAt()
        sb.setCharAt(2, 'X');
        System.out.println("9. After setCharAt(): " + sb);

        // 10. ensureCapacity()
        sb.ensureCapacity(100);
        System.out.println("10. After ensureCapacity(100): Capacity = " + sb.capacity());

        sc.close();
    }
}
