import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class Set7B_IOStreamsDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter source file path: ");
        String sourceFile = scanner.nextLine();
        System.out.print("Enter destination file path: ");
        String destinationFile = scanner.nextLine();

        try (FileInputStream inputStream = new FileInputStream(sourceFile);
             FileOutputStream outputStream = new FileOutputStream(destinationFile)) {

            byte[] buffer = new byte[1024];
            int bytesRead;
            int totalBytes = 0;

            while ((bytesRead = inputStream.read(buffer)) != -1) {
                outputStream.write(buffer, 0, bytesRead);
                totalBytes += bytesRead;
            }

            System.out.println("File copied successfully.");
            System.out.println("Total bytes copied: " + totalBytes);
        } catch (IOException exception) {
            System.out.println("I/O error: " + exception.getMessage());
        }
    }
}
