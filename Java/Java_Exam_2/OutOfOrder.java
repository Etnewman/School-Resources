public class OutOfOrder implements State {

	VMachine obj;
	
	public OutOfOrder(VMachine obj)
	{
		this.obj=obj;
	}
	
	public void insertDollar()
	{
		System.out.println("Error: Out of Order => Refill required.");
	}
	
	public void ejectDollar()
	{
		System.out.println("Error: Out of Order => Refill required.");
	}
	
	public void inputItem()
	{
		System.out.println("Error: Out of Order => Refill required.");
	}
	
	public void dispense()
	{
		System.out.println("Error: Out of Order => Refill required.");
	}
	
	public void cancel()
	{
		System.out.println("Error: Out of Order => Refill required.");
	}
	
	public void refill()
	{
		obj.setState(obj.getReady());
	}
	
	public String toString()
	{
		return "Vending Machine is Out of Order => Refill required.";
	}
}

