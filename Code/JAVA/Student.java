public class Student {
    static final int TOTAL_STUDENTS = 100;
    static Student[] student = new Student[TOTAL_STUDENTS]; 
    static int numStudents = 0;

    String name;
    int rollNum;
    int marks;

    Student(String name, int rollNum, int marks){
        this.name = name;
        this.rollNum = rollNum;
        this.marks = marks;
    }

    Student(String name){
        this.name = name;
    }

    Student(String name, int rollNum){
        this.name = name;
        this.rollNum = rollNum;
    }

    static double calculateAvgMarks(){
        int totalMarks = 0;
        for(int i = 0; i < numStudents; i++){
            totalMarks += student[i].marks;
        }
        double avg = totalMarks / numStudents;
        return avg;
    }

    public static void main(String[] args){
        student[numStudents++] = new Student("Studen1", 1, 390);
        student[numStudents++] = new Student("Studen2", 2);
        student[numStudents++] = new Student("Studen3");

        System.out.println("\n---- List of students ----");
        for (int i = 0; i < numStudents; i++) {
            System.out.printf("\nRoll no: %d. Name: %s Marks: %d\n", student[i].rollNum, student[i].name, student[i].marks);
        }
        calculateAvgMarks();
    }
}
