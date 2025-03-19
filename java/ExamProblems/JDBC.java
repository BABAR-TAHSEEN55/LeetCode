import java.sql.Connection;
import java.sql.DriverManager;
 import java.sql.SQLException;
  import java.sql.Statement;
//Insert
  pubblic class DemoInsert{
    static String final  DB_URL= "asdf"; 
    static String final  USEr= "asdf"; 
    static String final  Pass= "asdf"; 
    public static void main(String args[]){
try (Connection conn =  DriverManager.getConnection(DB_URL,USEr , Pass);
    Statement stmt = createStatemen();) {
  String sql = "INSERT REGISTER TO VALUES(100,"ALI",400,"Sally")"
    stmt.executeUpdate(sql);
    System.out.println("Inserting values ...");
} catch (SQLException e) {
e.printStackTrace();
}
    }
  }
//Update 
public class Demo{
  static final String DB_URL= " ahsldjfh"
    static final String User = "FF";
  static final String Pass = "SAD F";
  public static void main(String args[]){
    try(Connection conn = DriverManager.getConnection();
Statement stmt= conn.createStatement();
ResultSet rs = stmt.executeQuery(SQL)){
      System.out.println("Connected to Database");
      while (rs.next()) { //AWARE
        System.out.println("ID : " + rs.getINt());
      }
}

  }
}
// Select 
public class UpdateApplication{
  public static void main(String args[]){
    String sql = "UPDATE  REGISTRATION " + "SET AGE = 30 WHERE ID IN (100,101)"
      stmt.executeUpdate(sql);
  }
}

