//class MyThread extends Thread{
//  try {
//    System.out.println(Thread.currentThread().getName()+"Is Running");
//    Thread.sleep(3000);
//    System.out.println(Thread.currentThread().getName()+"has finished Executing");
//  } catch (InterruptedException e) {
//System.out.println(Thread.currentThread().getName()+"Has been Interrupted");
//  }
//}
//public class Main(){
//  public static void main(String args[]){
//    MyThread t1  = new MyThread();
//    MyThread t2  = new MyThread();
//    System.out.println("Starting Threads ...");
//    t1.start();
//    t2.start();
//    System.out.println("Is t1 thread alive :" + t1.isAlive());
//    System.out.println("Is t1 thread alive :" + t2.isAlive());
//    try{
//      t1.join();
//      t2.join();
//    }catch(InterruptedException e){
//      System.out.println("Interrrupted");
//    }
//    System.out.println("is aliv e: l" + t1.isAlive());
//  }
//}
//TODO : DONT FORGET RUN METHOD
//class MyThread extends Thread {
//  String ThreadName;
//  public MyThread(String name){
//    this.ThreadName = name;//TODO :Be Alert at this Point
//  }
//  public void run(){
//    for(int i = 0;i<=5;i++){
//      System.out.println(ThreadName + "Is running " + "count : "+i);
//      try{
//      Thread.sleep(3000);
//      }catch(InterruptedException e){
//        System.out.println("InterruptedException");
//      }
//    }
//  }
//}
//public class Main{
//  public static void main(String args[]){
//    MyThread t1 = new MyThread()
//    MyThread t2 = new MyThread()
//    t1.start();
//    t2.start();
//System.out.println("finished");
//  }
//}
//Thread(Runnable r)
class MyThread implements Runnable{
  public void run (){
    System.out.println("Thread is running ...");
  }
}
public class Main{
  public static void main(String args[]){
    MyThread t1 = new MyThread();
    Thread t = new Thread(MyThread)
    t1.start();
  }
}
class DemoThis{
  String Model;
  int year ;
  DemoThis(String Model , int year ){
    this.Model= Model;
    this.year = year;
  }
  public void Display(){
    System.out.println("Car's Model : " + this.Model);
    System.out.println("Car's year : " + this.year);
  }
}
class Main{
  public static void main(String args []){
    DemoThis c = new DemoThis("BMW ", 1009);
    c.Display();
  }
}

