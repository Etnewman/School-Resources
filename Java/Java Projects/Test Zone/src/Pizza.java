// Pizza.java
public class Pizza
{
	private String pizzaSize;
	private int cheeseCount;
	private int pepperoniCount;
	private int hamCount;

	public Pizza()
	{
		this.pizzaSize = "";
		this.cheeseCount = 0;
		this.pepperoniCount = 0;
		this.hamCount = 0;
	}
	
	public Pizza(String pizzaSize, int cheeseCount, 
					int pepperoniCount, int hamCount)
	{
		this.pizzaSize = pizzaSize;
		this.cheeseCount = cheeseCount;
		this.pepperoniCount = pepperoniCount;
		this.hamCount = hamCount;
	}
	
	public String getPizzaSize()
	{
		return pizzaSize;
	}

	public void setPizzaSize(String pizzaSize)
	{
		this.pizzaSize = pizzaSize;
	}

	public int getNumCheeseToppings()
	{
		return cheeseCount;
	}

	public void setNumCheeseToppings(int cheeseCount)
	{
		this.cheeseCount = cheeseCount;
	}

	public int getNumPepperoniToppings()
	{
		return pepperoniCount;
	}

	public void setNumPepperoniToppings(int pepperoniCount)
	{
		this.pepperoniCount = pepperoniCount;
	}

	public int getNumHmaToppings()
	{
		return hamCount;
	}

	public void setNumHmaToppings(int hamCount)
	{
		this.hamCount = hamCount;
	}

	public double calcCost()
	{		
		if(pizzaSize.equalsIgnoreCase("small"))
		{
			return 10 + (cheeseCount + pepperoniCount + hamCount) * 2;
		}
		else if(pizzaSize.equalsIgnoreCase("medium"))
		{
			return 12 + (cheeseCount + pepperoniCount + hamCount) * 2;
		}
		else if(pizzaSize.equalsIgnoreCase("large"))
		{
			return 14 + (cheeseCount + pepperoniCount + hamCount) * 2;
		}
		else
		{
			return 0.0;
		}
	}

	public String getDescription()
	{
		return "Pizza size: " + pizzaSize + "\n Cheese toppings: " 
				+ cheeseCount + "\n Pepperoni toppings: "
				+ pepperoniCount + "\n Ham toppings: " + hamCount
				+ "\n Pizza cost: $" + calcCost() + "\n";
	}
}