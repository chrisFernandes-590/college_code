import java.util.*;



public class GroupAnagram {

    static boolean isAnagram(String s1, String s2){
        if(s1.length() != s1.length())return false;
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        return new String(c1).equals(new String(c2));
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of 3-letter words: ");
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<String> words = new ArrayList<>();
        System.out.println("Enter the words:");
        for (int i = 0; i < n; i++) {
            String word = sc.nextLine().toLowerCase();
            if (word.length() == 3)
                words.add(word);
            else
                System.out.println("Only 3-letter words are allowed!");
        }

        ArrayList<ArrayList<String>> result = new ArrayList<>();

        for(String word : words){
            boolean added = false;
            for (ArrayList<String> group : result) {
                if(isAnagram(group.get(0), word)){
                    group.add(word);
                    added = true;
                    break;
                }   
            }
            if (!added) {
                ArrayList<String> newGroup = new ArrayList<>();
                newGroup.add(word);
                result.add(newGroup);
            }
        }

        System.out.println("Output: " + result);
        sc.close();
    }
}
