public class PizzaToppingFactory
{
	public static DecoratedPizza addPepperoni(DecoratedPizza dec_pizza)
	{
		PizzaTopping pep = new PizzaTopping(dec_pizza, "Pepperoni", "P", 0.99);
		return pep;
	}
	
	public static DecoratedPizza addSausage(DecoratedPizza dec_pizza)
	{
		PizzaTopping sau = new PizzaTopping(dec_pizza, "Pepperoni", "S", 0.99);
		return sau;
	}
	
	public static DecoratedPizza addOnions(DecoratedPizza dec_pizza)
	{
		PizzaTopping oni = new PizzaTopping(dec_pizza, "Onions", "O", 0.79);
		return oni;
	}
	
	public static DecoratedPizza addGreenPeppers(DecoratedPizza dec_pizza)
	{
		PizzaTopping grep = new PizzaTopping(dec_pizza, "Green Peppers", "G", 0.69);
		return grep;
	}
	
	public static DecoratedPizza addMushrooms(DecoratedPizza dec_pizza)
	{
		PizzaTopping mush = new PizzaTopping(dec_pizza, "Mushrooms", "M", 0.79);
		return mush;
	}
	
	public static DecoratedPizza addHam(DecoratedPizza dec_pizza)
	{
		PizzaTopping ham = new PizzaTopping(dec_pizza, "Ham", "H", 0.89);
		return ham;
	}
	
	public static DecoratedPizza addPineapple(DecoratedPizza dec_pizza)
	{
		PizzaTopping pine = new PizzaTopping(dec_pizza, "Pineapple", "A", 0.89);
		return pine;
	}
}