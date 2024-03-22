public class VeggieLovers extends PizzaBuilder
{
	public VeggieLovers()
	{
		super();
	}
	
	protected void buildPizza()
	{
		super.buildPizza();
		super.addTopping('O');
		super.addTopping('G');
		super.addTopping('M');
	}
}