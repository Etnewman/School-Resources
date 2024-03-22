public class Pineapple extends DecoratedPizza
{
	public Pineapple(DecoratedPizza Pizza)
	{
		super(Pizza);
	}
	
	public String toString()
	{
		return super.toString() + ", Pineapple";
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + 0.89;
	}
	
	public String getImage()
	{
		return super.getImage() + "A";
	}
}

