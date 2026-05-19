import java.sql.*;
import java.util.Scanner;


public class JdbcCrudApp {

    static final String URL = "jdbc:oracle:thin:@localhost:1521/XEPDB1";
    static final String USER = "system";
    static final String PASS = "system";

    public static void main(String[] args) {
        try {
            // Load driver

            Class.forName("oracle.jdbc.driver.OracleDriver");

            // Connect
            Connection con = DriverManager.getConnection(URL, USER, PASS);
            Scanner sc = new Scanner(System.in);

            while (true) {
                System.out.println("\n1.Insert  2.Read  3.Update  4.Delete  5.Exit");
                int choice = sc.nextInt();

                switch (choice) {
                    case 1: // INSERT
                        System.out.print("Enter ID: ");
                        int id = sc.nextInt();
                        sc.nextLine();
                        System.out.print("Enter Name: ");
                        String name = sc.nextLine();

                        PreparedStatement ps1 = con.prepareStatement(
                                "INSERT INTO student VALUES (?, ?)");
                        ps1.setInt(1, id);
                        ps1.setString(2, name);

                        ps1.executeUpdate();
                        System.out.println("Inserted Successfully");
                        break;

                    case 2: // READ
                        Statement st = con.createStatement();
                        ResultSet rs = st.executeQuery("SELECT * FROM student");

                        while (rs.next()) {
                            System.out.println(rs.getInt(1) + " " + rs.getString(2));
                        }
                        break;

                    case 3: // UPDATE
                        System.out.print("Enter ID to update: ");
                        int uid = sc.nextInt();
                        sc.nextLine();
                        System.out.print("Enter new Name: ");
                        String newName = sc.nextLine();

                        PreparedStatement ps2 = con.prepareStatement(
                                "UPDATE student SET name=? WHERE id=?");
                        ps2.setString(1, newName);
                        ps2.setInt(2, uid);

                        ps2.executeUpdate();
                        System.out.println("Updated Successfully");
                        break;

                    case 4: // DELETE
                        System.out.print("Enter ID to delete: ");
                        int did = sc.nextInt();

                        PreparedStatement ps3 = con.prepareStatement(
                                "DELETE FROM student WHERE id=?");
                        ps3.setInt(1, did);

                        ps3.executeUpdate();
                        System.out.println("Deleted Successfully");
                        break;

                    case 5:
                        con.close();
                        System.exit(0);
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
