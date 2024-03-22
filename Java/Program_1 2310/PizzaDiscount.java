public class PizzaDiscount extends DecoratedPizza
{
	private String msg;
	private double discount;
	
	public PizzaDiscount(DecoratedPizza pizzaComp, String msg, double discount)
	{
		super(pizzaComp);
		this.msg = msg;
		this.discount = discount;
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() * (1 - discount);
	}
	
	public String toString()
	{
		return super.toString() + msg;
	}
}
	