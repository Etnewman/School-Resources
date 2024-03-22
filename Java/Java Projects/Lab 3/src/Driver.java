// Ethan Newman and Jonathan Spradlin



public class Driver {

	public static void main(String[] args) {

		boolean another = true;
		String temp = "";
		String yes = "y";
		int count = 0;
		double total = 0.00;
		System.out.println("Would you like to order an Ice Cream Cone? (y/n)?");
	    String check =	Keyboard.getKeyboard().readString(temp);
		
		if (check.equals(yes))
			another = true;
		else
			another = false;
		
		
		while (another == true)
		{
			
			System.out.println(Flavors.getFlavors().listFlavors());
			System.out.println("Enter your desired flavor: ");
			int flav = Keyboard.getKeyboard().readInt(temp);
			
			System.out.println(Toppings.getToppings().listToppings());
			System.out.println("Enter your desired topping: ");
			int  top = Keyboard.getKeyboard().readInt(temp);
			
			int scoops = getScoopsChoice();
			
			System.out.println("What type of cone do you desire? (1 for Sugar Cone, 2 for Waffle Cone, 3 for Cup");
			int coneType = Keyboard.getKeyboard().readInt(temp);
			
			IceCream iceCream = new IceCream(scoops, getFlavorChoice(flav), getToppingChoice(top));
			IceCreamCone iceCone = new IceCreamCone(getConeChoice(coneType), iceCream);
			
			String f = getFlavorChoice(flav).toString();
			String t = getToppingChoice(top).toString();
			
			
			System.out.println("Your Order: ");
			System.out.println("Cone: " + iceCone.getCone().coneToStr());
			System.out.println("Flavor: " + f);
			System.out.println("Topping: " + t);
			System.out.println("Number of Scoops: " + scoops);
			System.out.println("Price: " + Currency.formatCurrency(iceCone.orderPrice()));
			
			total = total + iceCone.orderPrice();
			count = count + 1;
			
			System.out.println("Would you like to order an Ice Cream Cone? (y/n)?");
		    check =	Keyboard.getKeyboard().readString(temp);
			
			if (check.equals(yes))
				another = true;
			else
				another = false;
			
		}
		
		System.out.println("Your total order for " + count + " orders of ice cream is: " + Currency.formatCurrency(total));
		System.out.println("Goodbye!");
		
		
	}
	
	public static Flavor getFlavorChoice(int i)
	{
		Flavor flavor;
		flavor = Flavors.getFlavors().getFlavor(i);
		return flavor;
		

	}

	public static Topping getToppingChoice(int i)
	{
		Topping topping;
		topping = Toppings.getToppings().getTopping(i);
		return topping;
	}
	
	public static int getScoopsChoice()
	{
		String temp = "";
		System.out.println("How many scoops do you desire? (1, 2, or 3): ");
		int i = Keyboard.getKeyboard().readInt(temp);
		while (i > 3 || i < 0)
		{
			System.out.println("Usage: Number of scoops between 1 and 3.");
			i = Keyboard.getKeyboard().readInt(temp);
		}
		return i;

	}
	
	public static Cone getConeChoice(int i)
	{
		Cone cone = new Cone(i);
		return cone;
	}
}

