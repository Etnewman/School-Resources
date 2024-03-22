public class Onions extends DecoratedPizza
{
	public Onions(DecoratedPizza Pizza)
	{
		super(Pizza);
	}
	
	public String toString()
	{
		return super.toString() + ", Onions";
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + 0.79;
	}
	
	public String getImage()
	{
		return super.getImage() + "O";
	}
}