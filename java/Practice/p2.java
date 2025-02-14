import java.io.*;
public class Largest{
public static void main(String args[]) throws IOException{
BufferedReader reader = new BufferedReader(new InputStreamReader(System.in) );
int a = Integer.parseInt(reader.readLine());
int b = Integer.parseInt(reader.readLine());
int c = Integer.parseInt(reader.readLine());
if(a>b && a > c){
  System.out.println("A is Greatest");
}else if(b>a && b>c){

  System.out.println("B is Greatest");
}else{
  System.out.println("C is Greastest");
}
}
}
