//import java.io.*;
//public class bufferDemo{
//  public static void main(String args[]) throws IOException{
//    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//    System.out.println("Enter Integers");
//    int n = Integer.parseInt(reader.readLine());
//int factorial  = 1;
//for(int i = 1;i<=n;i++){
//  factorial*=i;
//}
//System.out.println("Factorial of the Number : " + n + "  : "  + factorial);
//  }
//}

// Fibonacci 
//import java.io.*;
//
//public class Main {
//    public static void main(String args[]) throws IOException {
//        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//        System.out.println("Enter the number of terms:");
//        int n = Integer.parseInt(reader.readLine());
//
//        System.out.println("Fibonacci Series:");
//        for (int i = 0; i < n; i++) { 
//            System.out.print(fibonacci(i) + " "); // Store and print the result
//        }
//        System.out.println();
//    }
//
//    static int fibonacci(int n) { // Function name changed to lowercase for convention
//        if (n == 0) return 0;
//        if (n == 1) return 1;
//        return fibonacci(n - 1) + fibonacci(n - 2);
//    }
//}
//
