
public class Passage {

	private int num;
	private double doubleNum;
	private String myString;
	private boolean truthValue;
	
	
	Passage(int num, double doubleNum, String myString, boolean truthValue)
	{
		this.num = num;
		this.doubleNum = doubleNum;
		this.myString = myString;
		this.truthValue = truthValue;
	}
	
	void PrintData()
	{
		System.out.println("The Number is: " + num);
		System.out.println("The Double is: " + doubleNum);
		System.out.println("My String is: " + myString);
		
		if (truthValue == true)
			System.out.println("The Boolean is True");
		else
			System.out.println("The Boolean is False");
	}
	
	
}
