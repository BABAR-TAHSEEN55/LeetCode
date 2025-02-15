import java.io.*;
import java.util.StringTokenizer;
class DemoToken{
  public static void main(String args[]) throws IOException{
    BufferedReader reader= new BufferedReader(new InputStreamReader(System.in));
    String line = reader.readLine();
    StringTokenizer  token = new StringTokenizer(line);
    int sum = 0;
    while (token.hasMoreTokens()) {
      int n  =  Integer.parseInt(token.nextToken());
      sum +=n;
      
    }
    System.out.println("Sum : "+ sum);
  }
}

class Car {
  Car(){
    System.out.println("Class : Car");
  }
  public void VehicleType(){
    System.out.println("Car : Type");
  }
  public void Brand(){
    System.out.println("Car : Brand");
  }
}
class Maruti extends Car{
  Maruti(){
    System.out.println("Class : Maruti");
  }
  public void Speed(){
    System.out.println("89 kmph");
  }
  public void Brand(){
    System.out.println("BRAND : Maruti");
  }
}
class Suzuki extends Maruti{
  Suzuki(){
    System.out.println("Class : Suzuki");
  }
  public void Brand(){
    System.out.println("Brand : Suzuki");
  }
  public void Speed(){
    System.out.println("100kmph");
  }
}
public class Main{
  public static void main(String args[]){
    Maruti M = new Maruti();
    Suzuki S = new Suzuki();
    M.Brand();
    M.Speed();

    S.Brand();
    S.Speed();
  }
}


interface Drawalbe{
  void Draw();
}
class Rectangle implements Drawalbe{
  public void Draw(){
    System.out.println("Drawing Rectangle");
  }
}
class Circle implements Drawalbe{
  public void Draw(){
    System.out.println("Drawing Circle");
  }
}

class Main{
  public static void main(String args[]){
    Rectangle r = new Rectangle();
    r.Draw();
    Circle c = new Circle();
    c.Draw();
  }
}

//Abstract
class Animal{
  public abstract void MakeSound();
  public void Sleep(){
    System.out.println("SLeeping .........");
  }
}
class Dog extends Animal{
  public void MakeSound(){
    System.out.println("Woof Woof");
  }
}
class Cat extends Animal{
  public void MakeSound(){
    System.out.println("Meow Meo");
  }
}
class Main{
  public static void main(String args[]){
    Dog dog = new Dog();
    dog.MakeSound();
    dog.Sleep();
    Cat cat = new Cat();
    cat.MakeSound();
    cat.Sleep();
  }
}


class Car{
  String model;
  int year;
  Car(){
model = "BMW";
year = 1999;
  }
  Car(String model){
    this.model = model;
    year = "1800";
  }
  Car(String model , int year){
    this.model = model;
    this.year = year;
  }
  public void Display(){
    System.out.println("Car Model : " + model);
    System.out.println("Car Year : " + year);
  }
}
public class Main{
  public static void main(String args[]){
    Car c1 = new Car();
    Car c2 = new Car("Porsche");
    Car c3 = new Car("Suzuki",1888);
    c1.Display();
    c2.Display();
    c3.Display();
  }
}
//Method Overrding
class SBI {
  public  void Rate(){
    return 9;
  }
}
class AXIS extends SBI{

  public  void Rate(){
    return 90;
  }
}
class ICICI extends SBI{

  public  void Rate(){
    return 89;
  }
}
class Main{
  public static void main(String args[]){
    SBI s = new SBI();
  System.out.println("Rate of Interst of SBI : " + s.Rate);
  }
}

class A{
void CallMe(){
  System.out.println("Inside A");
}
}
class B extends A{

void CallMe(){
  System.out.println("Inside B");
}
}
class C extends A {
  
void CallMe(){
  System.out.println("Inside C");
}
}
public class Main{
  public static void main(Strings args[]){
    A a = new A();
    B b = new B();
    C c = new C();
    A r;
    r = a;
    r.CallMe();
  r=b;
    r.CallMe();
    r =c;
    
    r.CallMe();
  }
}


class ExcpetionHandling{
   public static void main(String[] args) {
     try {
       
   int a = 10;
   String str = null;
   str.length();
   int sum ;
   sum = a/0;
     } catch (ArithmeticException e) {
System.out.println("Caught ArithmeticException");
     }catch(NullPointerException e){
       System.out.println("Null Pointer Exceptio Caught");
     }catch(Exception e ){
       System.out.println("Exception caught");
     }
  }
}//Do try Different Blocks


import java.util.*;
impott java.io.*;
class Fibonacci{
  public static void main(String args[]){
    BufferedReader reader = new BufferedReader(newe InputStreamReader(System.in));
    System.out.println("Enter Value of N : ");
    int n = Integer.parseInt(reader.readLine());
for(int i = 0;i<n;i++){
System.out.println(fibonacci(i) );
}
System.out.println(" ");

  }
static int fibonacci(int n ){
  if(n ==0) return 0;
  if(n==1) return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}
}

import java.util.*;
import java.io.*;
public class Main{
   public static void main(String[] args) {
   BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
   int n = Integer.parseInt(reader.readLine());
   int factorial  =1;
   for(int i = 1;i<=n;i++){
     factorial*=i;
   }
   System.out.println("Factorial of the " + n +" : " + factorial);
  }
}
import java.uitl.*;
import java.io.*;
class Employee{
  private String name;
  private int age;
  private int ID;
  private double Salary;
  public void AcceptDetails(){

  Scanner scanner = new Scanner(System.in);
System.out.println("Enter Employee Name : ");
name = scanner.nextLine();

System.out.println("Enter Employee Age : ");
age = scanner.nextInt();
  
System.out.println("Enter Employee ID : ");
ID = scanner.nextInt();
System.out.println("Enter Employee Double : ");
Salary = scanner.nextDouble();
  }
public void DisplayDetails(){
  System.out.println("Employee's name : " + name);
  System.out.println("Employee's Age : " + age);
  System.out.println("Employee's ID : " + ID);
  System.out.println("Employee's Salary : " + Salary);
}
}
public class Main{
   public static void main(String[] args) {
   Employee e1 = new Employee() ;
   e1.AcceptDetails();
   e1.DisplayDetails();
  }
}

class DemoThrowAndThrows{
  static void CheckNumber(int n) throws ArithmeticException{
    if(n<0){
      throw new ArithmeticException("Number is Negative");
    }else{
      System.out.println("Value of Number : " + n);
    }
  }

  public static void main(String args[]){
    try{
      CheckNumber(-1);
    }catch(ArithmeticException e){
      System.out.println("ArithmeticException Caught");
    }
    CheckNumber(340);
  }
  }
}//Extra Brace error but not Extra Brace would be Int void Problem

class Car{
  String model;
  int year;
  Car(Stirng model, int year){
    this.model = model;
    this.year = year;
  }
  public void Display(){
    System.out.println("Car Model :" + this.model);
    System.out.println("Car year :" + this.year);
  }
}
public class Main{
  public static void main(String args[]){
    Car c1 = new Car("BMWQ", 1999);
    c1.Display();
  }
}

class MyThread implements Runnable{
public void run(){
  System.out.println("Thread is Running ........");
}
}
class Main{
  public static void main(String args[]){
    MyThread runnable = new MyThread();
    Thread t1 = new Thread(runnable);
    t1.start();
  }
}


class MyThread extends Thread{
public void run(){
  System.out.println(Thread.currentThread().getName() + "is running...");
  try{
    Thread.sleep(3000);
  }catch(InterruptedException e){
    System.out.println("InterruptedException");
  }
  System.out.println(Thread.currentThread().getName()+"Is stopped ...");
}
}
public class Main{
  public static void main(String args[]){
    MyThread t1 = new MyThread();
    MyThread  t2 = new MyThread();
    System.out.println("Starting Threads ....");
    t1.start();
    t2.start();
    System.out.println("Are threads Alive ?" + t1.isAlive());
    System.out.println("Are threads Alive ?" + t2.isAlive());
    try {
      t1.join();
      t2.join();
    } catch (InterruptedException e) {
      System.out.println("InterruptedException");
    }

    System.out.println("Are threads Alive ?" + t1.isAlive());
    System.out.println("Are threads Alive ?" + t2.isAlive());

  }
}

import java.util.*;
interface SharedConstants{
  int NO = 0;
  int YES= 1;
  int MAYBE = 2;
  int LATER= 3;
int SOON =4;
int NEVER = 5;
}
class Question implements SharedConstants{
  Random rand = new Random();
  public int Ask(){
    int prob = (int)(100*rand.nextDouble());
    if(prob<30){
      return NO;
    }else if(prob <60){
      return YES;
    }else{
      return -1;
    }
  }
}
class Answers implements SharedConstants{
  static void answer(int Result){
    switch (Result) {
      case NO:
        System.out.println("NO");
        break;
      default:
        break;
    }
  }
}
class Main{
  public static void main(String args[]){
    Question Q = new Question();
    Answers a = new Answers();
int result = Q.Ask();
Answers.Answers(result);
  }
}
class StackDemo{
  static void ShowPush(Stack<Integer>st , int a){
    st.push(a);
    System.out.println("Pushed Element : " + a);
    System.out.println("Stack : ") + st;
  }

  static void ShowPop(Stack<Integer>st ){
    int integer = st.pop();
    System.out.println("Popped  Element : " + integer);
    System.out.println("Stack : ") + st;
  }
  public static void main(String args[]) {
    
Stack<Integer> st = new Stack<Integer>();
ShowPush(st,40);

ShowPush(st,43);
ShowPush(st,99);
ShowPush(st,87);
ShowPush(st,22);
ShowPop(st);
}
}

import java.util.*;

class Main {
  public static void main(String args[]) {
    ArrayList<String> al = new ArrayList<String>();
    al.add("D");
    al.add("A");
    al.add("B");
    al.add("C");

    // Using Iterator
    Iterator<String> itr = al.iterator();
    while (itr.hasNext()) {
      String element = itr.next();
      System.out.println("Element: " + element);
    }

    System.out.println();

    // Using ListIterator for modification
    ListIterator<String> ltr = al.listIterator();
    while (ltr.hasNext()) {
      String element = ltr.next();
      ltr.set(element + "-");  // Modify the element
      System.out.println("Modified Element: " + (element + "+"));
    }

    System.out.println("\nFinal ArrayList: " + al);
  }
}
import java.io.*;
class Main{
  public static void main(String args[])throws IOException{
    if(args.length<2){
      System.out.println("Please Provide a Valid File");
      return;
    }
      String InputFile = args[0];
      String OutputFile = args[1];
    FileInputSteam InputReader = new FileInputSteam (InputFile);
    FileOutputSteam OutputReader = new FileOutputSteam(OutputFile);
    int FileSize = new File(InputFile).length();
    byte[] allbytes = new byte(FileSize);
    InputReader.read(allbytes);
    OutputReader.write(allbytes)
