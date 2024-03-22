public class Ready implements State {
	
	VMachine obj;
	
	public Ready(VMachine obj)
	{
		this.obj=obj;
	}
	
	public void insertDollar()
	{
		System.out.println("You insert a Dollar, Balance: $1.00");
		obj.setState(obj.getEnoughBalance());
	}
	
	public void ejectDollar()
	{
		System.out.println("Error: Balance: $0.00");
	}
	
	public void inputItem()
	{
		System.out.println("Balance: $0.00, an item costs: $1.00");
	}
	
	public void dispense()
	{
		System.out.println("Error: Balance: $0.00");
	}
	
	public void cancel()
	{
		System.out.println("Error: There is no transaction to cancel!");
	}
	
	public void refill() {}
	
	public String toString()
	{
		return "Vending Machine is ready. Balance: $0.00, please insert a dollar.";
	}
}

