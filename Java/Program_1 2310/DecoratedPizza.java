public abstract class DecoratedPizza 
{
	private DecoratedPizza next_pizza_item;

	public DecoratedPizza()
	{
		next_pizza_item = null;
	}
	
	public DecoratedPizza(DecoratedPizza temp)
	{
		next_pizza_item = temp;
	}
	
	public double pizzaCost()
	{
		return next_pizza_item.pizzaCost();
	}
	
	public String toString()
	{
		return next_pizza_item.toString();
	}
	
	public String getImage()
	{
		return next_pizza_item.getImage();
	}
}