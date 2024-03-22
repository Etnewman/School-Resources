public class Sausage extends DecoratedPizza
{
	public Sausage(DecoratedPizza Pizza)
	{
		super(Pizza);
	}
	
	public String toString()
	{
		return super.toString() + ", Sausage";
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + 0.99;
	}
	
	public String getImage()
	{
		return super.getImage() + "S";
	}
}