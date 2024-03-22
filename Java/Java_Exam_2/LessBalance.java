public class LessBalance implements State {

	VMachine obj;
	
	public LessBalance(VMachine obj)
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
		System.out.println("Cancelling Transaction...");
		obj.setState(obj.getTransactionCancel());
	}
	
	public void refill() {}
	
	public String toString()
	{
		return "Balance: $0.00, please insert dollar.";
	}
}