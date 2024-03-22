public class Pepperoni extends DecoratedPizza
{
	public Pepperoni(DecoratedPizza Pizza)
	{
		super(Pizza);
	}
	
	public String toString()
	{
		return super.toString() + ", Pepperoni";
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + 0.99;
	}
	
	public String getImage()
	{
		return super.getImage() + "P";
	}
}