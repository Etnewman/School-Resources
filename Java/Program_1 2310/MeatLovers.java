public class MeatLovers extends PizzaBuilder
{
	public MeatLovers()
	{
		super();
	}
	
	protected void buildPizza()
	{
		super.buildPizza();
		super.addTopping('P');
		super.addTopping('S');
		super.addTopping('H');
	}
}