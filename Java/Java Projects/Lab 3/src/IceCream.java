
public class IceCream {

	private int numScoops;
	private Flavor flavor;
	private Topping topping;
	
	
	public IceCream (int numScoops, Flavor flavor, Topping topping)
	{
	this.numScoops = numScoops;
	this.flavor = flavor;
	this.topping = topping;
	}
	
	public double scoopPrice()
	{
		if (numScoops == 1)
			return 0.00;
		else 
			return (numScoops - 1) * 0.75;
	}
	
	public double getToppingPrice()
	{
		return topping.price();
	}
	
}
