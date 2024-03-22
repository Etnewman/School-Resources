import java.sql.*;
import java.lang.*;
public class problem2
{
    public static void main(String args[])
    {
        try
        {
            Statement stmt;
            ResultSet rs1;
            ResultSet rs2;
            ResultSet rs3;
            ResultSet rs4;
            ResultSet trueSet;

            //System.out.println("Pre Class.forName");

            try
            {
            Class.forName("org.mariadb.jdbc.Driver");
            } catch(ClassNotFoundException ex)
            {
                System.out.println(ex.toString());
            }

            String url = "jdbc:mysql://localhost:3306/TTU";

            //System.out.println("Pre Connection");

            Connection con = DriverManager.getConnection(url, "root", "coursework");

            //System.out.println("Post Connection");

            stmt = con.createStatement();

                //*****Creating Query Statements***** */

            String query1 = "INSERT INTO TABLE student(tnumber, firstname, lastname, dateofbirth, credits) VALUES('00003256','John','Doe','1970-07-15',119);";
            String query2 = "INSERT INTO TABLE student(tnumber, firstname, lastname, dateofbirth, credits) VALUES('00001423','Mary','Smith','1992-01-01',15);";
            String query3 = "INSERT INTO TABLE student(tnumber, firstname, lastname, dateofbirth, credits) VALUES('00015366','William','Williamson','1991-05-23',60);";
            String query4 = "INSERT INTO TABLE student(tnumber, firstname, lastname, dateofbirth, credits) VALUES('00012345','Katie','Did','1992-09-27',45);";
            String testQuery = "Select * from student;";

            //System.out.println("Post Query Creation");

            rs1 = stmt.executeQuery(query1);
            rs2 = stmt.executeQuery(query2);
            rs3 = stmt.executeQuery(query3);
            rs4 = stmt.executeQuery(query4);

            PreparedStatement pst = con.prepareStatement(testQuery);
            trueSet = pst.executeQuery();
            int i = 0;

                //*****QUERIES CREATED***** */
            //System.out.println("Post Query Execution");

            while(trueSet.next())
            {
                System.out.println(trueSet.getString(i));
                System.out.println("     ");
                i = i + 1;
            }
            con.close();
        } catch (Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }
}