import java.io.File;
import java.util.Scanner;

public class Set7A_FileInfoDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the file name or path: ");
        String fileName = scanner.nextLine();
        File file = new File(fileName);

        System.out.println("File exists   : " + file.exists());
        System.out.println("Readable      : " + file.canRead());
        System.out.println("Writable      : " + file.canWrite());

        if (file.exists()) {
            System.out.println("File type     : " + (file.isDirectory() ? "Directory" : "Regular File"));
            System.out.println("Length bytes  : " + file.length());
        } else {
            System.out.println("File type     : Not available");
            System.out.println("Length bytes  : Not available");
        }
    }
}
