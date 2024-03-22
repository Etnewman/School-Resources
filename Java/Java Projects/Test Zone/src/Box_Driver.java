import java.util.Scanner;

class Box {
	private double length;
	private double width;
	private double height;
	
	Box(double boxLength, double boxWidth, double boxHeight)
	{
		length = boxLength;
		width = boxWidth;
		height = boxHeight;
	}
		
	public double volume()
	{
		double volume = length * width * height;
		return volume;
	}
	
	public double area()
	{
		double area = (2* length * width) + (2 * width * height) + (2 * length * height);
	    return area;
	}
	
}

public class Box_Driver {

	public static void main(String[] args) {
		
		
		Scanner scan = new Scanner(System.in);
		double l, w, h;
		
		System.out.println("What is the length of your Box?");
		l = scan.nextDouble();
				
		System.out.println("What is the width of your box?");
		w = scan.nextDouble();
		
		System.out.println("What is the height of your box?");
		h = scan.nextDouble();
		
		Box new_Box = new Box(l, w, h);
		
		double vol = new_Box.volume();
		double area = new_Box.area();
		
		System.out.println("The volume of the box is: " + vol + ", and the Area is: " + area);
		

	}

}
