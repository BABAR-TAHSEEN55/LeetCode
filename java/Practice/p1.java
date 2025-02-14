import java.util.Scanner;
private class Employee{
  private String name;
  private int age;
  private double Salary;
  private int ID;
  public void AcceptDetails(){
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter Name : ");
    name = scanner.nextLine();
    System.out.println("Enter age : ");
    age = scanner.nextInt();
    System.out.println("Enter Salary : ");
    Salary = scanner.nextDouble();
    System.out.println("Enter ID : ");
    ID = scanner.nextInt();
  }
  public void DisplayDetails(){
    System.out.println("Name : " + name);
    System.out.println("Age : " + age);
    System.out.println("Salary : " + Salary);
    System.out.println("ID : " + ID);
  }
}
public class Main{
  public static void main(String args[]){
    Employee e1 = new Employee();
    e1.AcceptDetails();
    e1.DisplayDetails();
  }
}

