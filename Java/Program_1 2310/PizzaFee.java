public class PizzaFee extends DecoratedPizza
{
	private String msg;
	private double fee;
	
	public PizzaFee(DecoratedPizza pizzaComp, String msg, double fee)
	{
		super(pizzaComp);
		this.msg = msg;
		this.fee = fee;
	}
	
	public double pizzaCost()
	{
		return super.pizzaCost() + fee;
	}
	
	public String toString()
	{
		return super.toString() + msg;
	}
}