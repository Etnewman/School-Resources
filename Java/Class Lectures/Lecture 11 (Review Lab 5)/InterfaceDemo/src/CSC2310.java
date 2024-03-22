
public class CSC2310 extends Course implements Prerequisite{

private String credithours;

		 public boolean fulfills_CourseRequirements()
		 {
			return true; 
		 }
 
		 public boolean fulfills_GradeRequirements()
		 {
			return false; 
		 }
 
	
}
