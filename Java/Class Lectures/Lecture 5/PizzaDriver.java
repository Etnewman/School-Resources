// PizzaDriver.java
public class PizzaDriver
{
	public static void main(String[] args)
	{
		Pizza p1 = new Pizza("large", 1, 1, 2);
		Pizza p2 = new Pizza("small", 2, 1, 1);
		Pizza p3 = new Pizza("medium", 1, 2, 1);
		
		System.out.println(p1.getDescription());
		System.out.println(p2.getDescription());
		System.out.println(p3.getDescription());
	}
}