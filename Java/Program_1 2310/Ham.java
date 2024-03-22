public class Ham extends DecoratedPizza
{
	public Ham(DecoratedPizza Pizza)
	{
		super(Pizza);
	}
	
	public String toString()
	{
		return super.toString() + ", Ham";
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + 0.89;
	}
	
	public String getImage()
	{
		return super.getImage() + "H";
	}
}