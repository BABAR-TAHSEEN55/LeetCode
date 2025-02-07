////class Box{
////  double length;
////  double width ;
////  double heigth;
////  Box(double  l , double w , double h){
////    length = l;
////    width = w;
////    heigth = h;
////  }
////  double Volume(){
////    return length*width*heigth;
////  }
////}
////class BoxWeight extends Box{
////  double weight;
////  BoxWeight(double l , double w , double h , double m ){
//// super(l,w,h);
//// weight = m;
////  }
////  double Volume (){
////    return length *width * heigth *weight;
////  }
////}
////public class Main{
////  public static void name() {
////     Box b = new Box(2,3,4);
////     System.out.println(b.Volume());
////  }
////{
//
////}
////
//
//abstract Animal {
//  public void MakeSound();
//  public void Sleep(){
//    System.out.println("Sleeping .....");
//  }
//}
//class Cat extends Animal{
//  public void MakeSound(){
//    System.out.println("Meow Meow  !");
//  }
//}
//class Dog extends Animal{
//  public void MakeSound(){
//    System.out.println("Meow Meow  !");
//  }
//}
//public class Main{
//  public static void main(String args[]){
//    Animal dog = new Dog();
//    Animal Cat= new Cat();
//    dog.Sleep();
//    dog.MakeSound();
//    cat.Sleep();
//    cat.MakeSound();
//  }
//}
//
class MyThread extends Thread{
  String ThreadName;
  MyThread(String ThreadName){
    this.ThreadName = ThreadName;
  }
  public void run(){

for(int i  = 0;i<5;i++){
  System.out.println("Thread is Runnnng : " + i );
}
try {
  Thread.Sleep(500);
} catch (InterruptedException e) {
System.out.println("InterruptedException");
}
  }
}

