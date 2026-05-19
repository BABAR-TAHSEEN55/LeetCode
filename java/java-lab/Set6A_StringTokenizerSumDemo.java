import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Set6A_StringTokenizerSumDemo {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter integers in one line:");
        String line = reader.readLine();
        StringTokenizer tokenizer = new StringTokenizer(line);

        int sum = 0;
        System.out.println("Integers are:");
        while (tokenizer.hasMoreTokens()) {
            int number = Integer.parseInt(tokenizer.nextToken());
            System.out.println(number);
            sum += number;
        }

        System.out.println("Sum of integers: " + sum);
    }
}
