//class Queue {
//  private int item;
//  private boolean available = false;
//
//  public synchronized int consume() throws IOException{
//    white(!available){
//      wait();
//    }
//    available = false;
//    notify();
//    System.out.println("It has been Consumed " + item);
//    return item;
//  }
//  public synchronized void produce (){
//    while(available){
//      wait();
//    }
//    available = true;
//    notify();
//    System.out.println("It has been Consumed" + item);
//  }
//}
//class Consumer extends Thread {
//  private Queue queue;
//  public Consumer( Queue queue){
//    this.queue = queue;
//  }
//  public void run () throws IOException{
//    for(int i = 0;i<=5;i++){
//      queue.produce(i);
//      Thread.sleep(500);
//    }
//  }
//}
//  class Producer extends Thread {
//    private Queue queue;
//    Producer(Queue queue ){
//      this.queue = queue;
//    }
//    public void run() throws IOException{
//      for(int i = 0;i<=5;i++){
//        queue.consume(i);
//        Thread.sleep(500);
//      }
//    }
//  }
//public class Main{
//  public static void main(String args[]){
//    Queue queue  = new Queue();
//    Consumer consume = new Consumer(queue);
//    Producer produce= new Producer(queue);
//    consume.start();
//    produce.start();
//    consume.join();
//    produce.join();
//  }
//}
import java.io.*;
import java.util.StringTokenizer;
public class DemoToken {
  public static void main(String args[]) throws IOException{
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Enter the Integers ");
    String line = reader.readLine();
    StringTokenizer Tokenizer = new StringTokenizer(line);
    int sum = 0;
    System.out.println(" Integers : " );
    while (Tokenizer.hasMoreTokens()) {
      int n = Integer.parseInt(Tokenizer.nextToken());
      System.out.println("Number : " + n);
      sum+=n;
    }

      System.out.println("SUm of INtegers : " + sum);
  }
}
