public class GreenPeppers extends DecoratedPizza
{
	public GreenPeppers(DecoratedPizza Pizza)
	{
		super(Pizza);
	}
	
	public String toString()
	{
		return super.toString() + ", Green Peppers";
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + 0.69;
	}
	
	public String getImage()
	{
		return super.getImage() + "G";
	}
}