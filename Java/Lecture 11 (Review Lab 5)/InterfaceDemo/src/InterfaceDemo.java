
public class InterfaceDemo {

	public static void main (String args[])
	{
		CSC2310 course1 = new CSC2310(); 
		course1.setID("2310");
		if (course1.fulfills_CourseRequirements())
			System.out.println("Credit requirement is fulfilled");
		else
			System.out.println("Credit requirement is NOT fulfilled");
		
		
		if (course1.fulfills_GradeRequirements())
			System.out.println("Grade requirement is fulfilled");
		else
			System.out.println("Grade requirement is NOT fulfilled");
		
	}
}
