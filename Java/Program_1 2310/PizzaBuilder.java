import java.lang.*;
public class PizzaBuilder
{
	private Crust crust;
	private DecoratedPizza pizzaItem;
	private char size;
	private String type;
		
	protected void buildPizza()
	{
		crust = new Crust(size, type);
		pizzaItem = new Pizza(crust);
	}
		
	public PizzaBuilder()
	{
		size = 'S';
		type = "THIN";
		crust = new Crust(size, type);
		pizzaItem = new Pizza(crust);
	}
		
	public boolean setSize(char tSize)
	{
		if (tSize == 'S' || tSize == 's')
		{
			size = 'S';
			buildPizza();
			return true;
		}
		else if (tSize == 'M' || tSize == 'm')
		{
			size = 'M';
			buildPizza();
			return true;
		}
		else if (tSize == 'L' || tSize == 'l')
		{
			size = 'L';
			buildPizza();
			return true;
		}
		else 
			return false;
	}
		
	public boolean setCrust(String tType)
	{
		if (tType.equalsIgnoreCase("THIN"))
		{
			type = "THIN";
			buildPizza();
			return true;
		}
		else if (tType.equalsIgnoreCase("PAN"))
		{
			type = "PAN";
			buildPizza();
			return true;
		}
		else if (tType.equalsIgnoreCase("HAND"))
		{
			type = "HAND";
			buildPizza();
			return true;
		}
		else 
			return false;
	}
		
	public void addTopping(char topChar)
	{
		if (topChar == 'P' || topChar == 'p')
		{
			//pizzaItem = new Pepperoni(pizzaItem);
			pizzaItem = PizzaToppingFactory.addPepperoni(pizzaItem);
		}
			
		else if (topChar == 'S' || topChar == 's')
		{
			//pizzaItem = new Sausage(pizzaItem);
			pizzaItem = PizzaToppingFactory.addSausage(pizzaItem);
		}
		else if (topChar == 'O' || topChar == 'o')
		{
			//pizzaItem = new Onions(pizzaItem);
			pizzaItem = PizzaToppingFactory.addOnions(pizzaItem);
		}
		else if (topChar == 'G' || topChar == 'g')
		{
			//pizzaItem = new GreenPeppers(pizzaItem);
			pizzaItem = PizzaToppingFactory.addGreenPeppers(pizzaItem);
		}
		else if (topChar == 'M' || topChar == 'm')
		{
			//pizzaItem = new Mushrooms(pizzaItem);
			pizzaItem = PizzaToppingFactory.addMushrooms(pizzaItem);
		}
		else if (topChar == 'H' || topChar == 'h')
		{
			//pizzaItem = new Ham(pizzaItem);
			pizzaItem = PizzaToppingFactory.addHam(pizzaItem);
		}
		else if (topChar == 'A' || topChar == 'a')
		{
			//pizzaItem = new Pineapple(pizzaItem);
			pizzaItem = PizzaToppingFactory.addPineapple(pizzaItem);
		}
		else 
			return;
	}
	
	public DecoratedPizza pizzaDone()
	{
		DecoratedPizza temp = pizzaItem;
		size = 'S';
		type = "THIN";
		buildPizza();
		return temp;
	}
	
	public void addDiscount(String msg, double discount)
	{
		pizzaItem = new PizzaDiscount(pizzaItem, msg, discount);
	}
	
	public void addFee(String msg, double fee)
	{
		pizzaItem = new PizzaFee(pizzaItem, msg, fee);
	}	
}