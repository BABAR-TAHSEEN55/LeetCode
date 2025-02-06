//class MyThread extends Thread{
//  public void run(){
//    try {
//    System.out.println(Thread.currentThread().getName()+"is Running ");
//    Thread.sleep(3000);
//    System.out.println(Thread.currentThread().getName()+"Finished Running");
//    } catch (InterruptedException e) {
//System.out.println(Thread.currentThread().getName()+"Was interrupted");
//    }
//  }
//}
//public class main{
//  public static void main(String args[]){
//
//
//MyThread t1 = new MyThread();
//MyThread t2 = new MyThread();
//System.out.println("Starting Threads....");
//t1.start();
//t2.start();
//
//System.out.println("Are Threads Alive ? "+ t1.isAlive());
//System.out.println("Are Threads Alive ? "+ t2.isAlive());
//
//try{
//  t1.join();
//  t2.join();
//
//}catch(InterruptedException e){
//  System.out.println("Thread Interruupted while Joining");
//}
//System.out.println("Are threads  alive after joining ? "+t1.isAlive());
//System.out.println("Are threads  alive after joining ? "+t2.isAlive());
//}
//}
//class MyThread implements Runnable{
//  public void run(){
//    System.out.println("Thread is running .. ");
//  }
//}
//class Main{
//   public static void main(String[] args) {
//   MyThread Runnable = new MyThread(); 
//   Thread t1 = new Thread(Runnable);
//   t1.start();
//  }
//}
//
class Main {
  public static void main(String args[]){
try {
  
  int result = 10/0;
  String str = null;
  str.length();
} catch (ArithmeticException e) {
  //TODO: handle exception
  System.out.println("Arithmentic Excerptio Caught");
}catch(NullPointerException e){

  System.out.println("Null Excerptio Caught");
}catch(Exception e ){

  System.out.println(" Excerptio Caught");
}
}
  }

