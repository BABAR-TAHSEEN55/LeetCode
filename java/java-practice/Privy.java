
class PrivateClass{

    public String name;
    private int rollNumber;

    void setRollNumber(int r){      
        rollNumber=r;
        System.out.println("ROll NUmber: " +this.rollNumber);
    }


    void displayDetails() {

        System.out.println("Student Name: " + name);
        System.out.println("Roll Number : " + rollNumber);
    }


}

public class Privy {
    public static void main(String[] args) {
        PrivateClass firstStudent = new PrivateClass();
        PrivateClass secondStudent = new PrivateClass();
        firstStudent.name = "Ayaan";
        firstStudent.rollNumber=20;
        
        firstStudent.setRollNumber(20);
        firstStudent.displayDetails();


    }
}

































void add(int a,int b){
    return a+b;
}
