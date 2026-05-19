class Student {
    private final String name;
    private final int rollNumber;

    Student(String name, int rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
    }

    void displayDetails() {
        System.out.println("Student Name: " + name);
        System.out.println("Roll Number : " + rollNumber);
    }
}

public class Set1A_ClassObjectDemo {
    public static void main(String[] args) {
        Student firstStudent = new Student("Ayaan", 101);
        Student secondStudent = new Student("Sara", 102);

        firstStudent.displayDetails();
        System.out.println();
        secondStudent.displayDetails();
    }
}
