// I am Lazy to write in my NoteBook hehe

public class Conversion{
  public static void main(String args[]){
    int i =200;
    long l=i;
    System.out.println("Inti : "+ i);
    System.out.println("long : "+ l);
    double d = 22.1;
    long ll = (long)d;
    System.out.println("Converted : "+ ll);
  }
}
// This Keyword

public class ThisDemo{
  public static void main(String args[]){
//Box(double height , double length , double width){
//  this.height = height;
//  this.length = length;
//  this.widht = width;
//}
int a = 10;
int b=  20;
contructorDemo(){
  this(a,b);
  System.out.println("Inside Demo");
}
contructorDemo(int a , int b){
  this.a = a ;
  this.b = b;
}
contructorDemo cd = new contructorDemo();
  }
}
//Finalize Method 
public class TestGarbage {
  public void finalize(){
    System.out.println("Object is Garbage colleceted");
  }
  public static void main(String args[]){
    TestGarbage t1 = new TestGarbage();
    t1=t2;
    TestGarbage t2 = new TestGarbage();
    System.gc();

  }
}
// Inheritance
public class Box {
  double width , height , lenght;
  Box(double w , double h , double l){
    width= w;
    height=h;
    lenght = l;
  }
  public double Volume(){
    return  width * lenght * height;
  }
}
class BoxWeight extends Box{
  double weight;
  BoxWeight(double w , double l , double h , double m){
    super(l,w,h);
    weight=m;
  }
}
class Calculate {
  public stativ void main(String args[]){
    BoxWeight b1 = new BoxWeight(2,4,5,6);
    b1.Volume();
    Box b2 = new Box(2,4,5);
  }
}
// Mutlilevel Inheritance
public class Car{
  public void Car{
    System.out.println("Car Type");
  }

  public void Brand{
    System.out.println("Car Brand");
  }
}
public class Maruti extends Car{
  public void Maurti{
    System.out.println("Class Maruti");
  }

  public void Brand{
    System.out.println("Car Maruti");
  }

  public void Speed{
    System.out.println("80kmpph");
  }

public class Cheverlot extends Maruti{
  public void Cheverlot{
    System.out.println("Class Cheverlot");
  }

  public void Brand{
    System.out.println("Car Chenrelot");
  }

  public void Speed{
    System.out.println("80kmpph");
  }
}
class Cease {
  public static void main(String args[]){
    Cheverlot c = new Chenrelot();
    c.Brand();
    c.Speed();
  }
}
// Method Overloading
//Make Sure you are Printing values
public class DemoOverloading{
  public void Square(){
    System.out.println("Empty Method");
  }
  public int Square(int lenght , int width){
    return lenght * width;
  }

  public double Square(double lenght , double width ){
    return lenght * width;
  }
  public static void main(String args[]){
    DemoOverloading dm = new DemoOverloading();
    dm.Square();
System.out.println(dm.Square(2,4););    
System.out.println(dm.Square(2.2,4.3););    

  }
}
// Method Overrrding
//
public class Bank{
  public void ROI{
    return 0;
  }
}
public class SBI extends Bank{
  public void ROI{
    return 9;
  }
}
public class ICICI extends Bank{
  public void ROI{
    return 99;
  }
}
public class AXISX extends Bank{
  public void ROI{
    return 299;
  }
}


public Test {
  public static void main(String args[]){
    SBI s = new SBI();
    ICICI ic = new ICICI();
    AXISX ax = new AXISX();
    System.out.println(s.ROI());
    System.out.println(ic.ROI());
    System.out.println(ax.ROI());
)
  }
}
// Interfaces 
interface Drawable {
  void Draw();
}
class Rectangle implements Drawable{
  public void Draw(){
    System.out.println("Rectange is being Drwan");
  }
}

class Circle implements Drawable{
  public void Draw(){
    System.out.println("Circle is being Drwan");
  }
  public class test{
    public static void main(String args[]){
      Rectange r = new Rectangle();
      r.Draw();
    }
  }
  //Mutilple Inheritance

interface Drawable {
  void Draw();
}

interface Erase {
  void erase();
}
class Rectangle implements Drawable,Erase{
  public void Draw(){
    System.out.println("Rectange is being Drwan");
  }

  public void erase(){
    System.out.println("Rectange i being Erased");
  }
}

class Circle implements Drawable{
  public void Draw(){
    System.out.println("Circle is being Drwan");
  }
  public class test{
    public static void main(String args[]){
      Rectange r = new Rectangle();
      r.Draw();
    }
  }

// Package 
package MyPack;
class Balance {
  double balance;
  String Name;
Balance(Stirng n , double b){
  Name = n;
  balance=b;
}
void Show(){
  if(bal<0){
    System.out.println("Brookie! LOL");
  }else{

  System.out.println("Balance in the Account : " + balance);
  }
}
}
class BankAccount {
  public static void main(String args[]){
Balance bb = new Balance[3];
bb[0] = new Balance[1234.22,"HOla"];
bb[1] = new Balance[2343.2,"SUpe"]
bb[2] = new Balance[1.2,"Batman"]
bb[3] = new Balance[122.2,"WonderMAn"]
for(int i = 0;i<3;i++){
  bb[i].show();
}
  }
}
//Throw and Throws 
public class DemoThrow{
  static void Check(int age) throws ArithmeticException{
    if(age < 0){
      throw new ArithmeticException("Number is Negative");
    }else{
      System.out.println("Value of Age : " + age);
    }

  }
}
public class TestDemo{
  public static void main(String args[]){
    try{
      DemoThrow.Check(-1);
      DemoThrow.Check(234);
    }catch(ArithmeticException e){
System.out.println("Exception Caught Alert@!!");
    }
  }
}
// Cpy One File to Another
import java.io.*;
public class Main{
public static void main(Strings args[]){
  if(args.lenght<2){
    System.out.println("Please Provide a valid File");
    return;
  }
  String InputFile = args[0];
  String OutputFile = args[1];
  try{
    FileInputStream InputReader = new FileInputStream(InputFile);
    FileOutputStream OutputReader = new FileOutputStream(OutputFile);
    long FileSize =  new File(InputFile).length();
    byte[] allBytes = new byte[(int)FileSize];
    InputReader.read(allBytes);
    OutputReader.write(allBytes);
InputReader.close();
OutputReader.close;
  }catch(Exception e){
    System.out.println("Exception caught");
  }
}
}
// Program to Demonstrate File Mehtods
import java.io.File;
import java.io.*;
public class Main{
  public static void main(Strings args[]){
    try{

    File myFile = new File("Example.txt");
    if(myFile.createNewFile){
System.out.println("New File Created " + myFile.getName());
    }else{

System.out.println("File already Exists");
    System.out.println("File Absolute Path" + myFile.getAbsolutePath());
    System.out.println("File  Name" + myFile.geName());
    System.out.println("File Absolute Path" + myFile.length());
    System.out.println("File Absolute Path" + myFile.canRead());
    System.out.println("File Absolute Path" + myFile.canWrite());
    if(myFile.delete()){

    System.out.println("File Deleted  " );
    }else{
      System.out.println("File Didn't Exits");
    }
    }
    }catch(IOException e){
      System.out.println("IOException caught");
    }
  }
}
// String Tokenizer
import java.io.*;
import java.util.StringTokenizer;
public class DemoToken{
  public staic void main(String args[]){
    try{
    BufferedReader  reader = new BufferedReader(new InputStreamReader(System.in));
    String line = reader.readLine(); 
    StringTokenizer Token = new StringTokenizer(line);
    int sum = 0;
    while (Token.hasMoreTokens()) {
int n = Integer.parseInt(Token.nextToken());
sum +=n;
    }
System.out.println("Sum of Integers : " + sum);
    }catch(IOException e){
      System.out.println(e.getMessage());
    }
  }
}
// Factorial Using Buffered reader
import java.io.*;
public class Fibonnaci{
  public static void main(String args[]){
    BufferedReader reader= new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Enter the number of Terms :");
    int  n = Integer.pareseInt(reader.readLine);

    System.out.println("Fibonacci Series : ");
    for(int i = 0;i<n;i++){
      System.out.println(Fibonacci(i));
    }
    System.out.println(" ");
  }
}
static int Fibonacci(int n){
  if(n==0) return 0;
  if(n==1) return 1;
  return Fibonnaci(n-1) + Finalize(n-2);
}
// In Stacks , Remember they are Abstract Classes
// Stack Demo
public class StackDemo{
static void ShowPush(Stack<Intger> st , int n){
st.push(n);
System.out.println("Pushed Element : " + n);
System.out.println("Stack : " + st);
}
static void ShowPop(Stack<Integer>st){
  int popped = st.pop();
  System.out.println("Popped Element : " + popped);
  System.out.println("Stack : " + st );
}
  public static void main(String args[]){
Stack<Integer> st = new Stack<Integer>;
st.ShowPush(st,2);
st.ShowPush(st,3);
st.ShowPush(st,4);
st.ShowPush(st,5);
st.ShowPop();
  }
}
// Scanner Class
import java.util.Scanner;
private class Employee{
private String name;
private int age;
private double Salary;
private int ID;
public void AcceptDetails(){
  Scanner scanner = new Scanner(System.in);
  System.out.println("Enter Employee's Name : ");
  name = scanner.nextLine();
  System.out.println("Enter Employee's AGE : ");
  age = scanner.nextInt();
  System.out.println("Enter Employee's Salary : ");
  Salary = scanner.nextDouble();
  System.out.println("Enter Employee's ID : ");
  ID = scanner.nextInt();
}
public void DisplayDetails(){
  System.out.println("Employee's Name : "+name);
  System.out.println("Employee's age : "+age);
  System.out.println("Employee's Salary : "+Salary);
  System.out.println("Employee's ID : "+ID);
}
}
public class Main{
  public static void main(String args[]){
Employee ep = new Employee();
ep.AcceptDetails();
ep.DisplayDetails();
  }
}
// Iterator

public class IteratorDemo{
public static void main(String args[]){
  ArrayList<Integer> al= new ArrayList<Integer>;

}
}

// User Defined Exceptions
class InsufficientBankBalance extends Exception{
  InsufficientBankBalance(String msg){
    super(msg);
  }
}
public class BankAccount{
  private double balance;
  BankAccount(double balance ){
    this.balance = balance;
  }
  public void Withdraw (double amount) throws InsufficientBankBalance{
    if(amount > balance){
      throw new InsufficientBankBalance("You have InsufficientBankBalance in your Bank account ! Brookie LOL")
    }else{
      balance-=amount;
      System.out.println("Transaction has been Successfull");
    }
  }
}
public class Test {
  public static void main(String args[]){
    BankAccount bb = new BankAccount(6000);
    try{

    }catch(InsufficientBankBalance e){
      System.out.println("Excetption Caught : " + e.getMessage());
    }
    bb.Withdraw(7000);
  }
}

class Queue{
  private int item;
  private boolean available = false;
  public synchronized int consume (){
    while(!available){
      try{
        wait();
      }catch(InterruptedException e){
e.printStack();
      }
    }

      available = false;
      notify();
      System.out.println("Conumed : "  + item);
      return item;
  }
  public synchronized int produce(int newItem){
    while(available){
      try{
        wait();
      }catch(InterruptedException e){
        e.printStack();
      }
    }

      this.item = newItem;
      available = true;
      notify();
      System.out.println("Produced : " + item);
  }
}
public class Producer extends Thread{
  private Queue queue;
  Producer(Queue queue){
    this.queue =queue;
  }


  public void run(){
    for(int i = 0;i<5;i++){
      try{

queue.produce[i];
Thread.sleep(500)

      }

  }catch(InterruptedException e){
    e.printStack();
  }
  }
}

public class Consumer extends Thread{
  private Queue queue;
  Consumer(Queue queue){
    this.queue = queue;
  }

  public void run(){
    try{

    for(int i = 0;i<=5;i++){
 queue.consume[i];
 Thread.sleep(500);
    }catch(InterruptedException e){
      e.printStack();
    }
    }
  }
}
public class  Main{
  public static void main(String args[]){
    Producer producer = new Producer(queue);
    Consumer consume = new Consumer(queue);
    producer.start();
    consume.start();
    try{
      producer.join();
      consume.join();
    }catch(InterruptedException e){
      e.printStack();
    }
  }
}
// Thread isJoin && IsAlive  
class MyThread extends Thread{
  try{
    System.out.println(Thread.currentThread().getName() + "Is Running ....");
    Thread.sleep(500);
    System.out.println(Thread.currentThread().getName() + "Is Running ....");
  }catch(InterruptedException e){
    System.out.println(Thread.currentThread().getName() + "Has been Interruted");
  }
}
class DemoThread{
  public static void main(String args[]){
    MyThread t1 = new MyThread();
    MyThread t2 = new MyThread();
    System.out.println("Starting Threads ... ");
    t1.start() ;
    t2.start();

      System.out.println("Is Thread t1 Allivve ? "  + t1.isAlive());
      System.out.println("Is Thread t1 Allivve ? "  + t2.isAlive());
    try{
      t1.join();
      t2.join();

    }catch(InterruptedException e){
      System.out.println("Thread has been Interrupted");
    }
System.out.println("Is Alive3 ? " + t1.isAlive());
  }
}

// Two ways of Implementing Thread : 
class MyThread implements Runnable {
public void run(){
  for(int i =0;i<=5;i++){
    System.out.println("Thread  " + i + " is Reunning ");
  }
  try{
    Threads.sleep(5000);
  }catch(InterruptedException e){
    System.out.println("Thread has been Interrupted");
  }
}
}
public class ThreadDemo{
  public static void main(String args[]){
    MyThread r2 = new MyThread();
    Thread t1 = new Thread(r2)
      t1.start();
   }
}
class MyThread extends Thread {
  public void run(){

  for(int i =0;i<=5;i++){
    System.out.println("Thread  " + i + " is Reunning ");
  }
  try{
    Thread.sleep(5000);
  }catch(InterruptedException e){
    System.out.println("Interuupted");
  }
  }
}
public class ThreadSemo{
  public static void main(String args[]){
    MyThread t1 = new Thread();
    t1.start();
  }
}

// Serialization and De-Serialization
import java.io.*;
public class Demo implements java.io.Serializable{
  public int a ;
  public String name;
  Demo(int a , String name){
    this.a = a;
    this.name= name;
  }
}
public class Test{
  public static  void main(String args[]){
    Demo dd = new Demo(14 , "CSE-A");
    try{
      String filname = "Some.txt";
      FileOutputStream file = new FileOutputStream(filename)
        ObjectOutputStream out = new ObjectOutputStream(file);
      out.writeObject(object);
      out.close();
      file.close();
      System.out.println("Object has been Serialized");
    }catch(IOException ex){
      System.out.println("IOException is caught");
    }
    Demo object1 = null;
    try{
      FileInputStream file = new FileInputStream(filename);
      ObjectInputStream  = new ObjectInputStream(file);
       object = (Demo)in.readObject();
       in.close();
       file.close();
       System.out.println("Object has been Deserialzed..");
 System.out.println("a" + object1.a);
 System.out.println("b" + object1.b);
    }catch(IOException e){
      System.out.println("Exception Caught");
    }catch(ClassNotFoundException e){
      System.out.println("ClassNotFoundException ");
    }

  }
}
// AGAIN
public class  Serialized {
  public int a ;
  public String name;
  Serialized(int a , String name){
    this.name = name;
    this.a = a;
  }
}
public class Test{
  public static void main(String args[]){
    try{
String filename ="Blaze";
FileInputStream file  = new FileInputStream(filename);
ObjectOutputStream  out = new ObjectOutputStream(file);
out.writeObject(object);
out.close();
file.close();

  }catch(IOException e){
    System.out.println("Exception Caught");
  }
  Serialized object1  = null;
  try{
FileInputStream file = new FileInputStream(filename);
ObjectInputStream in = new ObjectInputStream(file);
object1= (Serialized)in.readObject();
in.close();
file.close();
System.out.println("Object has been Deserialzed ... ");
System.out.println("a " + objec1.a);
System.out.println("B" + object1.b);
  }catch(IOException e){
System.out.println("Exception ahs been cuagh");
  }catch(ClassNotFoundException e){
    System.out.println("ClassNotFoundException has been caufdht");
  }
}
