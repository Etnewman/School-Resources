public class PizzaTopping extends DecoratedPizza
{
	private String topString;
	private String topLetter;
	private double topCost;
	
	public PizzaTopping(DecoratedPizza pizzaComp, String topString, String topLetter, double topCost)
	{
		super(pizzaComp);
		this.topString = topString;
		this.topLetter = topLetter;
		this.topCost = topCost;
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + topCost;
	}
	
	public String toString()
	{
		return super.toString() + topString + "\r\n";
	}
	
	public String getImage()
	{
		return super.getImage() + topLetter;
	}
}
		