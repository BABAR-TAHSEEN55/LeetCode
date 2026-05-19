import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class Set11_JdbcCrudDemo {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/javalab";
    private static final String USER = "root";
    private static final String PASSWORD = "password";

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in);
             Connection connection = DriverManager.getConnection(DB_URL, USER, PASSWORD)) {

            int choice;
            do {
                System.out.println("\n1. Insert  2. Read  3. Update  4. Delete  5. Exit");
                System.out.print("Enter your choice: ");
                choice = scanner.nextInt();
                scanner.nextLine();

                switch (choice) {
                    case 1:
                        insertRecord(connection, scanner);
                        break;
                    case 2:
                        readRecords(connection);
                        break;
                    case 3:
                        updateRecord(connection, scanner);
                        break;
                    case 4:
                        deleteRecord(connection, scanner);
                        break;
                    case 5:
                        System.out.println("Exiting program.");
                        break;
                    default:
                        System.out.println("Invalid choice.");
                }
            } while (choice != 5);
        } catch (SQLException exception) {
            System.out.println("Database error: " + exception.getMessage());
        }
    }

    private static void insertRecord(Connection connection, Scanner scanner) throws SQLException {
        System.out.print("Enter student id: ");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter student name: ");
        String name = scanner.nextLine();

        String query = "INSERT INTO student (id, name) VALUES (?, ?)";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, id);
            statement.setString(2, name);
            statement.executeUpdate();
            System.out.println("Record inserted successfully.");
        }
    }

    private static void readRecords(Connection connection) throws SQLException {
        String query = "SELECT id, name FROM student";
        try (Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(query)) {

            System.out.println("Student Records:");
            while (resultSet.next()) {
                System.out.println(resultSet.getInt("id") + " - " + resultSet.getString("name"));
            }
        }
    }

    private static void updateRecord(Connection connection, Scanner scanner) throws SQLException {
        System.out.print("Enter student id to update: ");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter new student name: ");
        String name = scanner.nextLine();

        String query = "UPDATE student SET name = ? WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, name);
            statement.setInt(2, id);
            int rowsUpdated = statement.executeUpdate();
            System.out.println(rowsUpdated > 0 ? "Record updated successfully." : "Record not found.");
        }
    }

    private static void deleteRecord(Connection connection, Scanner scanner) throws SQLException {
        System.out.print("Enter student id to delete: ");
        int id = scanner.nextInt();

        String query = "DELETE FROM student WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, id);
            int rowsDeleted = statement.executeUpdate();
            System.out.println(rowsDeleted > 0 ? "Record deleted successfully." : "Record not found.");
        }
    }
}
