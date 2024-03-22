
public class IceCreamCone {

	private Cone c;
	private IceCream i;
	
	public IceCreamCone(Cone c, IceCream i)
	{
		this.c = c;
		this.i = i;
	}
	
	public double orderPrice()
	{
		double base = 1.99;
		return (base + c.getConePrice() + i.scoopPrice() + i.getToppingPrice());
	}
	public Cone getCone()
	{
		return c;
	}
}
