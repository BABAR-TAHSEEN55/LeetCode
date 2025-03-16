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

