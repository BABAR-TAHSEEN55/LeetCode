////class Car {
////  String Model ;
////  int year ;
////Car(String Model , int year ){
////  this.Model = Model;
////  this.year = year ;
////}
////public void Display(){
////
////
////  System.out.println("Cars Model : " + this.Model);
////  System.out.println("Cars year : " + this.year);
////  ]
////}
////public class Main{
////  public static void main(String args[]){
////    Car c1 = new Car("BMw",1990);
////    c1.Display();
////  }
////} //Dynamic Dispatch
//class A {
//  void CallMe(){
//    System.out.println("Inside A ");
//  }
//}
//class B extends A{
//  void callMe(){
//    System.out.println("Inside B");
//  }
//}
//class C extends A{
//  void callMe(){
//    System.out.println("Inside x");
//  }
//}
//public class Main{
//  public static void main(String args[]){
//    A a = new A();
//    B b = new B();
//    C c = new C();
//    a.callMe();//TODO : Make sure all the Methods are having Correct name
//    b.callMe();
//    c.callMe();
//  }
//}
//class SBI {
//  int RateOfInterest(){
//    return 8;
//  }
//}
//class ICICI extends SBI{
//  int RateOfInterest(){
//    return 9;
//  }
//}
//class Axis extends SBI{
//  int RateOfInterest(){
//    return 10;
//  }
//}
//class Main{
//  public static void main(String args[]){
//    SBI sb = new SBI();
//    ICICI ic = new ICICI();
//    Axis ax = new Axis();
//    System.out.println("SBI : " + sb.RateOfInterest());
//    System.out.println("ICICI : " + ic.RateOfInterest());
//    System.out.println("Axis : " + ax.RateOfInterest());
//  }
//}
//// Constructor Overloading
//class Car{
//  String model;
//  int year ;
//  Car(){
//    model  = "BMW";
//    year  = 1992;
//  }
//  Car(String model  ){
//  this.model = model;
//    year  = 1992;
//  }
//
//  Car(String model , int year ){
//     this.model=model;
//     this.year=year;
//  }
//public void Display(){
//  System.out.println("Cars : mode : " + model);
//  System.out.println("Cars : mode : " + year);
//}
//}
//public class Main{
//    public static void main(String args[]){
//
//
//  Car c = new Car();
//  Car c1 = new Car("Porsche");
//  Car c2 = new Car("Hyndai",2992);
//  c.Display();
//  c1.Display();
//  c2.Display();
//}
//}
//
//
//Interface 
interface Drawable{
 void Draw();
}
class Rectangle implements Drawable{
 public void Draw(){
    System.out.println("Drawing Rectangle");
  }
}
class Triangle implements Drawable{
  public void Draw(){
    System.out.println("Drawing Triangle");
  }
}
public class Main{
  public static void main(String args[]){
    Rectangle r = new Rectangle();
    r.Draw();
    Triangle tr = new Triangle();
    tr.Draw();
  }
}
// Method Overloading
class Addtion{
  int sum(int a , int b){
    return a + b;
  }
  int sum(int a , int b , int c){
    return a + b+ c;
  }
  int sum(int a , int b , int c , int d){
    return a + b+ c + d;
  }
}
public class Main{
  public static void main(String args[]){
    Addtion ad = new Addtion();
    System.out.println(ad.sum(2,4));
    System.out.println(ad.sum(2,45,5));
  }
}
class Car {
  public Car(){
    System.out.println("Details are Listed Below : ");
  }
  void VehicleType(){
    System.out.println("VehicleType : Car");
  }
  void Brand(){
    System.out.println("Brand : car");
  }
}
class Maruti extends Car{
  Maruti(){
    System.out.println("CarType : Maruti");
  }
  void Speed(){
    System.out.println("Speed : 20kmph");
  }
  void Brand(){
    System.out.println("Brand : BMW");
  }
}
class Main{
  public static void main(String args[]){
Car cr = new Car();
cr.VehicleType();
Maruti mr = new Maruti();
mr.Brand();
mr.Speed();
  }
}
