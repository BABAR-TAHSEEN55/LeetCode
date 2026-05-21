
class Student {
    String name;
     int rollNumber;

    //Parameterized Constructor
    //this current context 
    // constructor
    Student(String name, int rollNumber) {
        this.nme = name;
        this.r = rollNumber;
    }
    StudentEnter(){
        System.out.println("I am here");
    }


    void displayDetails() {
        System.out.println("Student Name: " + this.name);
        System.out.println("Roll Number : " + this.rollNumber);
    }
}

public class Set1A_ClassObjectDemo {
    public static void main(String[] args) {
        Student firstStudent = new Student("AYaan",23);
        Student secondStudent = new Student();

        firstStudent.displayDetails();
        System.out.println();
        secondStudent.displayDetails();
    }
}
