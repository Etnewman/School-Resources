import java.util.*;
import java.io.*;
public class PizzaDriver
{
	private static int menu()
	{
		int temp;
		System.out.println("1. Meat Lover's");
		System.out.println("2. Veggie Lover's");
		System.out.println("3. Hawaiian ");
		System.out.println("4. Build Your Own");
		temp = Keyboard.getKeyboard().readInt("Select from the above: ");
			
		while ((temp != 1 && temp != 2 && temp != 3 && temp != 4))
		{			
			temp = Keyboard.getKeyboard().readInt("Incorrect input, try again. (1-4)");
		}
		
		return temp;
	}
	
	private static void requestSize(PizzaBuilder pizza_builder)
	{
		char temp;
		String sTemp;
		
		do
		{
			sTemp = Keyboard.getKeyboard().readString("What size pizza (S/M/L)? ");
			sTemp.toUpperCase();
			temp = sTemp.charAt(0);
		}while(pizza_builder.setSize(temp) == false);
		
	}

	private static void requestCrust(PizzaBuilder pizza_builder)
	{
		String temp;
		
		do
		{
			temp = Keyboard.getKeyboard().readString("What type of crust (thin/hand/pan)? ");
			temp.toUpperCase();
		}while(pizza_builder.setCrust(temp) == false);
		
	}
	
	private static void requestToppings(PizzaBuilder pizza_builder)
	{
		String sTemp;
		char cTemp;
		
		do
		{
			sTemp = Keyboard.getKeyboard().readString("(P)epperoni,(O)nions,(G)reen Peppers,(S)ausage,(M)ushrooms,(D)one \r\n");
			sTemp = sTemp.toUpperCase();
			cTemp = sTemp.charAt(0);
			pizza_builder.addTopping(cTemp);
		}while(!sTemp.contentEquals("D"));
	}
	
	private static void showOrder(DecoratedPizza pizza)
	{
		double cost = pizza.pizzaCost();
		String strDouble = String.format("%.2f", cost);
		System.out.println("Your Order:\n");
		System.out.println(pizza.toString());
		System.out.println("The cost of your pizza is : " + strDouble);
	}
		
	
	public static void main (String[] args)
	{
		String sTemp;
		char cTemp;
		double totalCost = 0.00;
		int switchCase = 0;
		PizzaBuilder pizza = new PizzaBuilder();
		int count = 0;
		

		do
		{
			sTemp = Keyboard.getKeyboard().readString("Would you like to order a pizza (y/n)? ");
			sTemp.toUpperCase();
			cTemp = sTemp.charAt(0);
			
			if (cTemp == 'N' || cTemp == 'n')
			{
				break;
			}
			
		while (cTemp != 'Y' && cTemp != 'y' && cTemp != 'N' && cTemp != 'n')
		{
			sTemp = Keyboard.getKeyboard().readString("Would you like to order a pizza (y/n)? ");
			sTemp.toUpperCase();
			cTemp = sTemp.charAt(0);
		}
			
			switchCase = menu();
			
			switch(switchCase)
			{
				case 1:
				pizza = new MeatLovers();
				requestSize(pizza);
				requestCrust(pizza);
				break;
				
				case 2:
				pizza = new VeggieLovers();
				requestSize(pizza);
				requestCrust(pizza);
				break;
				
				case 3:
				pizza = new Hawaiian();
				requestSize(pizza);
				requestCrust(pizza);
				break;
				
				case 4:
				requestSize(pizza);
				requestCrust(pizza);
				requestToppings(pizza);
				break;
			}
			
			do{
				sTemp = Keyboard.getKeyboard().readString("Are you a Senior Citizen? (y/n) "); 
				sTemp = sTemp.toUpperCase();
				cTemp = sTemp.charAt(0);
				
				if (cTemp == 'Y' || cTemp == 'y')
				{
					pizza.addDiscount("Senior Citizen Discount\r\n", 0.1);
					break;
				}
				else if (cTemp == 'N' || cTemp == 'n')
					break;
				
			}while(!sTemp.contentEquals("Y") || !sTemp.contentEquals("N"));
				
			do{
				sTemp = Keyboard.getKeyboard().readString("Is this pizza delivered? (y/n) ");
				sTemp = sTemp.toUpperCase();
				cTemp = sTemp.charAt(0);
				
				if (cTemp == 'Y' || cTemp == 'y')
				{
					pizza.addFee("Delivery Fee\r\n", 2.50);
					break;
				}
				else if (cTemp == 'N' || cTemp == 'n')
					break;
				
			}while(!sTemp.contentEquals("Y") || !sTemp.contentEquals("N"));
				
			
			
			DecoratedPizza dec_pizza = pizza.pizzaDone();
			showOrder(dec_pizza);
			
			count++;
			
			totalCost = totalCost + dec_pizza.pizzaCost();
			
		}while(cTemp == 'Y' || cTemp == 'y');
		
		String strDouble = String.format("%.2f", totalCost);
		System.out.println("You ordered " + count + " pizza(s) for a grand total of " + strDouble);
	}
}
		
		
	
		
