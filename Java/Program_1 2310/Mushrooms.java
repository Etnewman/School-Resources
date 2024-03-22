public class Mushrooms extends DecoratedPizza
{
	public Mushrooms(DecoratedPizza Pizza)
	{
		super(Pizza);
	}
	
	public String toString()
	{
		return super.toString() + ", Mushrooms";
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + 0.79;
	}
	
	public String getImage()
	{
		return super.getImage() + "M";
	}
}