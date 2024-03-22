public class EnoughBalance implements State {
	
	VMachine obj;
	
	public EnoughBalance(VMachine obj)
	{
		this.obj=obj;
	}
	
	public void insertDollar()
	{
		System.out.println("Error: Balance full, please select an Item.");
	}
	
	public void ejectDollar()
	{
		System.out.println("Ejecting: Balance: $1.00");
		obj.setState(obj.getLessBalance());
	}
	
	public void inputItem()
	{
		System.out.println("Item selected! Now dispensing...");
		obj.setState(obj.getDispenseItem());
	}
	
	public void dispense()
	{
		System.out.println("Please select an item first!");
	}
	
	public void cancel()
	{
		System.out.println("Cancelling Transaction...");
		obj.setState(obj.getTransactionCancel());
	}
	
	public void refill() {}
	
	public String toString()
	{
		return "Balance: $1.00, waiting for input.";
	}
}