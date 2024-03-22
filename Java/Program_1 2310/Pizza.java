public class Pizza extends DecoratedPizza
{
	private Crust crust;
	
	public Pizza(Crust crust)
	{
		super();
		this.crust = crust;
	}
	
	public String toString()
	{
		return crust.toString();
	}
	
	public double pizzaCost()
	{
		return crust.getCost();
	}
	
	public String getImage()
	{
		String image = new String();
		return (image + crust.getSize());
	}
}